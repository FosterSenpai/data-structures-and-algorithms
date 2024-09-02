// /***********************************************************************
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
// (c) 2024 Media Design School
// File Name : constants.h
// Description : Class for utility functions.
// Author : Foster Rae
// Mail : Foster.Rae@mds.ac.nz
// ************************************************************************/

#pragma once
#include <iostream>
#include "constants.h"

class c_utility
{
public:
	/**
	 * @brief Populates an array with random values.
	 * @param arr The array to populate.
	 * @param n The size of the array.
	 */
	static void populate_array(int* arr, int n);
	/**
	 * @brief Prints the contents of an array.
	 * @param arr The array to print.
	 * @param n The size of the array.
	 */
	static void print_array(int* arr, int n);
	/**
	 * @brief Swaps the values of two integers.
	 * @param a The first integer.
	 * @param b The second integer.
	 */
	static void swap(int* a, int* b);
	/**
	 * @brief Checks if an array is sorted.
	 * @param arr The array to check.
	 * @param n The size of the array.
	 * @return True if the array is sorted, false otherwise.
	 */
	static bool is_sorted(int* arr, int n);
	/**
	 * @brief Partitions an array for the quick sort algorithm, using the last element as the pivot.
	 * @param arr The array to partition.
	 * @param low The lowest index of the array.
	 * @param high The highest index of the array.
	 * @return The partition index. (pivot)
	 */
	static int partition(int* arr, int low, int high);
};

