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
∗ multiply matrix A and B, placing the result in matrix C --> OK
m compute a minor of matrix A, placing the result in matrix C --> OK
d compute the determinant of matrix A --> OK
*/
#include <stdio.h>
#include <math.h>
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
void multiplyMatrices(matrix_t ma, matrix_t mb, matrix_t *mc);
matrix_t minorMatrix(matrix_t *m, int row, int column);
float determinant(matrix_t *m);

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
    float det;
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
        case '*':
            multiplyMatrices(ma, mb, &mc);
            break;
        case 'm':
            printf("Remove which row & column? ");
            scanf("%d %d", &rows, &cols);
            mc = minorMatrix(&ma, rows, cols);
            break;
        case 'd':
            det = determinant(&ma);
            if (ma.elements[0] != NULL && ma.rows == ma.columns)
            {
                printf("\nThe determinant is %f\n", det);
            }
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

    // are row count and the column count not in the allowed range?
    if (rows < 1 || rows > 10 || columns < 1)
    {
        // exit function if not
        printf("Rows must be 1 to 10, and columns must be at least 1 \n");
        return;
    }

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

    if (ma.elements[0] == NULL && mb.elements[0] == NULL)
    {
        printf("Matrices cannot be empty\n");
        return;
    }

    if (mb.elements[0] == NULL)
    {
        printf("Matrix B is empty\n");
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

void multiplyMatrices(matrix_t ma, matrix_t mb, matrix_t *mc)
{
    int r, c, i;
    // matrices are null?
    if (ma.rows == -1 || mb.rows == -1 || ma.columns == -1 || mb.rows == -1)
    {
        printf("Matrices cannot be empty\n"); // then exit function
        return;
    }
    // matrix a's column count must be equal to matrix b's row count
    if (ma.columns != mb.rows)
    {
        printf("Matrix dimensions don't agree\n"); // otherwise exit function
        return;
    }

    // Start process if there is no problem
    //  Call newMatrix and fill all the elements with zero in matrix C
    *mc = newMatrix(ma.rows, mb.columns, '0');

    // multiplication
    // A(r,0)×B(0,c) + A(r,1)×B(1,c) + A(r,columnsA-1)×B(columnsA-1,c)
    for (r = 0; r < ma.rows; r++)
    {
        for (c = 0; c < mb.columns; c++)
        {
            for (i = 0; i < ma.columns; i++)
            {
                mc->elements[r][c] += ma.elements[r][i] * mb.elements[i][c];
            }
        }
    }
}

matrix_t minorMatrix(matrix_t *m, int row, int column)
{
    matrix_t minor = {-1, -1, {
                                  NULL,
                              }};
    int r, c, mr, mc;

    // Check if the matrix has at least two rows and columns
    if (m->rows < 2 || m->columns < 2)
    {
        printf("Matrix must have at least two rows & columns\n");
        return minor; // Return empty matrix
    }

    // Check if the row and column are within the matrix's dimensions
    if (row < 0 || row >= m->rows || column < 0 || column >= m->columns)
    {
        printf("Row & column must be 0 up to %d & %d, respectively\n", m->rows, m->columns);
        return minor; // Return empty matrix
    }

    minor = newMatrix(m->rows - 1, m->columns - 1, '0');

    // Fill the minor matrix
    for (r = 0, mr = 0; r < m->rows; r++)
    {
        if (r == row)
            continue; // Skip the specified row and jump to next row(r++)

        for (c = 0, mc = 0; c < m->columns; c++)
        {
            if (c == column)
                continue; // Skip the specified column and jump to next col (c++)

            minor.elements[mr][mc] = m->elements[r][c];
            mc++;
        }

        mr++;
    }

    return minor;
}

float determinant(matrix_t *m)
{
    int r, c, sign;
    float det = 0;

    if (m->rows <= 0 || m->columns <= 0)
    {
        printf("Matrix cannot be empty\n");
        return;
    }

    if (m->rows != m->columns)
    {
        printf("Matrix must be square\n");
        return;
    }

    if (m->columns == 1 && m->rows == 1)
    {
        det = m->elements[0][0] + 0.000000;
    }
    else if (m->rows == 2 && m->rows == 2)
    {
        det = m->elements[0][0] * m->elements[1][1] - m->elements[0][1] * m->elements[1][0] + +0.000000;
    }
    else
    {
         for (c = 0; c < m->columns; c++)
        {
            matrix_t minor;
            minor = minorMatrix(m, 0, c);
            sign = c % 2 == 0 ? 1 : -1;
 
            det += sign * m->elements[0][c] * determinant(&minor) + 0.000000;
        }
    }
    printf("%1.2f:", det);
    return det;
}
