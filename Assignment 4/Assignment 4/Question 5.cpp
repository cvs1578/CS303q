#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <algorithm> // This contains a function allowing us to reverse vectors
using namespace std;

//NOTE: These are the sorting algorithms uploaded on Canvas. Minor edits in order to keep track of # of comparisons and number of exchanges.
//Main code on very bottom
void ShellSort(vector <int> &num) {
	int i, temp, flag = 1, numLength = num.size();
	int gap = numLength;
	bool insertionNeeded = false;
	int swapPos = 0;
	int key;

	long long int numCompare = 0, numExchange = 0; //NOTE: All copmarisons are using long long int because the number is massive

	while (true) {    // boolean flag (true when not equal to 0) 
		
		gap = (gap - 1) / 2;
		if (gap == 0)
			break;

		for (int k = 0; k < gap; k++) {
			for (int j = gap + k; j < numLength; j += gap) {
				key = num[j];

				insertionNeeded = false;
				for (i = j - gap; i >= 0; i -= gap) {   // Smaller values move right
					numCompare++;
					if (key < num[i]) {
						numExchange++;
						swapPos = i;
						num[i + gap] = num[i];
						insertionNeeded = true;
					}
					else
						break;
				}
				if (insertionNeeded) {
					num[swapPos] = key;    //Put key into its proper location
					numExchange++;
				}
			}
		}
	}
	cout << "Shell Sort: Number of Comparisons: " << numCompare << "Number of Exchanges: " << numExchange << endl;
	return;
}


void selection_sort(vector<int>& vec) {
	long long int numCompare = 0, numExchange = 0;

	for (int fill = 0; fill != vec.size(); ++fill) {
		int pos_min = fill;
		for (int next = fill + 1; next != vec.size(); ++next) {
			numCompare++;
			if (vec[next] < vec[pos_min])
			{
				pos_min = next;
				numExchange++;
			}

		}
		if (fill != pos_min)
		{
			swap(vec[pos_min], vec[fill]);
			numExchange++;
		}

	}
	cout << "Selection Sort: Number of Comparisons: " << numCompare << "Number of Exchanges: " << numExchange << endl;
}



void bubble_sort_improved(vector <int> &vec) {
	long long int numCompare = 0, numExchange = 0;
	bool exchanges = false;
	for (int i = 1; i <= vec.size(); i++) {
		exchanges = false;
		for (int j = 0; j < vec.size() - i; j++) {
			numCompare++;
			if (vec[j + 1] < vec[j]) {
				numExchange++;
				swap(vec[j], vec[j + 1]);// swap elements
				exchanges = true;
			}
		}
		if (!exchanges)
			break;
	}
	cout << "Bubble Sort (Improved): Number of Comparisons: " << numCompare << "Number of Exchanges: " << numExchange << endl;
}


void insertion_sort(std::vector <int> &num) {
	long long int numCompare = 0, numExchange = 0;
	int i, j, key;
	bool insertionNeeded = false;

	for (j = 1; j < num.size(); j++) {
		key = num[j];
		insertionNeeded = false;
		for (i = j - 1; i >= 0; i--) { // larger values move right
			numCompare++;
			if (key < num[i]) {
				numExchange++;
				num[i + 1] = num[i];
				insertionNeeded = true;
			}
			else
				break;
		}
		if (insertionNeeded)
			num[i + 1] = key;    //Put key into its proper location
	}
	cout << "Insertion Sort: Number of Comparisons: " << numCompare << "Number of Exchanges: " << numExchange << endl;
}


void merge(std::vector<int>& array, std::vector<int>& result, int lowPointer, int highPointer, int upperBound, long long int& numCompare, long long int& numExchange) {
	int j = 0;
	int lowerBound = lowPointer;
	int mid = highPointer - 1;
	int n = upperBound - lowerBound + 1; //number of items

	while (lowPointer <= mid && highPointer <= upperBound) {
		numCompare++;
		if (array[lowPointer] < array[highPointer])
			result[j++] = array[lowPointer++];
		else
			result[j++] = array[highPointer++];
	}

	while (lowPointer <= mid)
	{
		result[j++] = array[lowPointer++];
	}


	while (highPointer <= upperBound)
		result[j++] = array[highPointer++];


	for (j = 0; j < n; j++) //copy the items from the temporary array to the original array
	{
		array[lowerBound + j] = result[j];
		numExchange++;
	}
}

