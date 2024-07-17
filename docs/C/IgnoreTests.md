# IGNORE_TEST_C
In this tutorial, you'll learn everything you need to know about the `IGNORE_TEST_C` function.

<br>

## What is IGNORE_TEST_C?
`IGNORE_TEST_C` is a function that marks a test as ignored. This function is useful for skipping tests that are not ready to be run or are temporarily disabled. When a test is ignored, a message is printed to indicate that the test was skipped.

<br>

## Implementing IGNORE_TEST_C
To ignore a test, simply call the function:

```C
    IGNORE_TEST_C("testName");
```

This function can be used anywhere in your test code where you need to skip a test and provide a visual indication of the skipped test.

<br>

## What does IGNORE_TEST_C do?
Here is the implementation of the IGNORE_TEST_C function:

```Cpp
    void IGNORE_TEST_C(const char* test) {
        printColored(std::string("Test ") + test + " ignored.", YELLOW);
    }
```

- **Message Formatting:** The function creates a message string indicating that the specified test is ignored.
- **Colored Output:** The message is printed in yellow color to highlight the ignored test.

<br>

## Important Notes
- **Usage Context:** Use IGNORE_TEST_C to skip tests that are not applicable or need to be disabled temporarily. This helps in keeping the test suite clean and avoiding unnecessary failures.
- **Visual Indication:** The yellow color output provides a clear visual indication in the test results, making it easy to spot ignored tests.
- **No Impact on Test Execution:** Ignoring a test does not affect the execution of other tests. Only the specified test is skipped, and the rest of the test suite runs as expected.