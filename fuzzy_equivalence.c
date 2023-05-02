#include <stdio.h>
#include <stdlib.h>
#include "fuzzy_header.h"

int reflexive(int, float **);
int symmetric(int, float **);
int transitive(int, float **);

int main()
{
    int r1, c1, x, y, z;
    float **a;
    printf("Enter the order of the matrix:\t");
    scanf("%d %d", &r1, &c1);
    if (r1 != c1)
    {
        printf("It is not a square matrix\n");
        return -1;
    }
    a = mem_alloc_2D(r1, c1);
    printf("Enter the elements of the matrix:\n");
    input(r1, c1, a);
    printf("The matrix is:\n");
    print(r1, c1, a);
    x = reflexive(r1, a);
    y = symmetric(r1, a);
    z = transitive(r1, a);
    if (x == 1 && y == 1 && z == 1)
        printf("The fuzzy relation is equivalence\n");
    else
        printf("So the fuzzy relation is not equivalence\n");
}
int reflexive(int n, float **a)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i][i] != 1.0)
        {
            printf("Fuzzy relation is not reflexive\n");
            return -1;
        }
    }
    return 1;
}
int symmetric(int n, float **a)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != a[j][i])
            {
                printf("Fuzzy relation is not symmetric\n");
                return -1;
            }
        }
    return 1;
}
int transitive(int n, float **a)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
            {
                if (a[i][j] && a[j][k] && !a[i][k])
                {
                    printf("Fuzzy relation is not transitive\n");
                    return -1;
                }
            }
    return 1;
}