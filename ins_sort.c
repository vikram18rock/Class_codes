#include <stdio.h>

void insert_sort(int a[], int n);

int main()
{
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    
    insert_sort(a, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}

void insert_sort(int a[], int n)
{
    int key, i, j;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        for (j = i-1; j >= 0 && a[j] < key; j--)
        {
            a[j+1] = a[j];
        }
        a[j+1] = key;
    }
}