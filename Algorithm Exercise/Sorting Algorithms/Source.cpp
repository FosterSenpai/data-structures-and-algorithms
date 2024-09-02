#include "c_sort.h"
#include "c_utility.h"
#include "constants.h"

int main()
{
	// ** Bubble Sort **
	std::cout << "************************** Bubble Sort **************************" << '\n';
	int array1[ARRAY_SIZE];                          // Create an array of size ARRAY_SIZE
	c_utility::populate_array(array1, ARRAY_SIZE); // Populate the array with random values
	// Print the unsorted array
	std::cout << "Unsorted Array: ";
	c_utility::print_array(array1, ARRAY_SIZE);
	// Sort the array using bubble sort
	c_sort::bubble_sort(array1, ARRAY_SIZE);
	std::cout << "Sorted Array: ";
	c_utility::print_array(array1, ARRAY_SIZE);

	// ** Insertion Sort **
	std::cout << "\n\n************************** Insertion Sort **************************" << '\n';
	int array2[ARRAY_SIZE];                          // Create an array of size ARRAY_SIZE
	c_utility::populate_array(array2, ARRAY_SIZE); // Populate the array with random values
	// Print the unsorted array
	std::cout << "Unsorted Array: ";
	c_utility::print_array(array2, ARRAY_SIZE);
	// Sort the array using insertion sort
	c_sort::insertion_sort(array2, ARRAY_SIZE);
	std::cout << "Sorted Array: ";
	c_utility::print_array(array2, ARRAY_SIZE);

	// ** Selection Sort **
	std::cout << "\n\n************************** Selection Sort **************************" << '\n';
	int array3[ARRAY_SIZE];                          // Create an array of size ARRAY_SIZE
	c_utility::populate_array(array3, ARRAY_SIZE); // Populate the array with random values
	// Print the unsorted array
	std::cout << "Unsorted Array: ";
	c_utility::print_array(array3, ARRAY_SIZE);
	// Sort the array using selection sort
	c_sort::selection_sort(array3, ARRAY_SIZE);
	std::cout << "Sorted Array: ";
	c_utility::print_array(array3, ARRAY_SIZE);

	// ** Quick Sort **
	std::cout << "\n\n************************** Quick Sort **************************" << '\n';
	int array4[ARRAY_SIZE];                          // Create an array of size ARRAY_SIZE
	c_utility::populate_array(array4, ARRAY_SIZE); // Populate the array with random values
	// Print the unsorted array
	std::cout << "Unsorted Array: ";
	c_utility::print_array(array4, ARRAY_SIZE);
	// Sort the array using quick sort
	c_sort::quick_sort(array4, 0, ARRAY_SIZE - 1); // -1 as the last element is the pivot
	std::cout << "Sorted Array: ";
	c_utility::print_array(array4, ARRAY_SIZE);

	return 0;
}