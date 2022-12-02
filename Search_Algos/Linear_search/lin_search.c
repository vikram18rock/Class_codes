#include <stdio.h>

int search_list(int a[], int len, int key)
{
    // decrease the index
    len--;

    // if the list is over
    if(len < 0)
        return len;
    // list is not done and we found key
    if(a[len] == key)
    {
        // return the found index
        return len;
    }
    // key not found, then search remaining array
    search_list(a, len, key);
}

int main()
{
    int n;
    // size of input array
    scanf("%d", &n);

    int a[n];
    // take input array
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int k;
    scanf("%d", &k);

    // print search result
    printf("%d\n",search_list(a, n, k));

    return 0;
}