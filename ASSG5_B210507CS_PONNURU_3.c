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
// search list for node with k
node list_search(LL l, int k);
// inserts a node with k as key in front of list
void list_insert_front(LL l, int k);
// inserts a node with k as key in back of list
void list_insert_tail(LL l, int k);
// inserts a node with k as key in list after node with data x
void list_insert_after(LL l, int k, int x);
// inserts a node with k as key in list before node with data x
void list_insert_before(LL l, int k, int x);
// deletes a node with k as key
void list_delete(LL l, int k);
// deletes last node of list
void list_delete_last(LL l);
// deletes first node of list
void list_delete_first(LL l);
// print from node with x as data to head in reverse order as original
void print_reverse(LL l, int x);
int main()
{
    struct LL L;
    L.head = 0;

    LL l = &L;

    int k, x;
    char choice;

    while (1)
    {
        scanf("%c", &choice);
        switch(choice)
        {
            case 'f':
                scanf("%d", &k);
                create_node(k);
                list_insert_front(l, k);
                break;
            case 't':
                scanf("%d", &k);
                list_insert_tail(l, k);
                break;
            case 'a':
                scanf("%d %d", &k, &x);
                list_insert_after(l, k, x);
                break;
            case 'b':
                scanf("%d %d", &k, &x);
                list_insert_before(l, k, x);
                break;
            case 'd':
                scanf("%d", &k);
                list_delete(l, k);
                break;
            case 'l':
                list_delete_last(l);
                break;
            case 'i':
                list_delete_first(l);
                break;
            case 'r':
                scanf("%d", &x);
                print_reverse(l, x);
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
void list_insert_after(LL l, int k, int x)
{
    if (l->head == 0)
    {
        printf("NULL\n");
        return;
    }
    node new, temp;
    temp = list_search(l, x);
    if(temp == 0)
    {
        printf("ABSENT\n");
        return;
    }
    new = create_node(k);
    if (temp->next != 0)
        temp->next->prev=new;
    new->next = temp->next;
    temp->next = new;
    new->prev = temp;
}
void list_insert_before(LL l, int k, int x)
{
    if (l->head == 0)
    {
        printf("NULL\n");
        return;
    }
    node new, temp;
    temp = list_search(l, x);
    if(temp == 0)
    {
        printf("ABSENT\n");
        return;
    }
    new = create_node(k); 
    new->prev = temp->prev;
    new->next = temp;
    if (temp->prev != 0)
    {
        temp->prev->next = new;
    }
    temp->prev = new;
}
void list_delete(LL l, int k)
{
    if(l->head == 0)
    {
        printf("NULL\n");
        return;
    }
    node temp = list_search(l, k);
    if(temp == 0)
    {
        printf("ABSENT\n");
        return;
    }
    if (temp == l->head)
    {
        printf("FIRST\n");
        free(temp);
        if(l->head->next != 0)
        {
            l->head = l->head->next;
            l->head->prev = 0;
        }
        else
        {
            l->head = 0;
        }
        return;
    }
    temp->prev->next = temp->next;
    printf("%d\n", temp->prev->data);
    free(temp);
}
void list_delete_last(LL l)
{
    if(l->head == 0)
    {
        printf("NULL\n");
        return;
    }

    node temp = l->head;

    while (temp->next != 0)
    {
        temp = temp->next;
    }
    temp->prev->next = 0;
    printf("%d\n", temp->data);
    free(temp);
}
void list_delete_first(LL l)
{
    if(l->head == 0)
    {
        printf("NULL\n");
        return;
    }
    printf("%d\n",l->head->data);
    l->head = l->head->next;
    free(l->head->prev);
    l->head->prev = 0;
}
void print_reverse(LL l, int x)
{
    node temp = list_search(l, x);
    if(l->head == 0)
    {
        printf("NULL\n");
        return;
    }
    if(temp == 0)
    {
        printf("ABSENT\n");
        return;
    }
    while (temp != 0)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
