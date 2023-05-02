#include <stdio.h>
#include <stdlib.h>

float **mem_alloc_2D(int, int);
void input(int, int, float **a);
void print(int, int, float **a);

float **mem_alloc_2D(int r, int c)
{
    int i;
    float **D;
    D = (float **)calloc(r, sizeof(float *));
    for (i = 0; i < r; i++)
        D[i] = (float *)calloc(c, sizeof(float));
    if (D == NULL)
    {
        printf("Memory not allocated.");
        exit(0);
    }
    return D;
}
void input(int r, int c, float **a)
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("Enter the value of a[%d][%d]", i, j);
            scanf("%f", &a[i][j]);
            if (a[i][j] < 0 || a[i][j] > 1)
            {
                printf("Input should lie between 0 and 1\n");
                j--;
            }
        }
    }
}
void print(int r, int c, float **a)
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            printf("%f\t", a[i][j]);
        printf("\n");
    }
}