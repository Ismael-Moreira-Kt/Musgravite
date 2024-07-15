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
}





#endif