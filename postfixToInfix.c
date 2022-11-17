#include <stdio.h>
#include <stdlib.h>

// nodes of tree
struct node
{
    char data;
    struct node *left, *right;
};

typedef struct node * node;

// stack
struct stack
{
    node top;
};

typedef struct stack* stack;

node createTreeNode(char key, node left, node right)
{
    node new_node = malloc(sizeof(struct node));
    new_node->left = left;
    new_node->right = right;

    return new_node;
}

void push(stack s, node new)
{
    if (s->top == 0)
    {
        s->top = new;
    }
    else
    {
        new->left = s->top;
        s->top = new;
    }
}

node pop(stack s)
{
    if (s->top == 0)
    {
        return 0;
    }
    node d = s->top;
    s->top = s->top->left;
}

int operand(char ch)
{
    if (ch <= 'z' && ch >= 'a')
        return 1;
    return 0;
}
void inorder()
{

}

node PostfixToExpressionTree(stack s, char exp[])
{
    node new_node, r_child, l_child;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (operand(exp[i]))
        {
            new_node = createTreeNode(exp[i], 0, 0);
            push(s, new_node);
        }
        else
        {
            r_child = pop(s);
            l_child = pop(s);
            new_node = createTreeNode(exp[i], l_child, r_child);
        }
    }
    inorder();
}

int main()
{
    struct stack S;
    stack s = &S;
    char exp[100];
    scanf("%s", exp);

    PostfixToExpressionTree(s, exp);
    return 0;
}