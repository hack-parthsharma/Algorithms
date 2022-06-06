//Implement program for matrix chain multiplication in C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int matrix_chain_multiplication(int p[], int n)
{
    int i, j, k, l, q, r, s, t, u, v, w, x, y, z;
    int m[n][n];
    for (i = 1; i < n; i++)
        m[i][i] = 0;
    for (l = 2; l < n; l++)
    {
        for (i = 1; i < n - l + 1; i++)
        {
            j = i + l - 1;
            m[i][j] = 1000000;
            for (k = i; k < j; k++)
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
    return m[1][n - 1];
}
int main()
{
    int i, j, k, n, temp;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int p[n];
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &p[i]);
    printf("Minimum number of multiplications is %d", matrix_chain_multiplication(p, n));
    return 0;
}