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





bool useColor = true;



void disableColors() {
    useColor = false;
}



void printColored(const std::string& message, const std::string& color = "") {
    if (useColor) {
        std::cout << color << message << RESET << std::endl;
    } 
    else {
        std::cout << message << std::endl;
    }
}





class Musgravite {
    public:
        Musgravite(
            const std::string& name,
            std::function<void()> func,
            std::function<void()> setup = nullptr,
            std::function<void()> teardown = nullptr,
            std::chrono::seconds timeout = std::chrono::seconds(30)
        ) :
            name(name),
            func(func),
            setup(setup),
            teardown(teardown),
            timeout(timeout)
        {}


        void run() const {
            try {
                if (setup) setup();

                auto start = std::chrono::high_resolution_clock::now();
                bool asyncTest = isAsyncTest(func);

                if (asyncTest) {
                    std::promise<void> promise;
                    auto future = promise.get_future();

                    std::thread asyncThread([&]() {
                        try {
                            func();
                            promise.set_value();
                        } catch (...) {
                            promise.set_exception(std::current_exception());
                        }
                    });

                    auto status = future.wait_for(timeout);

                    if (status == std::future_status::timeout) {
                        asyncThread.detach();
                    
                        throw std::runtime_error("Async test timed out.");
                    } else {
                        asyncThread.join();
                    }
                } else {
                    func();
                }

                auto end = std::chrono::high_resolution_clock::now();

                std::chrono::duration<double, std::milli> duration = end - start; // Duration in milliseconds
                printColored("Test " + name + " passed in " + std::to_string(duration.count()) + " milliseconds.", GREEN);

                if (teardown) teardown();
            } catch (const std::exception& exception) {
                printColored("Test " + name + " failed: " + exception.what(), RED);

                if (teardown) teardown();

                throw;
            }
        }


        std::string getName() const {
            return name;
        }



    private:
        std::string name;
        std::function<void()> func;
        std::function<void()> setup;
        std::function<void()> teardown;
        std::chrono::seconds timeout;


        bool isAsyncTest(const std::function<void()>& f) const {
            std::string funcName = name;

            return funcName.size() > 5 && funcName.compare(funcName.size() - 5, 5, "Async") == 0;
        }
}





class MusgraviteRunner {
    public:
        void addTest(
            const std::string& suiteName,
            const std::string& testName,

            std::function<void()> func,
            std::function<void()> setup = nullptr,
            std::function<void()> teardown = nullptr,
            std::chrono::seconds timeout = std::chrono::seconds(30))
        {
            if (suites.find(suiteName) == suites.end()) {
                suites[suiteName] = std::vector<Musgravite>();
            }

            suites[suiteName].emplace_back(testName, func, setup, teardown, timeout);
        }


        void runAllTests() {
            int totalPassed = 0;
            int totalTests = 0;
            double totalTime = 0.0;

            for (const auto& suite : suites) {
                int passed = 0;
                double suiteTime = 0.0;

                std::vector<std::string> failedTests;

                printColored("Running suite: " + suite.first, CYAN);

                for (auto& test : suite.second) {
                    try {
                        auto start = std::chrono::high_resolution_clock::now();

                        test.run();

                        auto end = std::chrono::high_resolution_clock::now();

                        std::chrono::duration<double, std::milli> duration = end - start; // Duration in milliseconds

                        suiteTime += duration.count();
                        passed++;
                    } catch (const std::exception& e) {
                        failedTests.push_back(test.getName() + ": " + e.what());
                    }
                }

                double averageTime = suite.second.empty() ? 0.0 : suiteTime / suite.second.size();
                totalTime += suiteTime;

                printColored(std::to_string(passed) + "/" + std::to_string(suite.second.size()) + " tests passed in suite " + suite.first, GREEN);
                printColored("Suite " + suite.first + " total time: " + std::to_string(suiteTime) + " milliseconds.", BLUE);
                printColored("Suite " + suite.first + " average time per test: " + std::to_string(averageTime) + " milliseconds.", RESET);

                if (!failedTests.empty()) {
                    printColored("Failed tests:", RED);

                    for (const auto& fail : failedTests) {
                        printColored(fail, RED);
                    }
                }

                totalPassed += passed;
                totalTests += suite.second.size();
            }

            double overallAverageTime = totalTests == 0 ? 0.0 : totalTime / totalTests;

            printColored("Overall results:", BOLD);
            printColored(std::to_string(totalPassed) + "/" + std::to_string(totalTests) + " tests passed across all suites.", GREEN);
            printColored("Total time for all suites: " + std::to_string(totalTime) + " milliseconds.", BLUE);
            printColored("Overall average time per test: " + std::to_string(overallAverageTime) + " milliseconds.", RESET);
        }



    private:
        std::map<std::string, std::vector<Musgravite>> suites;
}





#endif