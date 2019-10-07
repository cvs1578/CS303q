#include"Evaluator.h"
#include<iostream>
#include<stack>
#include<string>
using namespace std;

//Function to obtain what to evaluate
int Evaluator::eval(string s)
{
	count = 0;
	for (count; count < s.size(); count++)
	{
		//Numbers
		//Have to account for all numbers
		if (s[count] == '0' || s[count] == '1' || s[count] == '2' || s[count] == '3' || s[count] == '4' || s[count] == '5' || s[count] == '6' || s[count] == '7' || s[count] == '8' || s[count] == '9')
		{
			//First we determine if there are two numbers in a row:
			if (!Number.empty() && ((s[count - 1] == ' ') && (s[count - 2] == '0' || s[count - 2] == '1' || s[count - 2] == '2' || s[count - 2] == '3' || s[count - 2] == '4' || s[count - 2] == '5' || s[count - 2] == '6' || s[count - 2] == '7' || s[count - 2] == '8' || s[count - 2] == '9')))
			{
				error(4, count);
				return -1;
			}
			 // Then we push in numbers

			int num = s[count] - '0'; //This converts the ASCII into regular number since we are effectively converting a char to int.		
			//Then we make sure that we get the entire number instead of just one digit
			while (((count + 1) < s.size()) && (s[count + 1] == '0' || s[count + 1] == '1' || s[count + 1] == '2' || s[count + 1] == '3' || s[count + 1] == '4' || s[count + 1] == '5' || s[count + 1] == '6' || s[count + 1] == '7' || s[count + 1] == '8' || s[count + 1] == '9'))
			{
				num = num * 10 + (s[count + 1] - '0'); 
				count++;
			}
			Number.push(num);

		}




		//Operators
		else if (s[count] == ' '); // ignore the spaces. 

		else if (s[count] == '+') // if it's a + we have to determine if it's increment
		{
			//We have to check to see if the one before is a arithmetic operator
			if (count>0&&(s[count - 1] == '*' || s[count - 1] == '/' || s[count - 1] == '%' || s[count - 1] == '^'|| s[count-1] == '+' || s[count-1] == '-'))
			{
				error(7, count);
				return -1;
			}
			//Account for Spaces
			if (count>1 && s[count - 1] == ' ' && ((s[count - 2] == '+' || s[count - 2] == '-' || s[count - 2] == '*' || s[count - 2] == '/' || s[count - 2] == '%' || s[count - 2] == '^')))
			{
				error(7, count);
				return -1;
			}
			if (s[count + 1] == '+')//This is increment
			{
				StackOperator('i', 8); //i for increment
				count++;
			}
			else
			{
				StackOperator(s[count], 5);
			}
		}
		else if (s[count] == '-') // same thing with --
		{
			//We have to check to see if the one before is a arithmetic operator
			if (count>0 && (s[count - 1] == '*' || s[count - 1] == '/' || s[count - 1] == '%' || s[count - 1] == '^' || s[count - 1] == '+' || s[count - 1] == '-'))
			{
				if (count > 1 && ((s[count - 1] == '+' && (s[count - 2] == '+')) || (s[count - 1] == '-' && s[count - 2] == '-'))); //Keeping track of increment/decrement so it'll increment and decrement negative numbers
				else {
					error(7, count);
					return -1;
				}
			}
			//Account for Spaces
			if (count>1 && s[count - 1] == ' ' && ((s[count - 2] == '+' || s[count - 2] == '-' || s[count - 2] == '*' || s[count - 2] == '/' || s[count - 2] == '%' || s[count - 2] == '^')))
			{
				if (count > 2 && ((s[count - 2] == '+' && (s[count - 3] == '+')) || (s[count - 2] == '-' && s[count - 3] == '-')));
				else {
					error(7, count);
					return -1;
				}
			}
			if (s[count + 1] == '-') //This is decrement
			{
				StackOperator('d', 8); //d for decrement
				count++;
			}
			else if (Number.empty() || (s[count - 1] == '=' || s[count - 1] == '>' || s[count - 1] == '<' || s[count - 1] == '&' || s[count - 1] == '|' || s[count - 1] == '(')||((s[count-1]=='_')&&(s[count - 2] == '=' || s[count - 2] == '>' || s[count - 2] == '<' || s[count - 2] == '&' || s[count - 2] == '|' || s[count - 2] == '('))) //This is negative sign. It sees if either the number stack is empty or that the previous char is a "Binary Comparison".It's big 
			{
				StackOperator(s[count], 8);
			}
			else //This is just normal subtraction
			{
				StackOperator(s[count], 5);
			}

		}
		else if (s[count] == '^') 
		{
			//We have to check to see if the one before is a arithmetic operator
			if (count>0 && (s[count - 1] == '*' || s[count - 1] == '/' || s[count - 1] == '%' || s[count - 1] == '^' || s[count - 1] == '+' || s[count - 1] == '-'))
			{
				error(7, count);
				return -1;
			}
			//Account for Spaces
			if (count>1 && s[count - 1] == ' ' && ((s[count - 2] == '+' || s[count - 2] == '-' || s[count - 2] == '*' || s[count - 2] == '/' || s[count - 2] == '%' || s[count - 2] == '^')))
			{
				error(7, count);
				return -1;
			}
			StackOperator(s[count], 7); // ^ has a precedence of 8
		}
		else if (s[count] == '*' || s[count] == '/' || s[count] == '%')
		{
			//Errors for dividing by 0
			if ((s[count] == '/') && (s[count + 1] == '0'))
			{
				error(6, count+1);
				return -1;
			}
			//acount for spaces
			if ((s[count] == '/' && ((s[count + 1] == ' ') && (s[count + 2] == '0'))))
			{
				error(6, count + 2);
				return -1;
			}
			//We have to check to see if the one before is a arithmetic operator
			if (count>0 && (s[count - 1] == '*' || s[count - 1] == '/' || s[count - 1] == '%' || s[count - 1] == '^' || s[count - 1] == '+' || s[count - 1] == '-'))
			{
				error(7, count);
				return -1;
			}
			//Account for Spaces
			if (count>1 && s[count - 1] == ' ' && ((s[count - 2] == '+' || s[count - 2] == '-' || s[count - 2] == '*' || s[count - 2] == '/' || s[count - 2] == '%' || s[count - 2] == '^')))
			{
				error(7, count);
				return -1;
			}
			
			StackOperator(s[count], 6);
		}
		else if (s[count] == '(')
		{
			op.push(s[count]); //For parenthesis we do everything up until the parenthesis ends
		}
		else if (s[count] == ')')
		{
			while ((!op.empty()) && (op.top() != '(') ) //Goes through entire Operator Stack and does math until it hits the (
			{
				Math();
			}
			if (!op.empty())//If it's not empty then the character in it is '(' meaning that it works
				op.pop();
			else //This is what happens when there's no matching '('
			{
				error(1, count);
				return -1; //For errors we just return -1
			}
		}
		else if (s[count] == '!')
		{
			if (s[count + 1] == '=') //This is !=
			{			
				//First we see if the expression is starting out with comparison
				if (Number.empty()) { // If so, error
					error(2, count);
					return -1; //For errors we return -1
				}
				//Next we see if there is a previous binary operator
				if (s[count - 1] == '&' || s[count - 1] == '|' || s[count - 1] == '<' || s[count - 1] == '>' || s[count - 1] == '=')
				{ //if so, error
					error(3, count);
					return -1;
				}
				//We also have to account for spaces for the error
				if (s[count - 1] == ' ' && ((s[count - 2] == '&' || s[count - 2] == '|' || s[count - 2] == '<' || s[count - 2] == '>' || s[count - 2] == '=')))
				{
					error(3, count);
					return -1;
				}

				StackOperator('n', 3);//n for not-equal
				count++;
			}
			else
			{
				StackOperator(s[count], 8); //logical not
			}

		}
		else if (s[count] == '>')
		{
			//First we see if the expression is starting out with comparison
			if (Number.empty()) { // If so, error
				error(2, count);
				return -1; //For errors we return -1
			}
			//Next we see if there is a previous binary operator
			if (TwoBinInRow(s))
			{
				return -1;
			}
			//Now we have too see if an unary operand is before it
			if (UnaBin(s))
			{
				return -1;
			}
			if (s[count + 1] == '=') //Greater than or equal to
			{
				StackOperator('g', 4);//g = Greater than or equal to
				count++;
			}
			else
			{
				StackOperator(s[count], 4);//Greater than
			}
			
		}
		else if (s[count] == '<')
		{
			//First we see if the expression is starting out with comparison
			if (Number.empty()) { // If so, error
				error(2, count);
				return -1; //For errors we return -1
			}
			//Next we see if there is a previous binary operator
			if (TwoBinInRow(s))
			{
				return -1;
			}
			//Now we have too see if an unary operand is before it
			if (UnaBin(s))
			{
				return -1;
			}
			if (s[count + 1] == '=') //Less than or equal to
			{
				StackOperator('l', 4); //l = less than or equal to
				count++;
			}
			else
			{
				StackOperator(s[count], 4); //less than
			}
		}
		else if (s[count] == '=')
		{
			//First we see if the expression is starting out with comparison
			if (Number.empty()) { // If so, error
				error(2, count);
				return -1; //For errors we return -1
			}
			//Next we see if there is a previous binary operator
			if (TwoBinInRow(s))
			{
				return -1;
			}
			//Now we have too see if an unary operand is before it
			if (UnaBin(s))
			{
				return -1;
			}
			if (s[count + 1] == '=')
			{
				StackOperator('e', 3);
				count++;
			}
			else
			{
				error(10, count); // Since there's only 1 = then it's not a comparison.
				return -1;
			}
		}
		else if (s[count] == '&')
		{
			//First we see if the expression is starting out with comparison
			if (Number.empty()) { // If so, error
				error(2, count);
				return -1; //For errors we return -1
			}
			//Next we see if there is a previous binary operator

			if (TwoBinInRow(s))
			{
				return -1;
			}
			//Now we have too see if an unary operand is before it
			if (UnaBin(s))
			{
				return -1;
			}
			
			if (s[count + 1] == '&')
			{
				StackOperator(s[count], 2);
				count++;
			}
			else
			{
				error(10, count);
			}
		}
		else if (s[count == '|'])
		{
			//First we see if the expression is starting out with comparison
			if (Number.empty()) { // If so, error
				error(2, count);
				return -1; //For errors we return -1
			}
			//Next we see if there is a previous binary operator
			if (TwoBinInRow(s))
			{
				return -1;
			}
			//Now we have too see if an unary operand is before it
			if (UnaBin(s))
			{
				return -1;
			}

			if (s[count + 1] == '|')
			{
				StackOperator(s[count], 1);
				count++;
			}
			else
			{
				error(10, count);
				return -1;
			}
		}
	}
	while (!op.empty()) { //Empty out the stack 
		Math();
	}
	cout << Number.top() << endl;
		return Number.top();
}

