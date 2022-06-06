//User defined function for binomial coefficient
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binomial_coefficient(int n, int k)
{
    int i, j, C[n + 1][k + 1];
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= min(i, k); j++)
        {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    return C[n][k];
}
int main()
{
    int i, j, n, k, temp;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the number of elements to be printed: ");
    scanf("%d", &k);
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= min(i, k); j++)
        {
            printf("%d ", binomial_coefficient(i, j));
        }
        printf("\n");
    }
    return 0;
}