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

node findMin(node root)
{
    if (root == NULL)
    {
        return root;
    }
    node temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
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


node avlFixup(node root)
{
    int balance = balanceFactor(root);
    if (balance > 1 && balanceFactor(root->left) >= 0)
        return rightRotate(root);
 
    // Left Right Case
    if (balance > 1 && balanceFactor(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }
 
    // Right Right Case
    if (balance < -1 && balanceFactor(root->right) <= 0)
        return leftRotate(root);
 
    // Right Left Case
    if (balance < -1 && balanceFactor(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
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
    return avlFixup(root);
}

node deleteAvl(node root, int key)
{
    if(root == NULL)
        return root;

    if ( key < root->key )
        root->left = deleteAvl(root->left, key);
 
     else if( key > root->key )
        root->right = deleteAvl(root->right, key);
     else
    {
        // node with only one child or no child
        if( (root->left == NULL) || (root->right == NULL) )
        {
            struct Node *temp = root->left ? root->left : root->right;
            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
                *root = *temp;
            free(temp);
        }
        else
        {
            struct Node* temp = findMin(root->right);
            root->key = temp->key;
            root->right = deleteAvl(root->right, temp->key);
        }
    }
 
    if (root == NULL)
        return root;
    
    printf("deleting key\n");
    root->height = 1 + max(height(root->left), height(root->right));
    
    return avlFixup(root);
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
    printf("Enter no. of nodes: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    node root = NULL;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &dataRead);
        root = insertAvl(root, dataRead);
    }
    // before delete
    prettyDisplay(root, 0, '*');
  
    printf("Enter no. to delete: ");
    scanf("%d", &n);
    deleteAvl(root, n);
    // after delete
    prettyDisplay(root, 0, '*');
    return 0;
}
