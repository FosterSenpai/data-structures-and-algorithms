// Purpose: Bogosort algorithm exercise.
#include <iostream>
#include <cstdlib> // for rand and srand
#include <ctime>   // for time

// Function to check if the array is sorted
bool is_sorted(int* array, int size) {
    for (int i = 0; i < size - 1; i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}

// Function to print the array
void print_array(int* array, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void bogosort(int mixed_array[], int size)
{
	int shuffle_count = 0;
	while (!is_sorted(mixed_array, size)) {
		// Shuffle the array
		for (int i = 0; i < size; i++) {
			// Randomly swap the elements
			int random_index = std::rand() % size; // generate a random index from 0 to size-1
			int temp = mixed_array[random_index];  // store the value of the random index in a temporary variable
			mixed_array[random_index] = mixed_array[i]; // assign the value of the current index to the random index
			mixed_array[i] = temp; // assign the value of the temporary variable to the current index
		}
		shuffle_count++;
		std::cout << "Shuffle " << shuffle_count << ": ";
		print_array(mixed_array, size);
	}

    std::cout << "\nSORTED, total shuffles: " << shuffle_count << std::endl;
}

int main() {
    std::cout << "Bogosort algorithm exercise.\n";
    
    // The array before sorting
    int mixed_array[] = {5, 23, 34, 2, 4, 5, 46, 43, 26, 49, 5, 6, 7, 8, 20};
    int size = sizeof(mixed_array) / sizeof(mixed_array[0]);

    std::cout << "The array before sorting: ";
    print_array(mixed_array, size);

    // Seed the random number generator before shuffling
    std::srand(std::time(0));

    // Bogosort algorithm
    bogosort(mixed_array, size);

    return 0;
}
