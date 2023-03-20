#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key, height;
    struct Node *left, *right; 
};

typedef struct Node* node;

int max(int a, int b)
{
    if(a < b)
        return b;
    return a;
}

void prettyDisplay(node root, int tab, char child)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        for (int i = 0; i < tab; i++)
        {
            printf("    ");
        }
        printf("%d(%c), %d\n", root->key, child, root->height);
        prettyDisplay(root->left, tab+1, 'l');
        prettyDisplay(root->right, tab+1, 'r');
    }
}

int height(node N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

node leftRotate(node x)
{
    node y = x->right;
    node  t2 = y->left;
    
    y->left = x;
    x->right = t2;
    
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
    
    printf("after left rotate: \n");

    return y;
}

node rightRotate(node x)
{
    node y = x->left;
    node t2 = y->right;
    
    y->right = x;
    x->left = t2;
    
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
    
    printf("after rightRotate: ");

    return y;
}


int balanceFactor(node root)
{
    if (root == NULL)
    {
        return 0;
    }
    return height(root->left) - height(root->right);
}

node createNode(int data)
{
    node temp = (node)malloc(sizeof(struct Node));
    temp->key = data;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 1;
    return temp;
}


node avlFixup(node root, int key)
{
    int balance = balanceFactor(root);
    // Left Left Case
    if (balance > 1 && key < root->left->key)
        return rightRotate(root);
 
    // Right Right Case
    if (balance < -1 && key > root->right->key)
        return leftRotate(root);
 
    // Left Right Case
    if (balance > 1 && key > root->left->key)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }
 
    // Right Left Case
    if (balance < -1 && key < root->right->key)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    prettyDisplay(root, 0, '*');
    return root;
}
node insertAvl(node root, int dataRead)
{
    if(root == NULL)
    {
        return createNode(dataRead);
    }
    else
    {
        if(root->key < dataRead)
        {
            root->right = insertAvl(root->right, dataRead);
        }
        else
        {
            root->left = insertAvl(root->left, dataRead);
        }
    }
    root->height = 1 + max(height(root->left), height(root->right));
    prettyDisplay(root, 0, '*');
    return avlFixup(root, dataRead);
}


void inorder(node root)
{
    if(root == NULL)
        return;
    printf("%d ", root->key);
    inorder(root->left);
    inorder(root->right);
}

int main()
{
    int n, dataRead;
    scanf("%d", &n);

    node root = NULL;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &dataRead);
        root = insertAvl(root, dataRead);
    }
    prettyDisplay(root, 0, '*');
    return 0;
}
