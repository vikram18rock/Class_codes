#include <stdio.h>

struct P
{
    char c[4];
    int a;
    int o;
};

void read(struct P p[], int n);
int reduce(struct P p[], int n);
void find_winners(struct P p[], int n);
void q_sort(struct P p[], int s, int e);
int part(struct P p[], int s, int e);
void swap(struct P*a, struct P*b);

int main()
{
    int n;
    scanf("%d", &n);

    struct P p[n];
    
    read(p, n);

    find_winners(p, n);
    return 0;
}

void read(struct P p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%s", p[i].c);
        scanf("%d", &p[i].a);
        p[i].o = i;
    }
    q_sort(p, 0, n-1);
}

void q_sort(struct P p[], int s, int e)
{
    // position of sorted element
    int q;

    // executes it part is not sorted already
    if (s < e)
    {
        //t part function returns q
        q = part(p, s, e);

        // sort part left to element
        q_sort(p, s, q-1);

        // sort part right to element
        q_sort(p, q+1, e);

        // NOTE we are excluding sorted element
    }
}
int part(struct P p[], int s, int e)
{
    // storing in temp because the pivot can be swapped at last of prog
    int x = p[e].a;

    //starting from out side ot part
    int j = s-1;

    // going through tht part
    for (int i = s; i <= e; i++)
    {
        if(p[i].a >= x)
        {
            // increment  and swap
            j++;
            if(i != j)
            swap(&p[i], &p[j]);
        }
    }
    // returns sorted element pos
    return j;
}

// call by reference swapping
void swap(struct P*a, struct P*b)
{
    struct P temp;
    temp = *b;
    *b = *a;
    *a = temp;
}
int reduce(struct P p[], int n)
{
    if(p[n-2].a == p[n-1].a && n > 1)
    {
        if(p[n-2].o > p[n-1].o)
        {
            swap(&p[n-2], &p[n-1]);
        }
    }
    if (n > 2)
    {
        p[n-2].a += p[n-1].a;
        printf("%s %s %d\n", p[n-2].c, p[n-1].c, p[n-2].a);
    }
    n--;
    q_sort(p, 0, n-1);
    return n;
}
void find_winners(struct P p[], int n)
{
    while(n > 1)
    {
        n = reduce(p, n);
    }
    printf("%s %d\n", p[0].c, p[0].a);
    printf("%s %d\n", p[1].c, p[1].a);
}
