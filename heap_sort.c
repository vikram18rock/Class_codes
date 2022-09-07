#include<stdio.h>

// function declarations
void swap(int* a, int* b);
void build_max_heap(int a[], int s, int e);
void max_heapify(int a[], int s, int e);
void heap_sort(int a[], int n);

int main()
{
    // n - array size
    int n;
    scanf("%d", &n);

    // array declaration , input
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // heap_sorting the array
    heap_sort(a, n);

    // print sorted order
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}

void heap_sort(int a[], int n)
{
    // buid max heap from the random array
    build_max_heap(a, 0, n-1);

    // continuously swap root with last unsorted element
    // unsorted means not in it's specified position as in sorted

    // one by one from last
    for (int i = n-1; i >= 0; i--)
    {
        // swapping
        swap(&a[0], &a[i]);
        // decreasing the size so that exchanged element remains sorted
        // heapify the new array from root
        max_heapify(a, 0, i-1);
    }
}

// max heap every node
// s - index of node, e- size of array
void max_heapify(int a[], int s, int e)
{
    // left child
    int l = 2*s + 1;
    //right child
    int r = 2*s + 2;

    // assuming parent is larger for comparing the largest
    int lar = s;

    // updating largest without swapping  
    if ((a[l] > a[lar]) && (l <= e))
    {
        lar = l;
    }
    // comparing the current largest with right
    if ((a[r] > a[lar]) && (r <= e))
    {
        lar = r;
    }
    // if any of childs is largest
    if (lar != s)
    {
        // swap child with parent
        swap(&a[s], &a[lar]);
        //heapify the sub tree that goes on
        max_heapify(a, lar, e);
    }
}

void build_max_heap(int a[], int s, int e)
{
    // heapify startin from non leafs to 1st node(0)
    for(int i = (e-1)/2; i >= s; i--)
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