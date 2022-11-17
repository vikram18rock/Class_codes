#include <stdio.h>
#include <stdlib.h>

struct stk
{
    int* arr;
    int top;
    int size;
};

// s-arr -> stk implementation in array
typedef struct stk * sarr;

int stack_full(sarr s)
{
    if(s->top == s->size - 1)
        return 1;
    else
        return 0;
}

int stack_empty(sarr s)
{
    if(s->top == -1)
        return 1;
    else
        return 0;
}

void push(sarr s, int k)
{
    if(!(stack_full(s)))
    {
        s->top++;
        s->arr[s->top] = k;
    }
    else
        printf("FULL\n");
}

int pop(sarr s)
{
    if(!(stack_empty(s)))
    {
        s->top--;
        printf("%d ", s->arr[s->top+1]);
    }
    else
        printf("Empty ");
    return 0;
}

void print(sarr s)
{
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

int main()
{

    struct stk S;
    sarr s;
    s = &S;
    scanf("%d", &s->size);

    s->arr = (int*)malloc(s->size * sizeof(int));
    s->top = -1;

    char choice;
    int k;
    while (1)
    {
        scanf("\n%c", &choice);
        switch (choice)
        {
            case 'i':
                scanf("%d", &k);
                push(s, k);
                break;
            case 't':
                return 0;
                break;
            case 'd':
                scanf("%d", &k);
                for (int i = 0; i < k; i++)
                {
                    pop(s);
                }
                printf("\n");
                break;
            case 'f':
                if (stack_full(s))
                    printf("YES\n");
                else
                    printf("NO\n");
                break;
            case 'e':
                if(stack_empty(s))
                    printf("YES\n");
                else
                    printf("NO\n");
                break;
            case 'p':
                print(s);
                break;
        }
    }
    return 0;
}
