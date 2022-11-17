#include <stdio.h>
#include <stdlib.h>

// node
struct node
{
    // data of node
    char data;
    // next node pointer
    struct node * next;
};

// linked list struct
struct LL
{
    // head
    struct node* head;
};

// type def
typedef struct node node;

typedef struct LL * LL;

// head of list
node* head = 0;

// creates a new node with k as the k, and next points to NULL. returns a pointer to the new node.
node* create_node(char k);
// inserts a node with k as the first node of l.
void list_insert_front(LL l, node* x);
// inserts a node with k as the last node of l.
void list_insert_tail(LL l,node* x);
// deletes the first node from l and prints the deleted node’s k.
void list_delete_first(LL l);
// deletes the last node from l and prints the deleted node’s k.
void list_delete_last(LL l);
//prints the k values of all the nodes in l in order, starting from l.head.
void print_list(LL l);

int main()
{
    // variable declarations
    char k, choice;
    node* new;
    struct LL L;
    L.head = 0;
    LL l = &L;

    // looping operations
    while(1)
    {
        // choice input
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
            case 'p':
                print_list(l);
                break;
            case 'e':
                return 0;
                break;
        }
    }
}

node* create_node(char k)
{
    node* temp;
    
    // allocate memory using malloc()
    temp = (node*)malloc(sizeof(struct node)); 
    
    if(temp == NULL)
        return 0;
    
    temp->data = k;
    // make next point to NULL
    temp->next = NULL;
    //return the new node
    return temp; 
}

void list_insert_front(LL l, node* x)
{
    x->next = l->head;
    l->head = x;
}

void list_insert_tail(LL l,node* x)
{
    node* selected=l->head;
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
    node* selected = l->head;
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
    node* selected = l->head;
    node* previous = NULL;
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
    node* selected = l->head;
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
