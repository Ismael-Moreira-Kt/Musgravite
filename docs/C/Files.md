# File Structure
In this document, you will be introduced to the structure of the files used in the library and which ones are really important to you.

<br>

## Musgravite in C
Musgravite in C is actually a wrapper. In other words, it's a library made for C++ with an interface that offers compatibility with the C language. To be useful in C, musgravite needs three main files:


#### Project root
- **musgravite.hpp ->** This is the most important file, the “father” of them all. It is the C++ header that defines what each file should do and how it should be implemented.


#### musgravite/C Wrapper
- **musgravite.h ->** This is the C header. It provides instructions on what can be implemented and how it should be implemented in C.
- **musgraviteImpl.cpp ->** The implementation of musgravite in C. Ironically, it is made in C++, but basically serves as a bridge between your files and the definitions imposed by musgravite.hpp.