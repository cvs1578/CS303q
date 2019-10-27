#include<iostream>
using namespace std;

struct node {
	int data;
	node *left;
	node *right;
};


class BinaryTree {
public:
	BinaryTree();
	~BinaryTree();

	void insert(int);


	//Problem 3
	int sumOfNodes();
	int sumOfNodes(node*);


	//Problem 4
	bool isSearchTree();
	bool isSearchTree(node*, int, int);

private:
	void insert(int, node*);
	node *root;
};

//Constructor
BinaryTree::BinaryTree()
{
	root = NULL;
}
//Deconstructor
BinaryTree::~BinaryTree() {};

//Inserts Data into the tree assuming the root is not empty
void BinaryTree::insert(int value, node* leaf)
{
	if (value < leaf->data)
	{
		if (leaf->left != NULL)
		{
			insert(value, leaf->left);
		}
		else {
			leaf->left = new node;
			leaf->left->data = value;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}
	else if (value >= leaf->data)
	{
		if (leaf->right != NULL)
		{
			insert(value, leaf->right);
		}
		else {
			leaf->right = new node;
			leaf->right->data = value;
			leaf->right->left = NULL;
			leaf->right->right = NULL;
		}
	}
}

//Inserts tree if root is empty
void BinaryTree::insert(int value)
{
	if (root != NULL)
		insert(value, root);
	else {
		root = new node;
		root->data = value;
		root->left = NULL;
		root->right = NULL;
	}
}


//Question 3
//Sums all the nodes together
int  BinaryTree::sumOfNodes(node* local_root) {
	int result;
	if (local_root != NULL) {
		result = local_root->data;
		if (local_root->left != NULL) {
			result += sumOfNodes(local_root->left);
		}
		if (local_root->right != NULL) {
			result += sumOfNodes(local_root->right);
		}
	}
	else
		return  0;
	return result;
}

//Determines if there is a root, else returns 0;
int BinaryTree::sumOfNodes() {
	if (root == NULL)
		return 0;
	else
		return sumOfNodes(root);
}



//Question 4:
//Thought Process since the code is very tiny: If we're going left down the tree, then the max value is the value of the current node and will stay that value unless we go left again
//If we're going right, then the min value is the current node value and will stay until we go right again
//If the root is NULL then we are good
//We need a recursive formula to go down two nodes (left and right) and keep track of the updating max and min values per branch.

bool BinaryTree::isSearchTree(node* local_root, int min = -99999, int max = 99999)
{
	if (local_root == NULL)
		return true;
	if (min > local_root->data || max < local_root->data)
		return false;
	return (isSearchTree(local_root->left, min, local_root->data) && isSearchTree(local_root->right, local_root->data, max));
}

bool BinaryTree::isSearchTree()
{
	return isSearchTree(root);
}