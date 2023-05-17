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
void mat_print(Matrix res);

#endif // NN_HEADER

#ifdef NN_IMPLEMENTATION

#ifndef NN_ASSERT
#define NN_ASSERT assert
#endif // NN_ASSERT

#ifndef NN_MALLOC
#define NN_MALLOC malloc
#endif // NN_MALLOC

#ifndef NN_PRINT
#define NN_PRINT(v) printf("   %f", (v))
#endif // NN_PRINT

#define MATRIX_POINT(m, i, j) (m).data[(i) * (m).cols + (j)]

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
    NN_ASSERT(a.rows == b.cols);

    for (int i = 0; i < a.cols; i++)
    {
        for (int j = 0; j < a.rows; j++)
        {
            MATRIX_POINT(res, i, j) = MATRIX_POINT(res, i, j) + MATRIX_POINT(res, i, j);
        }
    }
}

void mat_fill(Matrix res, float value)
{
    for (int i = 0; i < res.cols; i++)
    {
        for (int j = 0; j < res.rows; j++)
        {
            MATRIX_POINT(res, i, j) = value;
        }
    }
}

void mat_print(Matrix res)
{
    for (int i = 0; i < res.cols; i++)
    {
        for (int j = 0; j < res.rows; j++)
        {
            NN_PRINT(MATRIX_POINT(res, i, j));
        }
    }
}

#endif // NN_IMPLEMENTATION