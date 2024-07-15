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
}