//Implement quick sort in c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int quick_sort(int a[], int low, int high)
{
    int i, j, pivot, temp;
    pivot = a[low];
    i = low;
    j = high;
    while (i < j)
    {
        while (a[i] <= pivot && i < j)
            i++;
        while (a[j] > pivot)
            j--;
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    a[low] = a[j];
    a[j] = pivot;
    if (low < j - 1)
        quick_sort(a, low, j - 1);
    if (high > j + 1)
        quick_sort(a, j + 1, high);
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
    quick_sort(a, 0, n - 1);
    printf("Sorted elements: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}
