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
        


            void IGNORE_TEST_C(const char* test);



            void ASSERT_TRUE_C(int cond, const char* cond_str, const char* file, int line);
            void ASSERT_FALSE_C(int cond, const char* cond_str, const char* file, int line);
            void ASSERT_EQUAL_C(int expected, int actual, const char* file, int line);
            void ASSERT_NOT_EQUAL_C(int expected, int actual, const char* file, int line);
            void ASSERT_NEAR_C(double expected, double actual, double tol, const char* file, int line);
            void ASSERT_THROW_C(void (*statement)(void), const char* exception_type, const char* file, int line);
            void ASSERT_NO_THROW_C(void (*statement)(void), const char* file, int line);
        #ifdef __cplusplus
    }
#endif





#endif