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