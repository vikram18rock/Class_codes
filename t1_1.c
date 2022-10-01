#include <stdio.h>

// Function declarations
int search(int A[], int t, int n);

int main()
{
    int n1, n2, n3;
    scanf("%d %d %d", &n1, &n2, &n3);

    int s[n1], a[n2], b[n3];
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &s[n1]);
    }
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &a[n2]);
    }
    for (int i = 0; i < n3; i++)
    {
        scanf("%d", &b[n3]);
    }

    for (int i = 0; i < n2; i++)
    {
        if(search(b, a[i], n3))
            continue;
        else
            printf("%d ", a[i]);
    }
    for (int i = 0; i < n3; i++)
    {
        if(search(a, b[i], n2))
            continue;
        else
            printf("%d ", b[i]);
    }
    for (int i = 0; i < n1; i++)
    {
        if(search(a, b[i], n2))
            printf("%d ", b[i]);
    }
    printf("\n");

    int flag = 0;
    for (int i = 0; i < n1; i++)
    {
        if (search(a, s[i], n2) || search(b, s[i], n3))
        {
            continue;
        }
        else
        {
            printf("%d ", s[i]);
            flag = 1;
        }
    }
    printf("\n");
    if(flag == 0)
    {
        printf("-1\n");
    }
}
//returns true if element is found in array A else returns false
int search(int A[], int t, int n)
{
    for (int i = 0; i < n; i++)
       if(t == A[i])
           return 1;
    return 0;
}