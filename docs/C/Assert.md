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

#### Implementation
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