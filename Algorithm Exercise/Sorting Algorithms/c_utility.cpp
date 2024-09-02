#include "c_utility.h"

void c_utility::populate_array(int* arr, int n)
{
	for (int i = 0; i < n; i++)                                    // Iterate through the array
	{
		arr[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE; // Assign a random value to the current element
	}
}

void c_utility::print_array(int* arr, int n)
{
	for (int i = 0; i < n; i++)     // Iterate through the array
	{
		std::cout << arr[i] << " "; // Print the current element
	}
	std::cout << std::endl;              // Print a newline and flush the buffer
}

void c_utility::swap(int* a, int* b)
{
	// Swap the values of 'a' and 'b'
	int temp = *a;  // Store the value of 'a' in a temporary variable
	*a = *b;        // Assign the value stored in 'b' to 'a'
	*b = temp;      // Assign the value of the temporary variable(old 'a') to 'b'
	// The values of 'a' and 'b' have now been swapped
}

bool c_utility::is_sorted(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++) // Iterate through the array
	{
		if (arr[i] > arr[i + 1])    // If the current element is greater than the next element
		{
			return false;           // It's not sorted so return false
		}
	}
	return true; // If the loop completes, the array is sorted so return true
}

int c_utility::partition(int* arr, int low, int high)
{
	// The partition function is used in the quick sort algorithm
	// It selects a pivot element and partitions the array around it

	int pivot = arr[high]; // Select the last element as the pivot
	int i = low - 1;       // Set the index of the smaller element to the left of the array

	// Traverse through the array low to high and move elements less than the pivot to the left
	for (int j = low; j < high; j++) // Iterate through the array
	{
		if (arr[j] < pivot) // If the current element is less than the pivot
		{
			i++; // Increment the index of the smaller element
			swap(&arr[i], &arr[j]); // Swap the elements
		}
	}

	// Move the pivot element to the correct position(right of the smaller elements) and return the index
	swap(&arr[i + 1], &arr[high]); // Swap the pivot element to the end of the smaller elements
	return i + 1;                       // Return the index of the pivot
}
