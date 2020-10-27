#include "Matrix.h"

Matrix matrix_CreateMatrix(int cols, int rows)
{
    if (cols > MAX_MATRIX_DIM || rows > MAX_MATRIX_DIM || rows < 0 || cols < 0)
    {
        cols = MAX_MATRIX_DIM;
        rows = MAX_MATRIX_DIM;
    }

    Matrix mat;
    mat.cols = cols;
    mat.rows = rows;
    int i, j;
    for (i = 0; i < rows; i ++)
            for (j = 0; j < cols; j ++)
                mat.data[i][j] = 0;
    return mat;
}

Matrix matrix_CopyMatrix(Matrix *mat)
{
    Matrix final = matrix_CreateMatrix(mat->cols, mat->rows);
    int i, j;
    for (i = 0; i < final.rows; i ++)
            for (j = 0; j < final.cols; j ++)
                final.data[i][j] = mat->data[i][j];
    return final;
}

bool matrix_SetValue(Matrix *mat, int colIndex, int rowIndex, float value)
{
    if (rowIndex > mat->rows || colIndex > mat->cols || colIndex < 0 || rowIndex < 0)
        return false;
    
    mat->data[colIndex][rowIndex] = value;

    return true;
}

bool matrix_SwapRows(Matrix *mat, int destIndex, int tgtIndex)
{
    if (destIndex > mat->rows || tgtIndex > mat->rows || destIndex < 0 || tgtIndex < 0)
        return false;
    
    int i;
    for (i = 0; i < mat->cols; i ++)
    {
        float val = mat->data[destIndex][i];
        mat->data[destIndex][i] = mat->data[tgtIndex][i];
        mat->data[tgtIndex][i] = val;
    }

    return true;
}

bool matrix_MultRowByRow(Matrix *mat, int destIndex, int tgtIndex)
{
    if (destIndex > mat->rows || tgtIndex > mat->rows || destIndex < 0 || tgtIndex < 0)
        return false;
    
    int i;
    for (i = 0; i < mat->cols; i ++)
        mat->data[destIndex][i] *= mat->data[tgtIndex][i];
    
    return true;
}

bool matrix_AddRowToRow(Matrix *mat, int tgtIndex, int destIndex)
{
    if (destIndex > mat->rows || tgtIndex > mat->rows || destIndex < 0 || tgtIndex < 0)
        return false;
    
    int i;
    for (i = 0; i < mat->cols; i ++)
        mat->data[destIndex][i] += mat->data[tgtIndex][i];
    
    return true;
}

bool matrix_SubRowFromRow(Matrix *mat, int tgtIndex, int destIndex)
{
    if (destIndex > mat->rows || tgtIndex > mat->rows || destIndex < 0 || tgtIndex < 0)
        return false;
    
    int i;
    for (i = 0; i < mat->cols; i ++)
        mat->data[destIndex][i] -= mat->data[tgtIndex][i];
    
    return true;
}

bool matrix_Add(Matrix *a, Matrix *b)
{
    if (a->rows != b->rows || a->cols != b->cols)
        return false;
    
    int i, j;
    for (i = 0; i < a->rows; i ++)
        for (j = 0; j < a->cols; j ++)
            a->data[i][j] += b->data[i][j];

    return true;
}

bool matrix_Sub(Matrix *a, Matrix *b)
{
    if (a->rows != b->rows || a->cols != b->cols)
        return false;
    
    int i, j;
    for (i = 0; i < a->rows; i ++)
        for (j = 0; j < a->cols; j ++)
            a->data[i][j] -= b->data[i][j];

    return true;
}

void matrix_MultByScalar(Matrix *tgt, float scalar)
{
    int x, y;
    for (y = 0; y < tgt->rows; y ++)
    {
        for (x = 0; x < tgt->cols; x ++)
        {
            tgt->data[y][x] *= scalar;
        }
    }
}

Matrix matrix_Mult(Matrix *a, Matrix *b)
{
    Matrix final;
    if (a->cols != b->rows) {

        final.rows = -1;
        final.cols = -1;
    
    } else {
        
        final = matrix_CreateMatrix(a->rows, b->cols);

        int i, j, k;
        for (i = 0; i < a->rows; i ++)
            for (j = 0; j < b->cols; j ++)
                for (k = 0; k < a->cols; k ++)
                    final.data[i][j] += a->data[i][k] * b->data[k][j];
    
    }

    return final;
}