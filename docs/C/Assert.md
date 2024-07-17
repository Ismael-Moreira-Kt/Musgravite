# ASSERT Functions in C
In this tutorial, you'll learn everything you need to know about the `ASSERT` functions provided for *C*. These functions help verify conditions in your tests, ensuring your code behaves as expected.

<br>

## Overview
The `ASSERT` functions are used to validate different conditions in your tests. When an assertion fails, a detailed error message is generated, and a *std::runtime_error* is thrown.

<br>

## ASSERT Functions
### ASSERT_TRUE_C
Asserts that a condition is true.

```C
    ASSERT_TRUE_C(cond, "condition", __FILE__, __LINE__);    
```

##### Implementation
```Cpp
    void ASSERT_TRUE_C(int cond, const char* cond_str, const char* file, int line) {
        if (!cond) {
            std::stringstream ss;
            ss << "Assertion failed: " << cond_str << ", file " << file << ", line " << line;
            
            throw std::runtime_error(ss.str());
        }
    }
```
- **Condition Check:** Checks if cond is true. If not, an error message is generated.
- **Error Message:** Includes the condition string, file name, and line number.

### ASSERT_FALSE_C
Asserts that a condition is false.

```C
    ASSERT_FALSE_C(cond, "condition", __FILE__, __LINE__);   
```

##### Implementation
```Cpp
    void ASSERT_FALSE_C(int cond, const char* cond_str, const char* file, int line) {
        if (cond) {
            std::stringstream ss;
            ss << "Assertion failed: " << cond_str << " is true, file " << file << ", line " << line;
            
            throw std::runtime_error(ss.str());
        }
    }
```
- **Condition Check:** Checks if cond is false. If not, an error message is generated.
- **Error Message:** Includes the condition string, file name, and line number.

### ASSERT_EQUAL_C
Asserts that two integers are equal.

```C
    ASSERT_EQUAL_C(expected, actual, __FILE__, __LINE__); 
```

##### Implementation
```Cpp
    void ASSERT_EQUAL_C(int expected, int actual, const char* file, int line) {
        if (expected != actual) {
            std::stringstream ss;
            ss << "Assertion failed: expected " << expected << ", got " << actual << ", file " << file << ", line " << line;
            
            throw std::runtime_error(ss.str());
        }
    }
```
- **Equality Check:** Compares expected and actual. If they are not equal, an error message is generated.
- **Error Message:** Includes the expected value, actual value, file name, and line number.

### ASSERT_NOT_EQUAL_C
Asserts that two integers are not equal.

```C
    ASSERT_NOT_EQUAL_C(expected, actual, __FILE__, __LINE__);
```

##### Implementation
```Cpp
    void ASSERT_NOT_EQUAL_C(int expected, int actual, const char* file, int line) {
        if (expected == actual) {
            std::stringstream ss;
            ss << "Assertion failed: expected not " << expected << ", but got " << actual << ", file " << file << ", line " << line;
            
            throw std::runtime_error(ss.str());
        }
    }
```
- **Inequality Check:** Compares expected and actual. If they are equal, an error message is generated.
- **Error Message:** Includes the expected value, actual value, file name, and line number.

### ASSERT_NEAR_C
Asserts that two floating-point numbers are nearly equal within a tolerance.
```C 
    ASSERT_NEAR_C(expected, actual, tol, __FILE__, __LINE__);
```

##### Implementation
```Cpp
    void ASSERT_NEAR_C(double expected, double actual, double tol, const char* file, int line) {
        if (std::fabs(expected - actual) > tol) {
            std::stringstream ss;
            ss << "Assertion failed: expected near " << expected << ", got " << actual << ", with tolerance " << tol << ", file " << file << ", line " << line;
            
            throw std::runtime_error(ss.str());
        }
    }
```
- **Near Check:** Compares expected and actual within the specified tolerance tol. If they are not nearly equal, an error message is generated.
- **Error Message:** Includes the expected value, actual value, tolerance, file name, and line number.