#include <stdio.h>

void merge_sort(int a[], int s, int e);
void merge(int a[], int s, int m, int e);

int main()
{
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    
    merge_sort(a, 0, n-1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}

void merge_sort(int a[], int s, int e)
{
    int m;
    if (s < e)
    {
        m = (s + e)/2;
        merge_sort(a, s, m);
        merge_sort(a, m+1, e);
        merge(a, s, m, e);
    }
}
void merge(int a[], int s, int m, int e)
{
    int n1 = m-s+1;
    int n2 = e-m;

    int l[n1+1], r[n2+1];

    for (int i = 0; i < n1; i++)
    {
        l[i] = a[s + i];
    }
    for (int i = 0; i < n2; i++)
    {
        r[i] = a[m + i + 1];
    }
    l[n1] = 10000;
    r[n2] = 10000;
    int i = 0, j = 0;
    for(int k = s; k <= e; k++)
    {
        if (l[i] < r[j])
        {
            a[k] = l[i];
            i++;
        }
        else
        {
            a[k] = r[j];
            j++;
        }
    }
}
