#include <stdio.h>
#include "musgravite.h"
#include "matrix_multiplication.h"





void test_multiplyMatrices(void) {
    int firstMatrix[2][10] = { {1, 2}, {3, 4} };
    int secondMatrix[2][10] = { {5, 6}, {7, 8} };
    int result[2][10];
    int expected[2][10] = { {19, 22}, {43, 50} };

    multiplyMatrices(firstMatrix, secondMatrix, result, 2, 2, 2, 2);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            ASSERT_EQUAL_C(expected[i][j], result[i][j], __FILE__, __LINE__);
        }
    }
}





