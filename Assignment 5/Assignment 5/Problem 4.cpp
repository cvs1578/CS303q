//NOTE: Assuming Binary Tree is an Int Tree
//NOTE: Using Self-Created Binary Tree found in IntBinaryTree
//NOTE: Function asked for is commented out on this file so you can see which function it is. Everything is in the IntBinaryTree Header 
#include "IntBinaryTree.h"
#include <iostream>
using namespace std;

//Question 4:
//Thought Process since the code is very tiny: If we're going left down the tree, then the max value is the value of the current node and will stay that value unless we go left again
//If we're going right, then the min value is the current node value and will stay until we go right again
//If the root is NULL then we are good
//We need a recursive formula to go down two nodes (left and right) and keep track of the updating max and min values per branch.


//These would be in the Binary Tree Class
//bool BinaryTree::isSearchTree(node* local_root, int min = -99999, int max = 99999)
//{
//	if (local_root == NULL)
//		return true;
//	if (min > local_root->data || max < local_root->data)
//		return false;
//	return (isSearchTree(local_root->left, min, local_root->data) && isSearchTree(local_root->right, local_root->data, max));
//}
//
//bool BinaryTree::isSearchTree()
//{
//	return isSearchTree(root);
//}

