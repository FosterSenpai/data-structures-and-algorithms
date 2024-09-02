// Problem: Insertion Sort Algorithm exercise.
#include <iostream>

void print_array(int* array, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

// Better to put the sorting algorithm in a separate function
void insertion_sort(int* array, int size) {
	// Insertion sort algorithm

	int iterations = 0;
	for (int i = 1; i < size; ++i)
	{
		int key = array[i]; // the current element to be compared
		int j = i - 1;      // the element before the current element, this is the element to be compared with the key

		while (j >= 0 && array[j] > key)  // while j is greater than or equal to 0 and the element at index j is greater than the key
		{
			array[j + 1] = array[j]; // move the element at index j to the right
			j = j - 1;               // move to the next element to the left
		}

		array[j + 1] = key; // insert the key into the correct position
		std::cout << "Iteration " << ++iterations << ": ";
		print_array(array, size); // print the array after each iteration
	}

	std::cout << "SORTED, total iterations: " << iterations << std::endl;
}

int main(int argc, char* argv[])
{

	std::cout << "Insertion Sort Algorithm exercise.\n";
	int arr[] = {5, 23, 34, 2, 4, 5, 46, 43, 26, 49, 5, 6, 7, 8, 20};
	int size = sizeof(arr) / sizeof(arr[0]);

	std::cout << "The array before sorting: ";
	print_array(arr, size);
	std::cout <<std::endl;

	insertion_sort(arr, size);

	return 0;
}
