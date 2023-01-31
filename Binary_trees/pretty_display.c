#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *left, *right;
};
typedef struct Node* node;

// finding the left and right subtree seperation
int find_index(char *st, int s, int e)
{
	int b = 0;
  // indirect stack implementation
	for(int i = s; i <= e; i++)
	{
    // push if open bracket
		if (st[i] == '(')
			b++;
    // pop if closed bracket
		else if (st[i] == ')')
			b--;
		if (b==0)
			return i;
	}
  // if not balanced
	return -1;
}

// creating node for tree
node create_node(int k)
{
	node new_node =  (node)malloc(sizeof (struct Node));
	new_node->data = k;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

// for creating tree
node create_tree(char* string, int s, int e)
{
	if(s>e) 
		return NULL;
	int sum = 0;
  
  // getting number
	while( s <= e && string[s] >= '0' && string[s] <= '9')
	{
		sum = sum * 10 + (string[s] - '0');
		s++;
	}
  // pushing key into node
	node n = create_node(sum);
	s++;
	int p=-1;
	if (string[s] == '(' && s < e ) 
		p=find_index(string,s,e);
	if (p != -1)
	{
		n->left = create_tree(string, s+2, p-2);
		n->right = create_tree(string, p+4, e-2);
	}
	return n;
}

// displaying tree using indentation
void display(node root, int spaces, char s)
{
	node temp = root;
	if(temp == NULL)
		return;
	int i = spaces;
	while(i--)
		printf("	");
  // printing the data(l or r)
	printf("%d(%c)\n", root->data, s);
	char l = 'L';
  // updating indentation for children by incrementing spaces
	display(root->left, spaces+1, l);
	l = 'R';
	display(root->right, spaces+1, l);
}

int main()
{
	char *string= (char*)malloc(sizeof(char) * 1000000);
  // for getting line with spaces as input
	scanf("%[^\n]%*c", string);

	int length = 0;
	for (int i = 0; string[i] != '\0'; ++i)
	{
		length++;
	}
	node root = NULL;
	root = create_tree(string,2, (length - 3));
  // P for parent , only for root
	char a = 'P';
  // pretty display
	display(root, 0, a);
  // freeing space used
  free(string);
	return 0;
}
