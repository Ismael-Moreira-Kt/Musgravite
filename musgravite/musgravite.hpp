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





#endif