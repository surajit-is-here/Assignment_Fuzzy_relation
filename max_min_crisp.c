#include <stdio.h>
#include <stdlib.h>
#include "crisp_header.h"


void crisp(int r, int c1, int c2, int **P, int **Q, int **R);

int main()
{
    int r1, c1, r2, c2;
    int **A, **B, **C;
    printf("Enter the order of the first matrix:\t");
    scanf("%d %d", &r1, &c1);
    printf("Enter the order of second matrix:\t");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2)
    {
        printf("Invalid case");
        exit(0);
    }
    A = mem_alloc_2D(r1, c1);
    B = mem_alloc_2D(r2, c2);
    C = mem_alloc_2D(r1, c2);
    printf("\nEnter the elements of matrix A:\n");
    input(r1, c1, A);
    printf("\nEnter the elements of matrix B:\n");
    input(r2, c2, B);

    printf("\nMatrix A=\n");
    print(r1, c1, A);
    printf("\nMatrix B=\n");
    print(r2, c2, B);
    printf("\nResultant crisp matrix :\n");
    crisp(r1, c1, c2, A, B, C);
    print(r1, c2, C);
}

void crisp(int r, int c1, int c2, int **P, int **Q, int **R)
{
    int i, j, k;
    float *temp;
    temp = (float *)calloc(c1, sizeof(float));
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c2; j++)
        {
            for (k = 0; k < c1; k++)
            {
                temp[k] = P[i][k] < Q[k][j] ? P[i][k] : Q[k][j];
            }

            R[i][j] = temp[0];
            for (k = 1; k < c1; k++)
            {
                R[i][j] = R[i][j] > temp[k] ? R[i][j] : temp[k];
            }
        }
    }
}