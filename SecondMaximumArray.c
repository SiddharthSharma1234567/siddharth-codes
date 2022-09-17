#include <stdio.h>
#include <stdlib.h>
int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
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
    qsort(a, n, sizeof(int), cmpfunc);
    int max = a[0];
    int second_max = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            continue;
        }
        else
        {
            if (a[i] > max)
            {
                second_max = max;
                max = a[i];
            }
        }
    }
    printf("%d", second_max);
    return 0;
}