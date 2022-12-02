#include <stdio.h>

//function declarations
//returns required element index
int binary_search(int *a, int n, int data);

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
    res = binary_search(input, n, t);

    //print output
    printf("%d\n", res);

    return 0;
}

//definitions
int binary_search(int *a, int n, int data)
{
    int mid, end1 = 0, end2 = n-1;

    //to mid element
    mid = (end1 + end2) / 2;

    //for not repeating back if element not found
    while(end1 <= end2)
    {
        //goes left
        if(data < a[mid])
        {
            //new end1 end2 and mid to go left
            end2 = mid - 1; 
            mid = (end1 + end2) / 2;
        }
        else if(data == a[mid])
        {
            //return the resultof search
            return mid;
        }
        else
        {
            //new end1 end2 and mid to go right side
            end1 = mid + 1;
            mid = (end1 + end2) / 2;
        }
    }
    //returning -1 if element is not found
    return -1;
}
