#include "Evaluator.h"
using namespace std;

//NOTE: We only have one class with a few functions in class. View Evaluator.cpp and Evaluator.h for full code
int main()
{
	Evaluator eval;
	int result = eval.eval("++++2-5*(3^2");
	cin.ignore();
	return 0;
;}