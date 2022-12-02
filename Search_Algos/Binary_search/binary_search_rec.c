#include <stdio.h>

// Recursive approach for binary search
int binary_search(int a[], int s, int e, int key)
{
    // if the list passed down is empty
    if(s > e)
        // -1 because no.s greater are indices
        return -1;

    // find the middle element
    int mid = (s + e) / 2;

    // if the a[mid] is the key
    if(a[mid] == key)
        return mid;
    else if(key > a[mid])
        // search in the right half
        return binary_search(a, mid + 1, e, key);
    else
        // search in the left half
        return binary_search(a, s, mid - 1, key);
}

int main()
{
    int n;
    scanf("%d", &n);

    int a[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int key;
    scanf("%d", &key);

    int index = binary_search(a, 0, n - 1, key);

    printf("%d\n", index);
}