//Function error
void Evaluator::error(int error, int location)
{
	switch (error)
	{
	case 1: //closing parenthesis
		cout << "Expression can’t start with a closing parenthesis @ char: " << location << endl;
		break;
	case 2: // Starting with comparison
		cout << "Expression can't start with a binary operator @ char: " << location << endl;
		break;
	case 3: //Two binary operators in a row
		cout << "Two binary operators in a row @ char: " << location << endl;
		break;
	case 4: //Two numbers in row
		cout << "Two operands in a row @ char: " << location << endl;
		break;
	case 5: // Math and Comparison side by side
		cout << "A unary operand can't be followed by a binary operator @ char: " << location << endl;
		break;
	case 6: // Dividing by 0
		cout << "Division by zero @ char: " << location << endl;
		break;
	case 7: //Two algebra operators in a row
		cout << "Two arithmetic operators in a row @ char" << location << endl;
		break;
	case 10: //If it's just = 
		cout << "This symbol alone is not a binary operator @ char: " << location << endl;
		break;
	}
}


void Evaluator::StackOperator(char oper, int prece)
{
	//Default: is the operator stack empty?
	if (Precedence.empty()) {
		op.push(oper);
		Precedence.push(prece);
		return;
	}
	if (prece < Precedence.top()) //If the previous item stored in the stack has a higher or equal precedence then it's done first
	{
		while ((!Precedence.empty())&&prece < Precedence.top()) {
			Math();
		}
		op.push(oper);
			Precedence.push(prece);
	}
	else //This mean the precedence of new operator is greater than or equal to current one
	{
		op.push(oper);
		Precedence.push(prece);
		return;
	}
	
}

