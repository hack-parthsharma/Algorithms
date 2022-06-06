//Implement Radix Sort in C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int radix_sort(int a[], int n)
{
    int i, j, k, m, exp = 1, temp;
    int b[n];
    for (m = 0; m < n; m++)
    {
        for (i = 0; i < n; i++)
        {
            b[i] = 0;
        }
        for (i = 0; i < n; i++)
        {
            j = a[i] / exp;
            b[j]++;
        }
        for (i = 1; i < n; i++)
        {
            b[i] += b[i - 1];
        }
        for (i = n - 1; i >= 0; i--)
        {
            j = a[i] / exp;
            b[j]--;
            a[b[j]] = a[i];
        }
        exp *= 10;
    }
}
int main()
{
    int i, j, n, temp;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    radix_sort(a, n);
    printf("Sorted elements: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}