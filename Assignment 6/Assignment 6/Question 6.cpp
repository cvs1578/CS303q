#include "Huffman_Tree.h"
#include <iostream>
#include <fstream> //We use this in order to use .txt file
#include <vector> 
#include <string>
using namespace std;
//NOTE: Assuming it's asking to make a huffman tree based on the amount of words, not the characters.
//I'm also adding a txt file that contains the nursery rhyme (NOTE: no word contains capital letters or have any punctuations since I only care about the words themselves).
void main()
{
	ifstream fin; //fin = function input, or nursery rhyme

	fin.open("NurseryRhyme.txt"); //This is the file that contains the nursery rhyme. 


	//First, we're gonna see how many of each word is in the rhyme and store into 2 vectors
	string oneword;
	vector<string> Words;
	vector<int> number;
	bool check = false;
	while (fin.good())
		{
		check = false;
			fin >> oneword;
			for (int i = 0; i < Words.size(); i++)
			{
				if (oneword == Words[i])
				{
					check = true;
					number[i]++;
				}
			}
			if (check == false)
			{
				Words.push_back(oneword);
				number.push_back(1);
			}
		}
	//Next we sort out the vectors into highest priority.
	//I just used a bubble sort since it's easiest to type
	for (int i = 1; i <= number.size();i++)
	{
		for (int j = 0; j < number.size() - i;j++)
		{
			if (number[j+1] > number[j])
			{
				std::swap(number[j], number[j+1]);
				std::swap(Words[j], Words[j+1]);

			}
		}
	}

	vector<Huff_Data<string>> huff_Data;
	//Next, we're gonna do the huffman code pushing in the number of each item and the word.
	for (int i = 0; i < Words.size(); i++)
	{
		huff_Data.push_back(Huff_Data<string>(number[i], Words[i]));
	}
	//I just copied this code from the example file on Canvas. 
		std::ostringstream code;
		Huffman_Tree<string> huff_tree;
		huff_tree.build_tree(huff_Data);
		huff_tree.print_code(code);
		string result = code.str();
		cout << result;
		result = huff_tree.decode("010");

		
		std::cin.ignore();
}