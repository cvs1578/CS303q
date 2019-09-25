#include<iostream>
#include<string>
#include <stack>
using namespace std;

void main()
{
	stack <char>s; //gonna use stack so we can do Last in First Out so words come out right
	string newPhrase;
	string phrase = "The quick brown fox jumps over the lazy dog.";
	cout << phrase << endl;
	for (int i = phrase.size() - 1; i >= 0; i--)
	{
		if (phrase[i] != ' ') //As long as it isn't a space, it'll put each individual character into the stack
			s.push(phrase[i]);
		else
		{
			while (!s.empty())
			{
				newPhrase += s.top(); //It will add each character from the stack to the new string.
				s.pop();
			}
			newPhrase += ' '; //Adds the space
		}
	}
	while (!s.empty()) //Make sure the stack is fully empty 
	{
		newPhrase += s.top();
		s.pop();
	}
	cout << newPhrase << endl;
	std::cin.ignore();
}
