#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int to_number(string s, int n = 0)
{
	if (n == s.size()) //Default: Makes sure the size doesn't exceed the string size
		return 0;
	if (isdigit(s[n])) //If the character's a number (NOTE: This would've been useful in the project).
		return ((s[n] - '0') + to_number(s, n + 1)); // the -'0' is to convert the ASCII number to an int value
	else
		return (0 + to_number(s, n + 1)); // If not number, adds 0 and the next value. 
}
//Note: main functions should be commented out so that I can put all of the assignment functions in the same solution/folder
int main()
{
	cout << to_number("3ac4");
	cin.ignore();
	return 0;
}