
#define NN_IMPLEMENTATION
#include "neural_network.h"

int main(void)
{
    Matrix a = mat_alloc(2, 4);
    mat_fill(a, 1);

    Matrix b = mat_alloc(2, 4);
    mat_fill(b, 5);

    Matrix result = mat_alloc(2, 4);
    mat_sum(result, a, b);

    MAT_PRINT(result);
    return 0;
}