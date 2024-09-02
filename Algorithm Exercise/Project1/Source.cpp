// Bubble sort algorithm exercise
#include <iostream>

// Function to print the array
void print_array(int* array, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void bubble_sort(int mixed_array[], int size)
{
	int swaps = 0;

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (mixed_array[j] > mixed_array[j + 1])
			{
				// swap the elements
				int temp = mixed_array[j]; // store the value of the first element in a temporary variable
				mixed_array[j] = mixed_array[j + 1]; // assign the value of the second element to the first element
				mixed_array[j + 1] = temp; // assign the value of the temporary variable to the second element
				swaps++;

				// Print the array after each swap
				std::cout << "\nArray after swap " << swaps << ": ";
				for (int k = 0; k < size; k++)
				{
					std::cout << mixed_array[k] << " ";
				}
			}
		}
	}

	std::cout << "\nSORTED, total swaps: " << swaps << std::endl;
}

int main() {

    std::cout << "Bubble sort algorithm exercise.\n";
    // The array before sorting
    int mixed_array[] = {5,23,34,2,4,5,46,43,26,49,5,6,7,8,20};
    std::cout << "The array before sorting: ";
	print_array(mixed_array, sizeof(mixed_array) / sizeof(mixed_array[0]));

	// Bubble sort algorithm
    int size = sizeof(mixed_array)/sizeof(mixed_array[0]);
    bubble_sort(mixed_array, size);

    return 0;
}
