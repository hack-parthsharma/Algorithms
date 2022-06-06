//Program for Bubble Sort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, j, n, temp, flag = 1;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    while (flag)
    {
        flag = 0;
        for (i = 0; i < n - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                flag = 1;
            }
        }
    }
    printf("Sorted elements: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}