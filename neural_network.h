#ifndef NN_HEADER
#define NN_HEADER

typedef struct M
{
    float rows;
    float cols;
    float *data;
} Matrix;

Matrix mat_alloc(float rows, float cols);
void mat_sum(Matrix res, Matrix a, Matrix b);
void mat_mult(Matrix res, Matrix a, Matrix b);
void mat_fill(Matrix res, float val);
void mat_print(Matrix res, char *name);

#endif // NN_HEADER

#ifdef NN_IMPLEMENTATION

#ifndef NN_ASSERT
#include <assert.h>
#define NN_ASSERT assert
#endif // NN_ASSERT

#ifndef NN_MALLOC
#include <stdlib.h>
#define NN_MALLOC malloc
#endif // NN_MALLOC

#ifndef NN_PRINT
#include <stdio.h>
#define NN_PRINT(v) printf("   %f", (v))
#endif // NN_PRINT

#define MATRIX_POINT(m, i, j) (m).data[(int)(i) * (int)(m).cols + (int)(j)]

#define MAT_PRINT(m) mat_print(m, #m)

Matrix mat_alloc(float rows, float cols)
{
    NN_ASSERT(rows > 0);
    NN_ASSERT(cols > 0);
    Matrix m;
    m.rows = rows;
    m.cols = cols;
    m.data = NN_MALLOC(sizeof(*m.data));
    return m;
}

void mat_sum(Matrix res, Matrix a, Matrix b)
{
    NN_ASSERT(a.cols == b.cols);
    NN_ASSERT(a.rows == b.rows);

    for (int i = 0; i < a.rows; i++)
    {
        for (int j = 0; j < a.cols; j++)
        {
            MATRIX_POINT(res, i, j) = MATRIX_POINT(a, i, j) + MATRIX_POINT(b, i, j);
        }
    }
}

void mat_mult(Matrix res, Matrix a, Matrix b)
{
    NN_ASSERT(a.cols == b.rows);
    NN_ASSERT(res.rows == a.rows && res.cols == b.cols);

    for (int i = 0; i < res.rows; i++)
    {
        for (int j = 0; j < res.cols; j++)
        {
            MATRIX_POINT(res, i, j) = 0;
            for (int k = 0; k < a.cols; k++)
            {
                MATRIX_POINT(res, i, j) += MATRIX_POINT(a, i, k) * MATRIX_POINT(b, k, j);
            }
        }
    }
}

void mat_fill(Matrix res, float value)
{
    for (int i = 0; i < res.rows; i++)
    {
        for (int j = 0; j < res.cols; j++)
        {
            MATRIX_POINT(res, i, j) = value;
        }
    }
}

void mat_print(Matrix res, char *name)
{
    printf("%s = [\n", name);
    for (int i = 0; i < res.rows; i++)
    {
        for (int j = 0; j < res.cols; j++)
        {
            NN_PRINT(MATRIX_POINT(res, i, j));
        }
        printf("\n");
    }
    printf("\n]\n");
}

#endif // NN_IMPLEMENTATION