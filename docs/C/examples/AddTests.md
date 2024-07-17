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