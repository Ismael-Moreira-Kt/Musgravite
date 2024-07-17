# CleanupMusgraviteRunner
In this tutorial, you'll learn everything you need to know about the `cleanupMusgraviteRunner` function.

<br>

## What is cleanupMusgraviteRunner?
cleanupMusgraviteRunner is a crucial function within the C wrapper that is responsible for cleaning up the MusgraviteRunner from memory. 

<br>

## Implementing cleanupMusgraviteRunner
To implement the runner cleanup, simply call the function at the end of your test code:

```C
    cleanupMusgraviteRunner();
```

This function should always be called as the last line in your test suite. It ensures that all allocated resources are properly freed, allowing the program to close safely and preventing memory leaks.

<br>

## What does cleanupMusgraviteRunner do?
Behind the scenes, while you're calling a simple function, this is what really happens:

```Cpp
    void cleanupMusgraviteRunner() {
        if (global_runner != nullptr) {
            free(global_runner);
            global_runner = nullptr;
        }
    }
```

- **Null pointer check:** The function first checks if `global_runner` is not *null*.
- **Memory deallocation:** If `global_runner` is not *null*, it deallocates the memory previously allocated for `MusgraviteRunnerImpl` using `free()`.
- **Resetting the pointer:** After freeing the memory, it sets `global_runner` to *null* to prevent any dangling pointer issues.

<br>

## Important Notes
- **Mandatory Cleanup:** Always ensure that `cleanupMusgraviteRunner` is called after all tests have been run. Failing to do so may result in memory leaks and other resource management issues.
- **Order of Operations:** Call `cleanupMusgraviteRunner` only after `initializeMusgraviteRunner` and all related test functions have completed their execution.
- **Safety:** By setting `global_runner` to *null* after freeing the memory, we protect against accidental use of freed memory, which could lead to undefined behavior.