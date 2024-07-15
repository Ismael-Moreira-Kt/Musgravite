#include "musgravite.h"
#include "musgravite.hpp"
#include <stdexcept>
#include <sstream>
#include <cmath>





struct MusgraviteRunnerImpl {
    MusgraviteRunner runner;
};





static MusgraviteRunnerImpl* global_runner = nullptr;





extern "C" {
    void initializeMusgraviteRunner() {
        if (global_runner == nullptr) {
            global_runner = (MusgraviteRunnerImpl*)malloc(sizeof(MusgraviteRunnerImpl));
            
            if (global_runner != nullptr) {
                new (&global_runner->runner) MusgraviteRunner();
            }
        }
    }



    void cleanupMusgraviteRunner() {
        if (global_runner != nullptr) {
            free(global_runner);

            global_runner = nullptr;
        }
    }



    void runAllTestsC() {
        if (global_runner == nullptr) {
            return;
        }

        global_runner->runner.runAllTests();
    }



    void ADD_TEST_C(const char* suite, const char* test, void (*func)(void)) {
        if (global_runner == nullptr) {
            return;
        }

        global_runner->runner.addTest(suite, test, func);
    }



    void ADD_TEST_TIMEOUT_C(const char* suite, const char* test, void (*func)(void), int timeout) {
        if (global_runner == nullptr) {
            return;
        }
        
        global_runner->runner.addTest(suite, test, func, nullptr, nullptr, std::chrono::seconds(timeout));
    }



    void ADD_TEST_SETUP_C(const char* suite, const char* test, void (*func)(void), void (*setup)(void)) {
        if (global_runner == nullptr) {
            return;
        }
        
        global_runner->runner.addTest(suite, test, func, setup);
    }



    void ADD_TEST_SETUP_TEARDOWN_C(const char* suite, const char* test, void (*func)(void), void (*setup)(void), void (*teardown)(void)) {
        if (global_runner == nullptr) {
            return;
        }
        
        global_runner->runner.addTest(suite, test, func, setup, teardown);
    }



    void ADD_TEST_SETUP_TIMEOUT_C(const char* suite, const char* test, void (*func)(void), void (*setup)(void), int timeout) {
        if (global_runner == nullptr) {
            return;
        }
        
        global_runner->runner.addTest(suite, test, func, setup, nullptr, std::chrono::seconds(timeout));
    }



    void ADD_TEST_TEARDOWN_C(const char* suite, const char* test, void (*func)(void), void (*teardown)(void)) {
        if (global_runner == nullptr) {
            return;
        }
        
        global_runner->runner.addTest(suite, test, func, nullptr, teardown);
    }



    void ADD_TEST_TEARDOWN_TIMEOUT_C(const char* suite, const char* test, void (*func)(void), void (*teardown)(void), int timeout) {
        if (global_runner == nullptr) {
            return;
        }
        
        global_runner->runner.addTest(suite, test, func, nullptr, teardown, std::chrono::seconds(timeout));
    }



    void ADD_TEST_SETUP_TEARDOWN_TIMEOUT_C(const char* suite, const char* test, void (*func)(void), void (*setup)(void), void (*teardown)(void), int timeout) {
        if (global_runner == nullptr) {
            return;
        }
        
        global_runner->runner.addTest(suite, test, func, setup, teardown, std::chrono::seconds(timeout));
    }



    void IGNORE_TEST_C(const char* test) {
        printColored(std::string("Test ") + test + " ignored.", YELLOW);
    }



    void ASSERT_TRUE_C(int cond, const char* cond_str, const char* file, int line) {
        if (!cond) {
            std::stringstream ss;
            ss << "Assertion failed: " << cond_str << ", file " << file << ", line " << line;
            
            throw std::runtime_error(ss.str());
        }
    }



    void ASSERT_FALSE_C(int cond, const char* cond_str, const char* file, int line) {
        if (cond) {
            std::stringstream ss;
            ss << "Assertion failed: " << cond_str << " is true, file " << file << ", line " << line;
            
            throw std::runtime_error(ss.str());
        }
    }



    void ASSERT_EQUAL_C(int expected, int actual, const char* file, int line) {
        if (expected != actual) {
            std::stringstream ss;
            ss << "Assertion failed: expected " << expected << ", got " << actual << ", file " << file << ", line " << line;
            
            throw std::runtime_error(ss.str());
        }
    }



    void ASSERT_NOT_EQUAL_C(int expected, int actual, const char* file, int line) {
        if (expected == actual) {
            std::stringstream ss;
            ss << "Assertion failed: expected not " << expected << ", but got " << actual << ", file " << file << ", line " << line;
            
            throw std::runtime_error(ss.str());
        }
    }



    void ASSERT_NEAR_C(double expected, double actual, double tol, const char* file, int line) {
        if (std::fabs(expected - actual) > tol) {
            std::stringstream ss;
            ss << "Assertion failed: expected near " << expected << ", got " << actual << ", with tolerance " << tol << ", file " << file << ", line " << line;
            
            throw std::runtime_error(ss.str());
        }
    }



    void ASSERT_THROW_C(void (*statement)(void), const char* exception_type, const char* file, int line) {
        try {
            statement();
            
            std::stringstream ss;
            ss << "Assertion failed: expected exception " << exception_type << ", but no exception thrown, file " << file << ", line " << line;
            
            throw std::runtime_error(ss.str());
        } catch (const std::exception& e) {
            
        } catch (...) {
            std::stringstream ss;
            ss << "Assertion failed: expected exception " << exception_type << ", but a different exception was thrown, file " << file << ", line " << line;
            
            throw std::runtime_error(ss.str());
        }
    }



    void ASSERT_NO_THROW_C(void (*statement)(void), const char* file, int line) {
        try {
            statement();
        } catch (...) {
            std::stringstream ss;
            ss << "Assertion failed: expected no exception, but an exception was thrown, file " << file << ", line " << line;
            
            throw std::runtime_error(ss.str());
        }
    }
}