#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node * ll;

struct stk
{
    // filled size of que
    int len;
    // head pointer
    ll head, tail;
};

typedef struct stk * q_ll;

ll create_node(int k)
{
    ll temp = (ll)malloc(sizeof(struct node));
    temp->data = k;
    temp->next = 0;

    return temp;
}

int queue_empty(q_ll q)
{
    if(q->head == 0)
        return 1;
    return 0;
}
void enqueue(q_ll q, int k)
{
    ll new = create_node(k);
    q->len++;
    if(q->head == 0)
    {
        q->head = new;
    }
    else
    {
        q->tail->next = new;
        q->tail = new;
    }
}
void dequeue(q_ll q)
{
    if(!(queue_empty(q)))
    {
        q->len--;
        ll temp = q->head;
        q->head = q->head->next;
        printf("%d ", temp->data);
        free(temp);
    }
    else
        printf("Empty ");
}

void print(q_ll q)
{
    ll temp;
    temp = q->head;
    while (temp != 0)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    if(q->head != 0)
    {
        printf("\n");
    }
}

int main()
{
    struct stk Q;
    q_ll q = &Q;
    q->head = 0;
    q->tail = 0;
    q->len = 0;

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
            enqueue(q, k);
            break;
        case 'd':
            scanf("%d", &k);
            for (int i = 0; i < k; i++)
            {
                dequeue(q);
            }
            printf("\n");
            break;
        case 'e':
            if(queue_empty(q))
                printf("YES\n");
            else
                printf("NO\n");
            break;
        case 't':
            return 0;
            break;
        default:
            break;
        }
    }
}
