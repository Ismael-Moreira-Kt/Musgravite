<div align="center">
    <img src="./assets/images/" alt="Project logo." width=200>
</div>



# Musgravite
Musgravite is a testing library designed to support multiple programming languages.



## Functionalities
- Support for synchronous and asynchronous tests;
- Optional `setup` and `teardown` settings;
- Configurable timeouts;
- Colored test results for better readability.



## Usage
### Test Definition
The library offers macros for defining tests:

- **TEST:** Defines a test.
- **ADD_TEST:** Adds a test to a suite.
- **IGNORE_TEST:** Ignores a test.


### Assertions
Macros available for checking conditions in tests:

- **ASSERT_TRUE:** Checks if the condition is true.
- **ASSERT_FALSE:** Checks if the condition is false.
- **ASSERT_EQUAL:** Checks if two values are equal.
- **ASSERT_NEAR:** Checks if two values are close within a tolerance.
- **ASSERT_THROW:** Checks if an exception is thrown.
- **ASSERT_NO_THROW:** Checks that no exception is thrown.