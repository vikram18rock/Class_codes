// code for evaluating postfix
#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int top;
    int arr[100];
};
typedef struct stack * stack;

// operate - returns corresp. operations
int operate(char ch, int op1, int op2)
{
    switch (ch)
    {
    case '+':
        return (op1 + op2);
    case '-':
        return (op1 - op2);
    case '*':
        return (op1 * op2);
    case '/':
        return (op1 / op2);
    }
}

// checks for integers
int operand(char ch)
{
    if(ch >= '0' && ch <= '9')
        return 1;
    else
        return 0;
}

// adds elements to stack
void push(stack s, int key)
{
    if (s->top < 99)
    {
        s->top++;
        s->arr[s->top] = key;
    }
    if(s->top == 99)
    {
        printf("FULL\n");
    }
}

// removes last in element
int pop(stack s)
{
    if (s->top >= 0)
    {
        s->top--;
        return s->arr[s->top + 1];
    }
    else
        printf("Empty\n");
}

// if it's operator gets the full number
int getNextToken(char* exp, int* i)
{
    int key = 0;
    for (; exp[*i] != ' '; (*i)++)
    {
        key = 10 * key + exp[*i] - '0';
    }
    return key;
}

// evaluating the expression using postfix
int evaluatePostfix(stack s, char* exp)
{
    int i, op1, op2, op;
    for (i = 0; exp[i] != '\0'; i++)
    {
        if(operand(exp[i]))
        {
            int key = getNextToken(exp, &i);
            push(s, key);
        }
        else if(exp[i] != ' ')
        {
            op2 = pop(s);
            op1 = pop(s);
            op = operate(exp[i], op1, op2);
            push(s, op);
        }
    }
    return pop(s);
}

int main()
{
    struct stack S;
    stack s = &S;
    s->top = -1;

    int n; 
    scanf("%d", &n);
    char exp[100];

    for(int i = 0; i < n; i++)
    {
        scanf("\n%[^\n]", exp);
        printf("%d\n",evaluatePostfix(s, exp));
    }
    return 0;
}
