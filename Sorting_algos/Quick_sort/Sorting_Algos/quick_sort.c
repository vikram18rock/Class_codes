#include<stdio.h>

void swap(int*a, int*b);
void quick_sort(int arr[], int s, int e);
int partition(int arr[], int s, int e);

int main()
{
    int n;
    scanf("%d", &n);

    // array dec, input
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    quick_sort(arr, 0, n-1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

void quick_sort(int arr[], int s, int e)
{
    // position of sorted element
    int q;

    // executes if partition is not sorted already
    if (s < e)
    {
        // partition function returns q
        q = partition(arr, s, e);

        // sort partition left to element
        quick_sort(arr, s, q-1);

        // sort partition right to element
        quick_sort(arr, q+1, e);

        // NOTE we are excluding sorted element
    }
}
int partition(int arr[], int s, int e)
{
    // storing in temp because the pivot can be swapped at last of prog
    int x = arr[e];

    //starting from out side of partition
    int j = s-1;

    // going through the partition
    for (int i = s; i <= e; i++)
    {
        if(arr[i] <= x)
        {
            // increment  and swap
            j++;
            // optimisation
            // won't swap if the element is comparing itself
            if(i != j)
            {
                swap(&arr[i], &arr[j]);
            }
        }
    }
    // returns sorted element pos
    return j;
}

// call by reference swapping
void swap(int*a, int*b)
{
    int temp;
    temp = *b;
    *b = *a;
    *a = temp;
}
