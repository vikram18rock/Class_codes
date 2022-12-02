#include <stdio.h>

//function declarations
//returns required element index
int lin_search(int *a, int n, int data);

int main()
{
    //variables
    int t, n, res;

    //input
    scanf("%d %d", &n, &t);
    int input[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &input[i]);
    }

    //search function
    res = lin_search(input, n, t);

    //print output
    printf("%d\n", res);

    return 0;
}

//definitions
int lin_search(int *a, int n, int data)
{
    // checking through the loop
    for(int i = 0; i < n; i++)
        if(a[i] == data)
            // return index if element is found 
            return i;
    
    // element not found
    return -1;
}
