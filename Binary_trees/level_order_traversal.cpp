
/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */


//Function to return a list containing the level order traversal.
vector<int> level_order(Node *root)
{
    vector<int> a;
    queue<Node*> n;
    // if tree is empty return empty vector
    if(root == NULL)
        return a;
    // else push 1st node
    n.push(root);
    Node* tmp;
    // as queue is not empty now we operate until it's empty
    while(!n.empty())
    {
        // copy top element to tmp and pop the queue
        tmp = n.front();
        n.pop();
        // if popped node is not NULL add it's children if they exist
        if(tmp != NULL)
        {
            // pass value to vector
            a.push_back(tmp->data);
            // if left child exist add to queue
            if(tmp->left != NULL)
                n.push(tmp->left);
            // if right child exist add to queue
            if(tmp->right != NULL)
                n.push(tmp->right);
        }
    }
    return a;
}
