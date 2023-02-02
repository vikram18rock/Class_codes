/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// the following code is space optimised by pushing 
// the empty vector into 2d vector and then accessing it 

// level order traversal is used
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> a;
    vector<int>b;
    int lev = 0;
    queue<TreeNode*> n;
    // if tree is empty return empty vector
    if(root == NULL)
        return a;
    // else push 1st node
    n.push(root);
    TreeNode* tmp;
	// current level is completed
	// root is only element in 1st level
    n.push(NULL);
	// without having an internal vector we cannot access it by a[row].push_back()
	// so push the empty vector
    a.push_back(b);
    // as queue is not empty now we operate until it's empty
    while(!n.empty())
    {
        // copy top element to tmp and pop the queue
        tmp = n.front();
		// remove from queue
        n.pop();
        // if the higher level is finished then so is lower
        // so add null for every null not after a node's child
        if(tmp == NULL && !n.empty())
        {
			// print level if we want no. of levels
            lev++;
			// add an empty vector to increase the level in 2d vector
            a.push_back(b);
			// for every null push null
            n.push(NULL);
        }
        // if popped node is not NULL add it's children if they exist
        else if(tmp != NULL)
        {
            // pass value to vector
            a[lev].push_back(tmp->val);
            // if left child exist add to queue
            if(tmp->left != NULL)
                n.push(tmp->left);
            // if right child exist add to queue
            if(tmp->right != NULL)
                n.push(tmp->right);
            // seperating levels
        }
    }
    return a;
    }
};
