#ifndef MUSGRAVITE_HPP
#define MUSGRAVITE_HPP



#include <iostream>
#include <vector>
#include <functional>
#include <stdexcept>
#include <sstream>
#include <chrono>
#include <cmath>
#include <map>
#include <future>
#include <thread>
#include <iomanip>



#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"



extern bool useColor;



void disableColors();
void printColored(const std::string& message, const std::string& color = "");



class Musgravite {
    public:
        Musgravite(
            const std::string& name,
            std::function<void()> func,
            std::function<void()> setup = nullptr,
            std::function<void()> teardown = nullptr,
            std::chrono::seconds timeout = std::chrono::seconds(30)
        );

        void run() const;
        std::string getName() const;


    private:
        std::string name;
        std::function<void()> func;
        std::function<void()> setup;
        std::function<void()> teardown;
        std::chrono::seconds timeout;

        bool isAsyncTest(const std::function<void()>& f) const;
};



class MusgraviteRunner {
    public:
        void addTest(
            const std::string& suiteName,
            const std::string& testName,
            std::function<void()> func,
            std::function<void()> setup = nullptr,
            std::function<void()> teardown = nullptr,
            std::chrono::seconds timeout = std::chrono::seconds(30)
        );

        void runAllTests();


    private:
        std::map<std::string, std::vector<Musgravite>> suites;
};



#define TEST(name) void name()



#define ADD_TEST(runner, suite, test) runner.addTest(suite, #test, test)
#define ADD_TEST_TIMEOUT(runner, suite, test, timeout) runner.addTest(suite, #test, test, nullptr, nullptr, timeout)
#define ADD_TEST_SETUP(runner, suite, test, setup) runner.addTest(suite, #test, test, setup, nullptr)
#define ADD_TEST_SETUP_TEARDOWN(runner, suite, test, setup, teardown) runner.addTest(suite, #test, test, setup, teardown)
#define ADD_TEST_SETUP_TIMEOUT(runner, suite, test, setup, timeout) runner.addTest(suite, #test, test, setup, nullptr, timeout)
#define ADD_TEST_TEARDOWN(runner, suite, test, teardown) runner.addTest(suite, #test, test, nullptr, teardown)
#define ADD_TEST_TEARDOWN_TIMEOUT(runner, suite, test, teardown, timeout) runner.addTest(suite, #test, test, nullptr, teardown, timeout)
#define ADD_TEST_SETUP_TEARDOWN_TIMEOUT(runner, suite, test, setup, teardown, timeout) runner.addTest(suite, #test, test, setup, teardown, timeout)



#define IGNORE_TEST(test) \
    printColored("Test " #test " ignored.", YELLOW);

#define ASSERT_TRUE(cond) \
    if (!(cond)) { \
        std::stringstream ss; \
        ss << "Assertion failed: " << #cond << ", file " << __FILE__ << ", line " << __LINE__; \
        throw std::runtime_error(ss.str()); \
    }

#define ASSERT_FALSE(cond) \
    if (cond) { \
        std::stringstream ss; \
        ss << "Assertion failed: " << #cond << " is true, file " << __FILE__ << ", line " << __LINE__; \
        throw std::runtime_error(ss.str()); \
    }

#define ASSERT_EQUAL(expected, actual) \
    if ((expected) != (actual)) { \
        std::stringstream ss; \
        ss << "Assertion failed: expected " << (expected) << ", got " << (actual) << ", file " << __FILE__ << ", line " << __LINE__; \
        throw std::runtime_error(ss.str()); \
    }

#define ASSERT_NOT_EQUAL(expected, actual) \
    if ((expected) == (actual)) { \
        std::stringstream ss; \
        ss << "Assertion failed: expected not " << (expected) << ", but got " << (actual) << ", file " << __FILE__ << ", line " << __LINE__; \
        throw std::runtime_error(ss.str()); \
    }

#define ASSERT_NEAR(expected, actual, tol) \
    if (std::fabs((expected) - (actual)) > (tol)) { \
        std::stringstream ss; \
        ss << "Assertion failed: expected near " << (expected) << ", got " << (actual) << ", with tolerance " << (tol) << ", file " << __FILE__ << ", line " << __LINE__; \
        throw std::runtime_error(ss.str()); \
    }

#define ASSERT_THROW(statement, exception_type) \
    try { \
        statement; \
        std::stringstream ss; \
        ss << "Assertion failed: expected exception " << #exception_type << ", but no exception thrown, file " << __FILE__ << ", line " << __LINE__; \
        throw std::runtime_error(ss.str()); \
    } catch (const exception_type&) { \
    } catch (...) { \
        std::stringstream ss; \
        ss << "Assertion failed: expected exception " << #exception_type << ", but a different exception was thrown, file " << __FILE__ << ", line " << __LINE__; \
        throw std::runtime_error(ss.str()); \
    }

#define ASSERT_NO_THROW(statement) \
    try { \
        statement; \
    } catch (...) { \
        std::stringstream ss; \
        ss << "Assertion failed: expected no exception, but an exception was thrown, file " << __FILE__ << ", line " << __LINE__; \
        throw std::runtime_error(ss.str()); \
    }



#endif