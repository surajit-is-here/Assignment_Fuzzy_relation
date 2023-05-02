#include<stdio.h>
#include<stdlib.h>

int **mem_alloc_2D(int r, int c);
void input(int r, int c, int **a);
void print(int r, int c, int **a);

int **mem_alloc_2D(int r, int c)
{
    int i, **D;
    D = (int **)calloc(r, sizeof(int *));
    for (i = 0; i < r; i++)
        D[i] = (int *)calloc(c, sizeof(int));
    if (D == NULL)
    {
        printf("Memory not allocated.");
        exit(0);
    }
    return D;
}
void input(int r, int c, int **a)
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("Enter the value of a[%d][%d]", i, j);
            scanf("%d", &a[i][j]);
            if (a[i][j] != 0 && a[i][j] != 1)
            {
                printf("Input should be either 0 or 1\n");
                j--;
            }
        }
    }
}
void print(int r, int c, int **a)
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            printf("%d\t", a[i][j]);
        printf("\n");
    }
}
