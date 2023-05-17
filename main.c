
#define NN_IMPLEMENTATION
#include "neural_network.h"

int main(void)
{
    Matrix a = mat_alloc(1, 2);
    mat_fill(a, 2);

    Matrix b = mat_alloc(2, 2);
    mat_fill(b, -5);

    Matrix result = mat_alloc(1, 2);
    mat_mult(result, a, b);

    MAT_PRINT(a);
    MAT_PRINT(b);
    MAT_PRINT(result);
    return 0;
}