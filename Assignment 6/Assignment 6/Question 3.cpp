#include<iostream>
#include<queue>
using namespace std;

//Persons object 
class Person {
public:
	Person() {
		dependents = 0;
	};
	Person(int x) {
		dependents = x;
	};
	int returnDependents()
	{
		return dependents;
	};

private:
	int dependents;

};


//FFunction updates the queue so it remains a max priority queue
void adda(Person A, queue<Person>& Priority)
{
	queue<Person> temp;//We create a temp 
	while (!Priority.empty())
	{
		if (Priority.front().returnDependents() < A.returnDependents()) //Compare what we're passing through and the front of the queue
		{ //If what we're passing through is higher, then we push what we're passing through into the temp function
			temp.push(A);
			A = Priority.front(); //While setting A as whatever's the front variable of queue
			Priority.pop(); //then we pop the queue
		}
		else
		{ //Else we put the front of the queue into the temp
			temp.push(Priority.front());
			Priority.pop();
		}
	}
	temp.push(A); 
	while (!temp.empty()) //We then put everything back into the original queue
	{
		Priority.push(temp.front());
		temp.pop();
	}
}


void main()
{
	Person Tim(5); //The number passed in is the dependents the person has. 
	Person Bill(10);
	Person Eric(50);
	Person Sam(25);
	queue<Person> Priority; //NOTE: Making my own Priority Queue using Queues
	adda(Tim, Priority);
	adda(Bill, Priority);
	adda(Eric, Priority);
	adda(Sam, Priority);
	while (!Priority.empty()) {
		cout << Priority.front().returnDependents() << endl;//NOTE: We're returning the number of dependents to clasify wach person. 
		Priority.pop();
	}
	//NOTE: You should get 50 25 10 5 to prove the code works
	cin.ignore();

}

