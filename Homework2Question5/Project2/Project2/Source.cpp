#include<iostream>
#include<string>
using namespace std;

struct node
{
	string data; //The data type is string
	node* next; //Pointer to next

				//Constructor
	node(const string& data_item, node* next_ptr = NULL) :
		data(data_item), next(next_ptr) {} //Item in node and pointer towards next node.
};

//This function outputs the link list. the Head of the list gets passed through
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
	//NOTE: I connected the node this way so I have reference to only the head "Tom" and Tail "Sam"
	node* head = new node("Sam");
	head = new node("Harry", head);
	head = new node("John", head);
	head = new node("Tom", head);
	node* tail = head->next->next->next; //The tail is Sam. We need to declare the tail
	traverselist(head);


	//part a. Insert Bill before Tom
	head = new node("Bill", head); //The new head is Bill and is pointing to the previous head "Tom"
	cout << "a: ";
	traverselist(head);


	//part b. Insert "Sue" before "Sam". Only reference to Sam and head
	head->next->next->next->next = new node("Sue", tail); //Basically create a new node at the end that's pointing to the tail "Sam"
	cout << "b: ";
	traverselist(head);


	//part c. Remove Bill
	node* ptr = head; //Create a pointer to Bill inorder to delete him to save memory
	head = head->next; //Set the head as "Tom"
	delete ptr; //Delete Bill
	cout << "c: ";
	traverselist(head);

	//part d. Remove Sam. Only reference to Sam and head. NOTE: Tail is the reference to Sam
	ptr = tail;
	tail = head->next->next->next; //This is setting tail to "Sue".
	tail->next = NULL; //Have to set the tail to point towards NULL since it's the end of the list
	delete ptr;
	cout << "d: ";
	traverselist(head);
	std::cin.ignore();
}