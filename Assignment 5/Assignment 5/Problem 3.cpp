//NOTE: Building own integer Binary Tree file that only has an insert function and the sumOfNodes Function. 
//NOTE: Function asked for is commented out on this file so you can see which function it is.
#include "IntBinaryTree.h"
#include <iostream>
using namespace std;





////Sums all the nodes together
//int  BinaryTree::sumOfNodes(node* local_root) {
//	int result;
//	if (local_root != NULL) {
//		result = local_root->data;
//		if (local_root->left != NULL) {
//			result += sumOfNodes(local_root->left);
//		}
//		if (local_root->right != NULL) {
//			result += sumOfNodes(local_root->right);
//		}
//	}
//	else
//		return  0;
//	return result;
//}
//
////Determines if there is a root, else returns 0;
//int BinaryTree::sumOfNodes() {
//	if (root == NULL)
//		return 0;
//	else
//		return sumOfNodes(root);
//}


	int main() {
		BinaryTree tree;
		tree.insert(10);
		tree.insert(15);
		tree.insert(25);
		tree.insert(20);
		tree.insert(30);
		tree.insert(5);
		tree.insert(9);
		tree.insert(17);
		tree.insert(2);

		cout << tree.sumOfNodes();
		if (tree.isSearchTree())
			cout << endl << "True";
		else
			cout << endl << "False";
		std::cin.ignore();

	}
