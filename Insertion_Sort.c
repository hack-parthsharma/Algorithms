//Implement Insertion Sort in C 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int insertion_sort(int a[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        temp = a[i];
        for (j = i - 1; j >= 0 && a[j] > temp; j--)
            a[j + 1] = a[j];
        a[j + 1] = temp;
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
    insertion_sort(a, n);
    printf("Sorted elements: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}
