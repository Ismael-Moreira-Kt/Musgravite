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



## Installation
The Musgravite library was initially developed to support C, C++, D, and Nim. However, it continues to evolve with ongoing expansions and improvements. To better accommodate users of each supported language, we have organized the usage tutorials accordingly:

| Language | Installation                          | Usage                          |
|----------|---------------------------------------|--------------------------------|
| C        | [C Installation Guide](./docs/C/)     | [C Usage Guide](./docs/C/)     |
| C++      | [C++ Installation Guide](./docs/Cpp/) | [C++ Usage Guide](./docs/Cpp/) |
| D        | [D Installation Guide](./docs/D/)     | [D Usage Guide](./docs/D/)     |
| Nim      | [Nim Installation Guide](./docs/Nim/) | [Nim Usage Guide](./docs/Nim/) |



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



## License
Distributed under the MIT license. See the [LICENSE](./LICENSE) file for more details.