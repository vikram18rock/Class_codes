#include <stdio.h>
#include <stdlib.h>

// structs
// node
struct node
{
    char data;
    struct node* next;
};
// linked list
struct LL
{
    struct node* head;
};

// typedefs
typedef struct node* node;
typedef struct LL* LL;

// function declarations
// creates new node with k as key and next points to NULL. returns pointer to new node.
node create_node(char k);
// inserts node with k as the first node of l.
void list_insert_front(LL l, node x);
// inserts node with k as the last node of l.
void list_insert_tail(LL l,node x);
// deletes the first node from l and prints the deleted node’s k.
void list_delete_first(LL l);
// deletes the last node from l and prints the deleted node’s k.
void list_delete_last(LL l);
//prints the k values of all the nodes in l in order, starting from l.head.
void print_list(LL l);
// searches for the first occurrence of the key k in L by doing a simple linear search and, if found, returns the address of that node. If a node with key k is not present in the list, or if the list is empty, then the procedure returns the NULL pointer.
node list_search(LL l, char k);
// inserts a node with key k just after the first occurrence of the key n in L.
void list_insert_after(LL l, char k, char n);
// inserts a node with key k just before the first occurrence of the key n in L.
void list_insert_before(LL l, char k, char n); 
// deletes the node with key k from L and prints the key of the node next to thedeleted node. Prints LAST, if the deleted node was the last node of L.
void list_delete(LL l, char k);

int main()
{
    // initialise linked list
    struct LL L;
    L.head = 0;

    // ll pointer
    LL l;
    l = &L;

    // variables declarations
    char choice, k, n;

    node new;

    // looping until exit command
    while (1)
    {
        scanf("%c", &choice);
        // operations for corresponding cases
        switch (choice)
        {
            case 'f':
                scanf("\n%c", &k);
                new = create_node(k);
                list_insert_front(l,new);
                break;
            case 't':
                scanf("\n%c", &k);
                new = create_node(k);
                list_insert_tail(l,new);
                break;
            case 'i':
                list_delete_first(l);
                break;
            case 'l':
                list_delete_last(l);
                break;
            case 'a':
                scanf("\n%c %c", &k, &n);
                list_insert_after(l, k, n);
                break;
            case 'b':
                scanf("\n%c %c", &k, &n);
                list_insert_before(l, k, n);
                break;
            case 'd':
                scanf("\n%c", &k);
                list_delete(l, k);
                break;
            case 'p':
                print_list(l);
                break;
            case 'e':
                return 0;
                break;
        }
    }
    
}

node create_node(char k)
{
    node temp;
    
    // allocate memory using malloc()
    temp = (node)malloc(sizeof(struct node)); 
    
    if(temp == NULL)
        return 0;
    
    temp->data = k;
    // make next point to NULL
    temp->next = NULL;
    //return the new node
    return temp; 
}

void list_insert_front(LL l, node x)
{
    x->next = l->head;
    l->head = x;
}

void list_insert_tail(LL l,node x)
{
    node selected=l->head;
    if(selected != NULL)
    {
        while(selected->next != NULL)
            selected = selected->next;
        selected->next=x;
    }
    else
        l->head=x;
}

void list_delete_first(LL l)
{
    node selected = l->head;
    if(selected == NULL)
        printf("NULL\n");
    else
    {
        printf("%c\n", selected->data);
        l->head = l->head->next;
        free(selected);
    }
}

void list_delete_last(LL l)
{
    node selected = l->head;
    node previous = NULL;
    if(selected == NULL)
        printf("NULL\n");
    else
    {
        while(selected->next != NULL)
        {
            previous = selected;
            selected = selected->next;
        }
        printf("%c\n", selected->data);
        if(previous != NULL)
            previous->next = NULL;
        else
            l->head = NULL;
    }
    free(selected);
}
void print_list(LL l)
{
    node selected = l->head;
    if(selected == NULL)
    {
        printf("NULL\n");
        return;
    }

    while(selected != NULL)
    {
        printf("%c ", selected->data);
        selected = selected->next;
    }
    printf("\n");
}

node list_search(LL l, char k)
{
    node temp;
    temp = l->head;

    while (temp != 0)
    {
        if (temp->data == k)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void list_insert_after(LL l, char k, char n)
{
    node target, new;
    
    if(l->head == NULL)
    {
        printf("NULL\n");
        return;
    }
    target = list_search(l, n);

    if (target == 0)
    {
        printf("ABSENT\n");
        return;
    }
    
    new = create_node(k);

    new->next = target->next;
    target->next = new;
}

void list_insert_before(LL l, char k, char n) 
{
    node target, new, temp, prev;
    temp = l->head;

    if(temp == NULL)
    {
        printf("NULL\n");
        return;
    }
    target = list_search(l, n);
    if (target == 0)
    {
        printf("ABSENT\n");
        return;
    }

    new = create_node(k);
    prev = temp;
    while (temp != target)
    {
        prev = temp;
        temp = temp->next;
    }
    new->next= prev->next;
    prev->next = new;
}

void list_delete(LL l, char k)
{
    node temp, prev, target;    
    temp = l->head;
    if(temp == NULL)
    {
        printf("NULL\n");
        return;
    }

    target = list_search(l, k);

    if (target == NULL)
    {
        printf("ABSENT\n");
        return;
    }
    prev = temp;

    while (temp != target)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    if (temp == l->head)
    {
        l->head = temp->next;
    }
    
    if (temp->next == NULL)
    {
        printf("LAST\n");
        free(temp);
        return;
    }
    printf("%c\n", prev->next->data);
    free(temp);
}