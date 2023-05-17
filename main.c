#include <stdlib.h>

#define NN_MALLOC malloc;
#define NN_IMPLEMENTATION
#include "neural_network.h"

int main(void)
{
    Matrix a;
    mat_fill(a, 1);

    mat_print(a);
    return 0;
}