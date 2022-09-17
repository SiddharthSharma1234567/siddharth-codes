//Given a list of integers, find out the number that has the highest frequency.

#include <stdio.h>
#include <stdlib.h>
int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int a[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        qsort(a, n, sizeof(int), cmpfunc);
        int count1 = 0, key = a[0], x;
        // 2 2 2 3 4 4 5
        for (int i = 0; i < n; i++)
        {
            int count=0;
            if (i == 0)
            {
                for (int j = 0; j < n; j++)
                {
                    if (a[j] == key)
                    {
                        count++;
                    }
                }
            }
            else
            {
                if (a[i] != a[i - 1])
                {
                    key = a[i];
                    for (int j = 0; j < n; j++)
                    {
                        if (a[j] == key)
                        {
                            count++;
                        }
                    }
                }
            }
            if (count > count1)
            {
                count1 = count;
                x = a[i];
            }
        }
        printf("%d\n", x);
    }
    return 0;
}