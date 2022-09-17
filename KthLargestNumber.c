// Write a method called kthLargest that accepts an integer k and an array arr as
// its parameters and returns the element such that k elements have greater or 
// equal value. If k = 0, return the largest element; if k = 1, return the 
// second largest element, and so on.

#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
int kthLargest(int arr[], int size, int k)
{
    qsort(arr, size, sizeof(int), cmpfunc);
    for (int i = 0; i < size / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
    for (int i = 0; i < size; i++)
    {
        if (i == k)
        {
            return arr[i];
            break;
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int k;
    scanf("%d", &k);
    int x = kthLargest(a, n, k);
    printf("%d", x);
}