#pragma once

#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Evaluator
{
public:

	//Function to obtain what to evaluate
	int eval(string);

	//Function error
	void error(int error, int location);

	//Compares current operator with previous to determine when to use item
	void StackOperator(char, int);

	//Does the stack math
	void Math();

	// Determines if there is two binary operators in a row
	bool TwoBinInRow(string s);

	//Determines if there is a Unary operator and a binary operator in a row
	bool UnaBin(string s);


private:
	int count;
	stack<char> op;
	stack<int> Precedence;
	stack<int> Number;
	
};