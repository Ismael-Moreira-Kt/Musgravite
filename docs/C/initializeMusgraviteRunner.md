# InitializeMusgraviteRunner
In this tutorial, you'll learn basically everything you need to know about the `initializeMusgraviteRunner` function.

<br>

## What is Musgravite Runner?
Before learning how to initialize the runner, it's important to understand what it is. `MusgraviteRunner` is the class that defines a test in `musgravite.hpp`. In other words, `initializeMusgraviteRunner` is the function that initializes the `MusgraviteRunner class`.

<br>

## Implementing initializeMusgraviteRunner
To implement runner initialization, simply call the function:

```C
    initializeMusgraviteRunner();
```

I've done my best to make the implementation of the class as simple as possible, which is why the `initializeMusgraviteRunner()` abstraction exists. It's important to remember a few points:
1. The `initializeMusgraviteRunner` method is mandatory; without it, you can't run the tests.
2. This method must be followed by `cleanupMusgraviteRunner` at the end of the tests. See the [`cleanupMusgraviteRunner` documentation](./cleanupMusgraviteRunner.md) for more details.

<br>

## What does initializeMusgraviteRunner do?
Behind the scenes, when you simply call a function, a few things happen. The function you call is split into two implementations.


#### Setting the Global Runner
First, we define `global_runner` as a null pointer:

```cpp
    static MusgraviteRunnerImpl* global_runner = nullptr;
```