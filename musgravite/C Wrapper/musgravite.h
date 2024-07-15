#ifndef MUSGRAVITE_H
#define MUSGRAVITE_H





#ifdef __cplusplus
    extern "C" {
        #endif
            typedef struct MusgraviteRunnerImpl MusgraviteRunnerImpl;



            void runAllTestsC(void);
            void initializeMusgraviteRunner(void);
            void cleanupMusgraviteRunner(void);



            void ADD_TEST_C(const char* suite, const char* test, void (*func)(void));
            void ADD_TEST_TIMEOUT_C(const char* suite, const char* test, void (*func)(void), int timeout);
            void ADD_TEST_SETUP_C(const char* suite, const char* test, void (*func)(void), void (*setup)(void));
            void ADD_TEST_SETUP_TEARDOWN_C(const char* suite, const char* test, void (*func)(void), void (*setup)(void), void (*teardown)(void));
            void ADD_TEST_SETUP_TIMEOUT_C(const char* suite, const char* test, void (*func)(void), void (*setup)(void), int timeout);
            void ADD_TEST_TEARDOWN_C(const char* suite, const char* test, void (*func)(void), void (*teardown)(void));
            void ADD_TEST_TEARDOWN_TIMEOUT_C(const char* suite, const char* test, void (*func)(void), void (*teardown)(void), int timeout);
            void ADD_TEST_SETUP_TEARDOWN_TIMEOUT_C(const char* suite, const char* test, void (*func)(void), void (*setup)(void), void (*teardown)(void), int timeout);
        #ifdef
    }
#endif





#endif