//This Does math using stack. It only does 1 operand at a time. 
void Evaluator::Math()
{
	int operand = Number.top();
	Number.pop();
	if (op.top() == '*') //Multiplication
	{
		operand = operand * Number.top();
		Number.pop();
	}
	if (op.top() == '/') //Division
	{
		operand = Number.top() / operand;
		Number.pop();
	}
	if (op.top() == '%') //Remainder
	{
		operand = Number.top() % operand;
		Number.pop();
	}
	if (op.top() == '^') // Power
	{
		operand = pow(Number.top(), operand);
		Number.pop();
	}
	if ((op.top() == '-')&& Precedence.top() == 8) //Negative sign not subtraction
	{
		operand = operand * (-1);
	}
	if (op.top() == '+') //Addition
	{
		operand = operand + Number.top();
		Number.pop();
	}
	if ((op.top() == '-') && Precedence.top() == 5) // Subtraction
	{
		operand = Number.top() - operand;
		Number.pop();
	}
	if (op.top() == 'i')//++
	{
		operand++;
	}
	if (op.top() == 'd')//--
	{
		operand--;
	}
	if (op.top() == '!')//!
	{
		operand = !operand;
	}	
	if (op.top() == 'n') //!=
	{
		operand = operand != Number.top();
		Number.pop();
	}
	if (op.top() == 'g') //>=
	{
		operand = (Number.top() >= operand);
		Number.pop();
	}
	if (op.top() == '>')//Greater than
	{
		operand = (Number.top() > operand);
		Number.pop();
	}
	if (op.top() == 'l')//<=
	{
		operand = (Number.top() <= operand);
		Number.pop();
	}
	if (op.top() == '<')//Less than
	{
		operand = (Number.top() < operand);
		Number.pop();
	}
	if (op.top() == 'e') //==
	{
		operand = (Number.top() == operand);
		Number.pop();
	}
	if (op.top() == '&')
	{
		operand = (Number.top() && operand);
		Number.pop();
	}
	if (op.top() == '|')
	{
		operand = (Number.top() || operand);
		Number.pop();
	}
	if (op.top() == '(')
	{
		op.pop();
		Number.push(operand);
		return;
	}
	op.pop();
	Precedence.pop();
	Number.push(operand);	
}

bool Evaluator::TwoBinInRow(string s)
{
	if (s[count - 1] == '&' || s[count - 1] == '|' || s[count - 1] == '<' || s[count - 1] == '>' || s[count - 1] == '=')
	{ //if so, error
		error(3, count);
		return true;
	}
	//We also have to account for spaces for the error
	if (s[count - 1] == ' ' && ((s[count - 2] == '&' || s[count - 2] == '|' || s[count - 2] == '<' || s[count - 2] == '>' || s[count - 2] == '=')))
	{
		error(3, count);
		return true;
	}
	else
		return false;
}

bool Evaluator::UnaBin(string s)
{
	if (s[count - 1] == '+' || s[count - 1] == '-' || s[count - 1] == '*' || s[count - 1] == '/' || s[count - 1] == '%' || s[count - 1] == '^')
	{
		error(5, count);
		return true;
	}
	//Account for Spaces
	if (s[count - 1] == ' ' && ((s[count - 2] == '+' || s[count - 2] == '-' || s[count - 2] == '*' || s[count - 2] == '/' || s[count - 2] == '%' || s[count - 2] == '^')))
	{
		error(5, count);
		return true;
	}
	else
	{
		return false;
	}
}