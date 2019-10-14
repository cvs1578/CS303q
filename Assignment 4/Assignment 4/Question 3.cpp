#include <iostream>
#include <vector>
using namespace std;

int linear_search(vector<int>& items, int target, int pos_last) //NOTE: No default variable for last position, so must indicate size of vector - 1
{
	if (pos_last < 0)
		return -1;
	if (target == items[pos_last])
		return pos_last;
	else
		return linear_search(items, target, pos_last - 1);
}

//Note: main functions should be commented out so that I can put all of the assignment functions in the same solution/folder
int main()
{
	vector<int> s;
	s.begin();
	for (int i = 0; i < 2;i++)
	{
		for (int j = 0; j < 10; j++)
		{
			s.push_back(j);
		}
	}
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i] << " ";
	}
	cout << endl << linear_search(s, 9, s.size() - 1);
	cin.ignore();
	return 0;
}