/*
q quit program -->OK
0 create zero matrix A  -->OK
a print matrix A  -->OK
b print matrix B  -->OK
c print matrix C  -->OK
A initialise matrix A  --> OK
B copy matrix A to matrix B
+ add matrix A to matrix B, placing the result in matrix C --> OK
t transpose matrix A --> OK
∗ multiply matrix A and B, placing the result in matrix C
m compute a minor of matrix A, placing the result in matrix C
d compute the determinant of matrix A
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXROWS 10

typedef struct
{
    int rows, columns;
    float *elements[MAXROWS];
} matrix_t;

matrix_t newMatrix(int rows, int columns, char zeroOrRead);
void printMatrix(matrix_t m, char name);
void freeMatrixElements(matrix_t *m);
void addMatrices(matrix_t ma, matrix_t mb);
void transposeMatrix(matrix_t *m);
void copyA2B(matrix_t *ma, matrix_t *mb);

int main()
{
    matrix_t ma = {-1, -1, {
                               NULL,
                           }};
    matrix_t mb = {-1, -1, {
                               NULL,
                           }};
    matrix_t mc = {-1, -1, {
                               NULL,
                           }};

    char cmd;

    int rows, cols;
    ma.rows = 0;
    ma.columns = 0;
    mb.rows = 0;
    mb.columns = 0;

    do
    {
        printf("Command? ");
        scanf(" %c", &cmd);
        switch (cmd)
        {
        case '0':
        case 'A':
            printf("Size of matrix A (rows columns)? ");
            scanf("%d %d", &rows, &cols);

            freeMatrixElements(&ma);

            ma = newMatrix(rows, cols, cmd);
            break;

        case 'a':
            printMatrix(ma, 'A');
            break;
        case 'b':
            printMatrix(mb, 'B');
            break;
        case 'c':
            printMatrix(mc, 'C');
            break;
        case 'B':
            mb = newMatrix(ma.rows, ma.columns, '0');
            copyA2B(&ma, &mb);
            break;
        case '+':
            addMatrices(ma, mb);
            break;
        case 't':
            transposeMatrix(&ma);
            break;
        case 'q':
            freeMatrixElements(&ma);
            freeMatrixElements(&mb);
            freeMatrixElements(&mc);
            printf("Bye!\n");
            break;
        default:
            printf("Unknown command '%c'\n", cmd);
        }
    } while (cmd != 'q');

    return 0;
}

matrix_t newMatrix(int rows, int columns, char zeroOrRead)
{
    int r, c;
    matrix_t matrix;

    matrix.rows = rows;
    matrix.columns = columns;

    for (r = 0; r < rows; r++)
    {
        matrix.elements[r] = (float *)malloc(columns * sizeof(float));
        if (zeroOrRead == '0')
        {
            for (c = 0; c < columns; c++)
            {
                matrix.elements[r][c] = 0;
            }
        }
        else if (zeroOrRead == 'A')
        {
            printf("Row %d: ", r);
            for (c = 0; c < columns; c++)
            {
                scanf("%f", &matrix.elements[r][c]);
            }
        }
    }

    return matrix;
}

void printMatrix(matrix_t m, char name)
{
    int r, c;

    // Is the matrix empty?
    if (m.rows == -1 || m.columns == -1)
    {
        printf("Matrix %c is empty\n", name); // Then tell the user that it is empty
        return;                               // exit function
    }

    // Print the size of the matrix first
    printf("Matrix %c (%d X %d):\n", name, m.rows, m.columns);

    // Print the values of the matirx
    for (r = 0; r < m.rows; r++)
    {
        for (c = 0; c < m.columns; c++)
        {
            printf("%6.2f ", m.elements[r][c]);
        }
        printf("\n");
    }
}

void freeMatrixElements(matrix_t *m)
{
    int r, c;
    // Is the matrix not an empty matris?
    if (m->rows == -1 && m->columns == -1)
    {
        return;
    }

    for (r = 0; r < m->rows; r++)
    {

        if (m->elements[r] != NULL)
        {
            free(m->elements[r]);
            m->elements[r] = NULL;
        }
    }
    // Reset matrix
    m->rows = -1;
    m->columns = -1;
}

void addMatrices(matrix_t ma, matrix_t mb)
{
    int r, c;

    if (ma.elements == NULL || mb.elements == NULL)
    {
        printf("Matrices cannot be empty\n");
        return;
    }

    if (ma.rows != mb.rows || ma.columns != mb.columns)
    {
        printf("Matrix dimensions don't agree\n");
        return;
    }

    for (r = 0; r < ma.rows; r++)
    {
        for (c = 0; c < ma.columns; c++)
        {
            mb.elements[r][c] += ma.elements[r][c];
        }
    }
}

void transposeMatrix(matrix_t *m)
{
    int r, c;
    if (m->elements == NULL)
    {
        printf("Matrix cannot be empty\n");
        return;
    }

    int newRows = m->columns;
    int newCols = m->rows;
    float **newElements = (float **)malloc(newRows * sizeof(float *));

    for (r = 0; r < newRows; r++)
    {
        newElements[r] = (float *)malloc(newCols * sizeof(float));

        for (c = 0; c < newCols; c++)
        {
            newElements[r][c] = m->elements[c][r];
        }
    }

    // Free the old memory
    for (r = 0; r < m->rows; r++)
    {
        free(m->elements[r]);
    }

    // Assign the new values to the matrix m
    for (r = 0; r < newRows; r++)
    {
        m->elements[r] = newElements[r];
    }

    free(newElements); // Free the top-level array of pointers

    m->rows = newRows;
    m->columns = newCols;
}

void copyA2B(matrix_t *ma, matrix_t *mb)
{
    freeMatrixElements(mb);

    int r, c;
    mb->rows = ma->rows;
    mb->columns = ma->columns;
    // mb->elements = (float*)malloc(mb->rows * sizeof(float *));

    for (r = 0; r < mb->rows; r++)
    {
        mb->elements[r] = (float *)malloc(mb->columns * sizeof(float));

        for (c = 0; c < mb->columns; c++)
        {
            mb->elements[r][c] = ma->elements[r][c];
        }
    }
}
