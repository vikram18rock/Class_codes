#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * next;
};

typedef struct node * ll;

struct stk
{
    // filled size of stack
    int len;
    // head pointer
    ll head;
};

typedef struct stk * s_ll;

ll create_node(int k)
{
    ll temp = (ll)malloc(sizeof(struct node));
    temp->data = k;
    temp->next = 0;

    return temp;
}

int stack_empty(s_ll s)
{
    if(s->head == 0)
        return 1;
    return 0;
}
void push(s_ll s, int k)
{
    ll new = create_node(k);
    s->len++;
    if(s->head == 0)
    {
        s->head = new;
    }
    else
    {
        new->next = s->head;
        s->head = new;
    }
}
void pop(s_ll s)
{
    if(!(stack_empty(s)))
    {
        s->len--;
        ll temp = s->head;
        s->head = s->head->next;
        printf("%d ", temp->data);
        free(temp);
    }
    else
        printf("Empty ");
}

void print(s_ll s)
{
    ll temp;
    temp = s->head;
    while (temp != 0)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    if(s->head != 0)
    {
        printf("\n");
    }
}

int main()
{
    struct stk S;
    s_ll s = &S;
    s->head = 0;
    s->len = 0;

    char choice;
    int k;

    ll newNode;
    while (1)
    {
        scanf("\n%c", &choice);
        switch (choice)
        {
        case 'i':
            scanf("%d", &k);
            push(s, k);
            break;
        case 'd':
            scanf("%d", &k);
            for (int i = 0; i < k; i++)
            {
                pop(s);
            }
            printf("\n");
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
        case 't':
            return 0;
            break;
        }
        //scanf("\n");
    }
}
