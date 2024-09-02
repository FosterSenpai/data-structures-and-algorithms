//Problem Selection Sort Algorithm exercise.
#include <iostream>

void print_array(int* array, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void selection_sort(int* array, int size) {
	// Selection sort algorithm
	int iterations = 0;

    for (int i = 0; i < size -1; i++) // one by one move boundary of unsorted sub array, first pass index 0, second pass index 1, etc.
    {
        int min_index = i; // find the minimum element in the unsorted part of the array

        for (int j = i + 1; j < size; j++) // find the index of the minimum element
		{
			if (array[j] < array[min_index]) // if the current element is less than the minimum element
			{
				min_index = j; // update the index of the minimum element
            }
        }

        // Swap the found minimum element with the first element
        if (min_index != i) // if the minimum element is not the first element
		{
            // swap the elements
			int temp = array[i]; // store the value of the first element in a temporary variable
			array[i] = array[min_index]; // assign the value of the minimum element to the first element
			array[min_index] = temp; // assign the value of the temporary variable to the minimum element
            iterations++;
		}

		std::cout << "Iteration " << iterations << ": ";
		print_array(array, size); // print the array after each iteration
    }

	std::cout << "SORTED, total iterations: " << iterations << std::endl;
}
int main(int argc, char* argv[])
{

    std::cout << "Selection Sort Algorithm exercise.\n";
    int arr[] = {5, 23, 34, 2, 4, 5, 46, 43, 26, 49, 5, 6, 7, 8, 20};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "The array before sorting: ";
    print_array(arr, size);
    std::cout <<std::endl;

    selection_sort(arr, size);
    return 0;
}