void mergesort(std::vector<int>& array, std::vector<int>& result, int lowerBand, int upperBand, long long int& numCompare, long long int& numExchange) {
	int midpoint;
	if (lowerBand < upperBand) {
		midpoint = (lowerBand + upperBand) / 2;
		mergesort(array, result, lowerBand, midpoint, numCompare, numExchange); //merge sort the left half
		mergesort(array, result, midpoint + 1, upperBand, numCompare, numExchange); //merge sort the right half
		merge(array, result, lowerBand, midpoint + 1, upperBand, numCompare, numExchange);
	}
}

void mergeSort(std::vector<int>& array) {
	std::vector<int> result = array;
	long long int numCompare = 0, numExchange = 0;

	mergesort(array, result, 0, array.size() - 1, numCompare, numExchange);
	cout << "Merge Sort: Number of Comparisons: " << numCompare << "Number of Exchanges: " << numExchange << endl;
}



int partition(int first, int last, std::vector<int>& arr, long long int& numCompare, long long int& numExchange) {
	// Start up and down at either end of the sequence.
	// The first table element is the pivot value.
	int up = first + 1;
	int down = last - 1;
	do {

		while ((up != last) && !(arr[first] < arr[up])) {
			++up;
		}
		while (arr[first] < arr[down]) {
			--down;
		}
		numCompare++;
		if (up < down) {
			// if up is to the left of down,
			swap(arr[up], arr[down]);
			numExchange++;
		}
	} while (up < down); // Repeat while up is left of down.

	swap(arr[down], arr[first]);
	numExchange++;
	return down;
}

void sort_median(std::vector<int>& arr, int first, int last, long long int& numCompare, long long int& numExchange) {

	bool exchanges = true;
	int middle = (first + last) / 2;
	numCompare++;
	if (arr[first] > arr[middle])
	{
		swap(arr[first], arr[middle]);
		numExchange++;
	}
	numCompare++;
	if (arr[middle] > arr[last])
	{
		swap(arr[middle], arr[last]);
		numExchange++;
	}
	numCompare++;
	if (arr[first] > arr[middle])
	{
		swap(arr[first], arr[middle]);
		numExchange++;
	}


	//swap the middle with the left 
	swap(arr[middle], arr[first]);
	numExchange++;
}

int partitionB(int first, int last, std::vector<int>& arr, long long int& numCompare, long long int& numExchange) {
	// Start up and down at either end of the sequence.
	// The first table element is the pivot value.

	int up = first + 1;
	int down = last - 1;
	sort_median(arr, first, last - 1, numCompare, numExchange);
	int mid = first;
	do {
		while ((up != last - 1) && !(arr[mid] < arr[up])) {
			++up;
		}
		while (arr[mid] < arr[down]) {
			--down;
		}
		numCompare++;
		if (up < down) {
			// if up is to the left of down,
			numExchange++;
			swap(arr[up], arr[down]);
		}
	} while (up < down); // Repeat while up is left of down.
	numExchange++;
	swap(arr[mid], arr[down]);
	return down;
}

void middle_quick_sort(int first, int last, std::vector<int>& arr, long long int& numCompare, long long int& numExchange) {
	if (last - first > 1) {
		// There is data to be sorted.
		// Partition the table.
		int pivot = partitionB(first, last, arr, numCompare, numExchange);

		// Sort the left half.
		middle_quick_sort(first, pivot, arr, numCompare, numExchange);

		// Sort the right half.
		middle_quick_sort(pivot + 1, last, arr, numCompare, numExchange);
	}
}

void middle_quick_sort_wrapper(vector<int>& arr) {
	long long int numCompare = 0, numExchange = 0;
	middle_quick_sort(0, arr.size(), arr, numCompare, numExchange);
	cout << "Quick Sort (Improved): Number of Comparisons: " << numCompare << "Number of Exchanges: " << numExchange << endl;
}

