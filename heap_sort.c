#include<stdio.h>

// function declarations
void swap(int* a, int* b);
void build_max_heap(int a[], int s, int e);
void max_heapify(int a[], int s, int e);
void heap_sort(int a[], int n);

int main()
{
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    heap_sort(a, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}

void heap_sort(int a[], int n)
{
    build_max_heap(a, 0, n-1);
    for (int i = n-1; i >= 0; i--)
    {
        swap(&a[0], &a[i]);
        max_heapify(a, 0, i-1);
    }
}
void max_heapify(int a[], int s, int e)
{
    int l = 2*s + 1;
    int r = 2*s + 2;

    int lar = s;

    if ((a[l] > a[lar]) && (l <= e))
    {
        lar = l;
    }
    if ((a[r] > a[lar]) && (r <= e))
    {
        lar = r;
    }
    if (lar != s)
    {
        swap(&a[s], &a[lar]);
        max_heapify(a, lar, e);
    }
}

void build_max_heap(int a[], int s, int e)
{
    for(int i = e/2 - 1; i >= s; i--)
    {
        max_heapify(a, i, e);
    }
}

void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}