#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * prev;
    struct node * next;
};

struct LL
{
    struct node *head;
};

typedef struct node * node;
typedef struct LL * LL;

// creates a node with k as key
node create_node(int k);
// search list for node with data as k
node list_search(LL l, int k);
// inserts a node with k as key in front of list
void list_insert_front(LL l, int k);
// inserts a node with k as key in back of list
void list_insert_tail(LL l, int k);
//print all the keys in L in order, starting from the tail end after swapping the key values of xth node from the beginning and the yth node from the end.
void print_swap(LL l, int x, int y);

int main()
{
    struct LL L;
    L.head = 0;

    LL l = &L;

    int k, x, y;
    char choice;

    while (1)
    {
        scanf("%c", &choice);
        switch(choice)
        {
            case 'f':
                scanf("%d", &k);
                list_insert_front(l, k);
                break;
            case 't':
                scanf("%d", &k);
                list_insert_tail(l, k);
                break;
            case 'p':
                scanf("%d %d", &x, &y);
                print_swap(l, x, y);
                break;
            case 'e':
                return 0;
                break;
        }
    }
}

node create_node(int k)
{
    node new = (node) malloc(sizeof(struct node));
    new->data = k;
    new->next = 0;
    new->prev = 0;
    return new;
}
node list_search(LL l, int k)
{
    node temp = l->head;
    while (temp != 0)
    {
        if (temp->data == k)
        {
            return temp;
        }
        temp = temp->next;
    }
    return 0;
}
void list_insert_front(LL l, int k)
{
    node new = create_node(k);
    if (l->head == 0)
    {
        l->head = new;
        return;
    }
    else
    {
        l->head->prev = new; 
        new->next = l->head;
        l->head = new;
    }
}
void list_insert_tail(LL l, int k)
{
    node temp, new = create_node(k);
    temp = l->head;
    if (l->head == 0)
    {
        l->head = new;
        return;
    }
    else
    {
        while (temp->next != 0)
        {
            temp = temp->next;
        }
        temp->next = new;
        new->prev = temp;
    }
}
void print_swap(LL l, int x, int y)
{
    node nx, ny, tail, tempx, tempy;
    int i = 1, ctr = 1;
    if(l->head == 0)
    {
        printf("NULL\n");
        return;
    }
    // going to last of node
    tail = l->head;
    while(tail->next != 0)
    {
        ctr++;
        tail = tail->next;
    }

    if (x > ctr || y > ctr)
    {
        printf("NULL\n");
        return;
    }

    tempx = l->head;
    tempy = l->head;

    while(i < x)
    {
        tempx = tempx->next;
        i++;
    }
    i = 1;
    while (i < (ctr-y+1))
    {
        tempy = tempy->next;
        i++;
    }
    
    int temp;
    temp = tempy->data;
    tempy->data = tempx->data;
    tempx->data = temp;
    while (tail != 0)
    {
        printf("%d ", tail->data);
        tail = tail->prev;
    }
    printf("\n");
}