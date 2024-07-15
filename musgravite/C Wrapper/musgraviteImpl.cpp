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
}