void quick_sort(int first, int last, std::vector<int>& arr, long long int& numCompare, long long int& numExchange) {
	if (last - first > 1) {
		// There is data to be sorted.
		// Partition the table.
		int pivot = partition(first, last, arr, numCompare, numExchange);

		// Sort the left subarray.
		quick_sort(first, pivot, arr, numCompare, numExchange);

		// Sort the right subarray.
		quick_sort(pivot + 1, last, arr, numCompare, numExchange);
	}
}

void quick_sort_wrapper(vector<int>& arr) {
	long long int numCompare = 0, numExchange = 0;
	quick_sort(0, arr.size(), arr, numCompare, numExchange);
	cout << "Quick Sort: Number of Comparisons: " << numCompare << "Number of Exchanges: " << numExchange << endl;
}


vector<int> random_vector(size_t size) {
	vector<int> v1;
	for (int i = 0; i < size; i++)
		v1.push_back(rand() % size); //put a random number between 0 and size
	return v1;
}

/*NOTE: I could've used these two equations in order to create the sorted and reversed vectors,
but after a random vector is sorted, it's already sorted, and there is a simple code in the function
library 'algorithms' in order to reverse a vector. 

vector<int> sorted_vector(size_t size) {
	vector<int> v1;
	for (int i = 0; i < size; i++)
		v1.push_back(i);
	return v1;
}

vector<int> reversed_vector(size_t size) {
	vector<int> v1;
	for (int i = size - 1; i >= 0; i--)
		v1.push_back(i);
	return v1;
}
*/
int main() {
	vector<int> v1 = random_vector(10000);

	cout << "Random Array: " << endl;
	selection_sort(v1);
	cout << "Sorted Array: " << endl;
	selection_sort(v1);
	reverse(v1.begin(), v1.end()); // This reverses the vector
	cout << "Reversed Array: " << endl;
	selection_sort(v1);

	cout << "Random Array: " << endl;
	v1 = random_vector(10000);
	bubble_sort_improved(v1);
	cout << "Sorted Array: " << endl;
	bubble_sort_improved(v1);
	reverse(v1.begin(), v1.end()); // This reverses the vector
	cout << "Reversed Array: " << endl;
	bubble_sort_improved(v1);


	cout << "Random Array: " << endl;
	v1 = random_vector(10000);
	insertion_sort(v1);
	cout << "Sorted Array: " << endl;
	insertion_sort(v1);
	reverse(v1.begin(), v1.end()); // This reverses the vector
	cout << "Reversed Array: " << endl;
	insertion_sort(v1);


	cout << "Random Array: " << endl;
	v1 = random_vector(10000);
	ShellSort(v1);
	cout << "Sorted Array: " << endl;
	ShellSort(v1);
	reverse(v1.begin(), v1.end()); // This reverses the vector
	cout << "Reversed Array: " << endl;
	ShellSort(v1);

	cout << "Random Array: " << endl;
	v1 = random_vector(10000);
	mergeSort(v1);
	cout << "Sorted Array: " << endl;
	mergeSort(v1);
	reverse(v1.begin(), v1.end()); // This reverses the vector
	cout << "Reversed Array: " << endl;
	mergeSort(v1);

	cout << "Random Array: " << endl;
	v1 = random_vector(10000);
	quick_sort_wrapper(v1); // NOTE: Considering this as Quick Sort. Also since quick sort crashes whenever we sort an already sorted array we're skipping that
	//reverse(v1.begin(), v1.end()); This crashes the program. I'm assuming overflow or something 
	//cout << "Reversed Array: " << endl;
	//quick_sort_wrapper(v1);

	cout << "Random Array: " << endl;
	v1 = random_vector(10000);
	middle_quick_sort_wrapper(v1); // NOTE: Considering this as Quick Sort (Improved)
	cout << "Sorted Array: " << endl;
	middle_quick_sort_wrapper(v1);
	reverse(v1.begin(), v1.end()); // This reverses the vector
	cout << "Reversed Array: " << endl;
	middle_quick_sort_wrapper(v1);

	std::cin.ignore();
	return 0;
}




