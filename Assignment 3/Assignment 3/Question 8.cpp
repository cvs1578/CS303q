#include<iostream>
#include<queue>
using namespace std;

queue<int> move_to_rear(queue<int> s) //NOTE: This is for ints. If you want to use any other data type just change the variable.
{
	s.push(s.front());
	s.pop();
	return s;
}

void main()
{
	queue<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	queue<int> x = s;
	s = move_to_rear(s);
	while (!x.empty())
	{
		cout << x.front() << " ";
		x.pop();
	}
	cout << endl;
	while (!s.empty())
	{
		cout << s.front() << " ";
		s.pop();
	}
	std::cin.ignore();
}
