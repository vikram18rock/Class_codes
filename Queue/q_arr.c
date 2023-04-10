#include <stdio.h>
#include <stdlib.h>

struct q
{
    int *arr, head, tail, len;
};

typedef struct q * q;

int queue_empty(q q_ar)
{
    if(q_ar->head == -1)
    {
        return 1;
    }
    return 0;
}

int queue_full(q q_ar)
{
    if((q_ar->head - q_ar->tail == 1) || (q_ar->tail - q_ar->head == q_ar->len - 1))
    {
        return 1;
    }
    return 0;
}

void enqueue(q q_ar, int k)
{
    if(!(queue_full(q_ar)))
    {
        if (q_ar->head == -1)
        {
            q_ar->head = 0;
        }
        q_ar->tail = ((q_ar->tail + 1) % q_ar->len);
        q_ar->arr[q_ar->tail] = k;
        if (queue_full(q_ar))
        {
            printf("Full\n");
        }
    }
    else
        printf("Full\n");
}

void dequeue(q q_ar)
{
    if (!(queue_empty(q_ar)))
    {
        printf("%d ", q_ar->arr[q_ar->head]);
        if (q_ar->head == q_ar->tail)
        {
            q_ar->head = -1;
            q_ar->tail = -1;
        }
        else
        {
            q_ar->head = (q_ar->head + 1) % q_ar->len;
        }
    }
    else
        printf("Empty ");
}

int main()
{
    int n;
    struct q Q;
    q q_ar = &Q;

    scanf("%d", &q_ar->len);

    q_ar->arr = (int*)malloc(q_ar->len * sizeof(int));
    q_ar->head = -1;
    q_ar->tail = -1;

    char choice;
    int k;

    while (1)
    {
        scanf("\n%c", &choice);
        switch (choice)
        {
            case 'i':
                scanf("%d", &k);
                enqueue(q_ar, k);
                
                break;
            case 'd':
                scanf("%d", &k);
                for (int i = 0; i < k; i++)
                {
                    dequeue(q_ar);
                }
                printf("\n");
                break;
            case 'e':
                if (queue_empty(q_ar))
                    printf("Yes\n");
                else
                    printf("No\n");
                break;
            case 'f':
                if (queue_full(q_ar))
                    printf("Yes\n");
                else
                    printf("No\n");
                break;
            case 't':
                return 0;
        }
    }
}
