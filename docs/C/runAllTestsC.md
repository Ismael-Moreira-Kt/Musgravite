# runAllTestsC
In this tutorial, you'll learn everything you need to know about the `runAllTestsC` function.

<br>

## What is runAllTestsC?
`runAllTestsC` is a function that executes all tests defined in the *MusgraviteRunner*.

<br>

## Implementing runAllTestsC
To execute all tests, simply call the function:

```C
    runAllTestsC();
```

This function should be called after `initializeMusgraviteRunner` and before `cleanupMusgraviteRunner` to ensure that the tests are run within the appropriate lifecycle of the *test runner*.

<br>

## What does runAllTestsC do?
Here is the implementation of the *runAllTestsC* function:

```Cpp
    void runAllTestsC() {
        if (global_runner == nullptr) {
            return;
        }

        global_runner->runner.runAllTests();
    }
```

- **Null pointer check:** The function first checks if `global_runner` is *null*. If `global_runner` is *null*, the function returns immediately without attempting to run the tests.
- **Running all tests:** If `global_runner` is *not null*, it calls the `runAllTests` method on the `MusgraviteRunner object` to execute all the defined tests.

<br>

## Important Notes
- **Initialization Requirement:** Ensure that `initializeMusgraviteRunner` is called before `runAllTestsC` to properly initialize the `global_runner`. Without this, the tests will not run.
- **Cleanup Requirement:** After calling `runAllTestsC`, make sure to call `cleanupMusgraviteRunner` to free up resources and avoid memory leaks.