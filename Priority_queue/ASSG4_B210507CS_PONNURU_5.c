#include <stdio.h>

// global variable for no. of processes
int len = 0;

void swap(int* a, int* b);
void build_min_heap(int Q[]);
void min_heapify(int Q[], int i);
void Insert_Process (int Q[], int k);
// Inserts a new process with priority k into Q.
void Extract_Next_Process (int Q[]);
// Return the priority of the process to be scheduled next and remove it from Q.
void Get_Next_Process (int Q[]);
// Return the priority of the process to be scheduled next, from Q without removing it.
void Change_Priority (int Q[], int k, int x);
// Change a process’s priority from old value k to new value x in Q.
void Display_Queue(int Q[]);
// Display all priority of processes in Q in their scheduling order without changing Q.

int main()
{
    // in- input type
    char in;
    // array for all processes
    int Q[1000];
    // change of priority of element
    // k - elemnt, x - new priority
    int k, x;

    // repeated looping until in is s
    do
    {
        scanf("%c", &in);
        switch (in)
        {
        case 'i':
            Insert_Process (Q, k);
            break;
        
        case 'e':
            Extract_Next_Process (Q);
            break;
        
        case 'm':
            printf("%d\n", Q[0]);
            break;
        
        case 'c':
            scanf("%d", &k);
            scanf("%d", &x);
            Change_Priority (Q, k, x);
            break;
        
        case 'd':
            Display_Queue(Q);
            break;
        
        default:
            break;
        }
            //Get_Next_Process (Q);
    }
    while (in != 's');
    
}

// inserts new process
void Insert_Process (int Q[], int k)
{
    len++;
    scanf("%d", &Q[len-1]);
    // min heap because the highest prior is at last
    build_min_heap(Q);
}

// display current queue
void Display_Queue(int Q[])
{
    // printing if the len of q is +ve
    if(len > 0)
    {
        for (int i = 0; i < len; i++)
        {
            printf("%d ", Q[i]);
        }
        printf("\n");
    }
    // else no display
    else
    {
        printf("-1\n");
    }
}

// updating priority
void Change_Priority (int Q[], int k, int x)
{
    // required index search
    int i, flag;
    // if updated priority is same
    if(k == x)
    {
        return;
    }
    // finding the index of process
    for (i = 0; i < len; i++)
    {
        if(Q[i] == k)
        {
            Q[i] = x;
            break;
        }
    }
    // if priority is higher
    if(k < x)
    {
        // build min heap for that node
        min_heapify(Q, i);
        return;
    }
    
    // swapping with parent and updating
    while (i > 0 && Q[i] < Q[(i-1)/2])
    {
        swap(&Q[i], &Q[(i-1)/2]);
        i = (i-1)/2;
    }
}

// for next process
void Get_Next_Process (int Q[])
{
    // next least priority is at first since min heap
    printf("%d\n", Q[0]);
}

void Extract_Next_Process (int Q[])
{
    // if no queue
    if(len==0)
    {
        printf("-1\n");
        return;
    }
    if(len > 0)
    {
        printf("%d\n", Q[0]);
        // decreasing len of queue
        len--;
        // copy last element in root
        Q[0] = Q[len];
        // heapify from root
        min_heapify(Q, 0);
    }
}

void min_heapify(int Q[], int i)
{
    // left child 
    int l = 2 * i + 1;
    // right child
    int r = 2 * i + 2;

    // comparisons for lowest of node
    int low = i;

    if(Q[l] < Q[low] && l < len)
    {
        low = l;
    }
    if(Q[r] < Q[low] && r < len)
    {
        low = r;
    }
    // if lowest is not parent
    if(low != i)
    {
        // swap and proceed process again 
        swap(&Q[low], &Q[i]);
        min_heapify(Q, low);
    }
}

// building min heap
void build_min_heap(int Q[])
{
    for (int i = len/2 -1; i >= 0; i--)
    {
        min_heapify(Q, i);
    }
}

// swapping with call by reference
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}