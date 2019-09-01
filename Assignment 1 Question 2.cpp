#include <iostream>
using namespace std;

int main()
{
	int y1, y2;
	for (int i = 0;i <= 100;i = i + 10)
	{
		y1 = 100 * i + 10;
		y2 = 5 * i*i + 2;
		cout << "for n = " << i << " y1 = " << y1 << " y2 = " << y2 << '\t';
		if (y1 < y2)
			cout << " y1 is less than y2" << endl;
		else if (y1 > y2)
			cout << " y1 is greater than y2" << endl;
		else
			cout << " y1 is equal to t2" << endl;
	}
	std::cin.ignore();
	return 0;
}