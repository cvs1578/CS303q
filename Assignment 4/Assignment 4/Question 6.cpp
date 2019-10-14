#include <iostream>
using namespace std;

struct node
{
	int data; //The data type is string
	node* next; //Pointer to next
	node* prev;
				//Constructor

	node(const int& data_item, node* prev_val = NULL, node* next_ptr = NULL) :

		data(data_item), prev(prev_val), next(next_ptr) {} //Item in node and pointer towards next node.
};

//NOTE: Assuming this is a double linked list
void insertion_sort_list(node* head) {
	int key;
	bool insertionNeeded = false;
	node* current_node = head->next;
	node* node2;
    while (current_node != NULL) {
		key = current_node->data;
		node2 = current_node->prev;
		insertionNeeded = false;
		while (node2 != NULL) {
			if (key < node2->data) {
				node2->next->data = node2->data;
				insertionNeeded = true;
			}
			else
				break;
			node2 = node2->prev;
		}
		if (insertionNeeded)
		{
			node2->next->data = key;
		}
		
		
		current_node = current_node->next;
	}
}

void traverselist(node* head)

{

	node* current_node = head;

	while (current_node != NULL) {

		cout << current_node->data;

		if (current_node->next != NULL)

			cout << "==>";

		current_node = current_node->next;

	}

	cout << endl;

}

void main()
{
	node* head = new node(1);
	head->next = new node(8);
	head->next->prev = head;
	head->next->next = new node(4);
	head->next->next->prev = head->next;
	traverselist(head);
	insertion_sort_list(head);
	traverselist(head);
	cin.ignore();
}