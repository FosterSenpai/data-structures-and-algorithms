#include "c_sort.h"
void c_sort::bogo_sort(int* arr, int n)
{
    // While the array is not sorted
    // Shuffle the array
    // Check if the array is sorted
    // If it is, break

    // Bogo sort is a highly ineffective, it might never finish

    int iterations = 0; // Variable to store the number of iterations
    auto start = std::chrono::high_resolution_clock::now(); // Start the timer
    while (!c_utility::is_sorted(arr, n))
    {
        iterations++; // Increment the number of iterations
        for (int i = 0; i < n; i++) // Iterate through the array
        {
            int j = rand() % n;                     // Generate a random index
            c_utility::swap(&arr[i], &arr[j]); // Swap the current element with the randomly selected element
        }
        std::cout << "Iteration " << iterations << ": ";                                       // Print the current iteration
        // Calculate the iteration speed per second and print it
        auto end = std::chrono::high_resolution_clock::now();              // Store the end time
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start); // Calculate the elapsed time in milliseconds
        double iterationSpeed = static_cast<double>(iterations) / (duration.count() / 1000.0);  // Calculate the iteration speed per second
        std::cout << "Iteration speed: " << iterationSpeed << " iterations/second | ARRAY = ";  // Print the iteration speed
        c_utility::print_array(arr, n);                                                         // Print the array
    }

    std::cout << "ACTUALLY Sorted in " << iterations << " iterations.\n"; // Print the number of iterations
    std::cout << "Array: ";                                               // Print the array
    c_utility::print_array(arr, n);
    start = std::chrono::high_resolution_clock::now(); // Update the start time
}

void c_sort::bubble_sort(int* arr, int n)
{
    // Bubble sort is a simple sorting algorithm
    // Traverse from the left and compare each element with the next element
    // If the current element is greater than the next element, swap them
    // The larger element goes to the right
    // Repeat the process until the array is sorted

    for (int i = 0; i < n - 1; i++) // Iterate through the array
	{
        bool swapped = false; // Variable to store if a swap has occurred
        for (int j = 0; j < n - i - 1; j++) // Iterate through the array
        {
	        if (arr[j] > arr[j + 1]) // If the current element is greater than the next element
			{
				c_utility::swap(&arr[j], &arr[j + 1]); // Swap the elements
				swapped = true; // Set swapped to true
			}
        }

    	if (swapped == false) // If no swaps occurred in the inner loop, the array is sorted so break
		{
            break;
		}
	}
}

void c_sort::insertion_sort(int* arr, int n)
{
    // Insertion sort is a simple sorting algorithm
    // Start with the second element as the first element is assumed to be sorted
    // compare the second element with the first element and check if the second element is smaller
    // If it is, swap the elements
    // Move to the third element and compare it with the second element
    // If the third element is smaller than the second element, swap them
    // Then compare the third element with the first element
    // If the third element is smaller than the first element, swap them
    // Repeat the process until the array is sorted

    for (int i = 1; i < n; ++i) // Iterate through the array
    {
    	int key = arr[i]; // Store the current element to compare
		int j = i - 1;    // Store the index of the previous element to compare

		while (j >= 0 && arr[j] > key) // While the previous element is greater than the current element (& the index is not out of bounds)
		{
			arr[j + 1] = arr[j]; // Move the previous element to the right
			j = j - 1;           // Move to the next element
		}
		arr[j + 1] = key; // Insert the current element in the correct position
    }
}

void c_sort::selection_sort(int* arr, int n)
{
    // Selection sort is a simple sorting algorithm
	// Traverse the whole array and find the smallest element
	// Swap the smallest element with the first element
	// Traverse the array from the second element and find the smallest element
	// Swap the smallest element with the second element
	// Repeat the process until the array is sorted

	for (int i = 0; i < n - 1; i++) // Iterate through the array
	{
		int min_index = i; // Store the index of the smallest element
		for (int j = i + 1; j < n; j++) // Iterate through the array
		{
			if (arr[j] < arr[min_index]) // If the current element is smaller than the smallest element
			{
				min_index = j; // Update the index of the smallest element
			}
		}

        if(min_index != i) // If the smallest element is not the current element
        {
        	c_utility::swap(&arr[min_index], &arr[i]); // Swap the smallest element with the current element, moving the smallest element to the left
        }
	}
}

void c_sort::quick_sort(int* arr, int low, int high)
{
	// Quick sort is a divide and conquer algorithm
	// It picks an element as a pivot(we are using the last element) and partitions the array around the pivot
	// The pivot is placed in its correct position in the sorted array
	// The elements smaller than the pivot are placed to the left of the pivot
	// The elements greater than the pivot are placed to the right of the pivot
	// The array is then divided into two sub-arrays and the process is repeated

	if (low < high) // If the low index is less than the high index
	{
		int pivot_index = c_utility::partition(arr, low, high); // Partition the array and store the pivot index

        // Recursively sort the sub-arrays
		quick_sort(arr, low, pivot_index - 1);  // Sort the left sub-array (low - pivot), recursive call
        quick_sort(arr, pivot_index + 1, high);  // Sort the right sub-array (pivot - high), recursive call
	}
}
