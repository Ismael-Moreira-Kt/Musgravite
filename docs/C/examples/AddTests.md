# ADD_TEST_C and Variants
In this tutorial, you'll learn everything you need to know about the `ADD_TEST_C` function and its variants for adding tests in *C*.

<br>

## What is ADD_TEST_C?
`ADD_TEST_C` and its variants are functions used to add tests to the `MusgraviteRunner` in the *C* environment. These functions ensure that tests are registered with various configurations such as setup, teardown, and timeout options.

<br>

## Basic Test Addition
To add a basic test without setup, teardown, or timeout:

```C    
    ADD_TEST_C("suiteName", "testName", testFunction);
```

### Test with Timeout
To add a test with a timeout:

```C    
    ADD_TEST_TIMEOUT_C("suiteName", "testName", testFunction, timeoutInSeconds);
```

### Test with Setup
To add a test with a setup function:

```C    
    ADD_TEST_SETUP_C("suiteName", "testName", testFunction, setupFunction);
```

### Test with Teardown
To add a test with a teardown function:

```C    
    ADD_TEST_TEARDOWN_C("suiteName", "testName", testFunction, teardownFunction);
```

### Test with Setup and Teardown
To add a test with both setup and teardown functions:

```C    
    ADD_TEST_SETUP_TEARDOWN_C("suiteName", "testName", testFunction, setupFunction, teardownFunction);
```

### Test with Setup and Timeout
To add a test with both setup function and timeout:

```C
    ADD_TEST_SETUP_TIMEOUT_C("suiteName", "testName", testFunction, setupFunction, timeoutInSeconds);
```

### Test with Teardown and Timeout
To add a test with both teardown function and timeout:

```C
    ADD_TEST_TEARDOWN_TIMEOUT_C("suiteName", "testName", testFunction, teardownFunction, timeoutInSeconds);
```

### Test with Setup, Teardown, and Timeout
To add a test with setup, teardown, and timeout:

```C
    ADD_TEST_SETUP_TEARDOWN_TIMEOUT_C("suiteName", "testName", testFunction, setupFunction, teardownFunction, timeoutInSeconds);
```

<br>

## What do these functions do?
### Basic Test Addition
```Cpp
    void ADD_TEST_C(const char* suite, const char* test, void (*func)(void)) {
        if (global_runner == nullptr) {
            return;
        }

        global_runner->runner.addTest(suite, test, func);
    }
```
- **Null pointer check:** Checks if `global_runner` is *null*.
- **Test addition:** Adds the test to the `runner` if `global_runner` is initialized.

### Test with Timeout
```Cpp
    void ADD_TEST_TIMEOUT_C(const char* suite, const char* test, void (*func)(void), int timeout) {
        if (global_runner == nullptr) {
            return;
        }

        global_runner->runner.addTest(suite, test, func, nullptr, nullptr, std::chrono::seconds(timeout));
    }
```
- *Timeout parameter:* Adds a timeout to the test in addition to the basic test addition steps.

### Test with Setup
```Cpp
    void ADD_TEST_SETUP_C(const char* suite, const char* test, void (*func)(void), void (*setup)(void)) {
        if (global_runner == nullptr) {
            return;
        }

        global_runner->runner.addTest(suite, test, func, setup);
    }
```
- **Setup function:** Adds a setup function to be called before the test runs.

### Test with Teardown
```Cpp
    void ADD_TEST_TEARDOWN_C(const char* suite, const char* test, void (*func)(void), void (*teardown)(void)) {
        if (global_runner == nullptr) {
            return;
        }

        global_runner->runner.addTest(suite, test, func, nullptr, teardown);
    }
```
- **Teardown function:** Adds a teardown function to be called after the test runs.

### Test with Setup and Teardown
```Cpp
    void ADD_TEST_SETUP_TEARDOWN_C(const char* suite, const char* test, void (*func)(void), void (*setup)(void), void (*teardown)(void)) {
        if (global_runner == nullptr) {
            return;
        }

        global_runner->runner.addTest(suite, test, func, setup, teardown);
    }
```
- **Setup and Teardown functions:** Combines both setup and teardown functions for the test.