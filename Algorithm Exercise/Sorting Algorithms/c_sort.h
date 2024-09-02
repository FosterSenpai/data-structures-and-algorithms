// /***********************************************************************
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
// (c) 2024 Media Design School
// File Name : c_sort.h
// Description : Class to hold sorting algorithms.
// Author : Foster Rae
// Mail : Foster.Rae@mds.ac.nz
// ************************************************************************/
#pragma once
#include "c_utility.h"
#include <chrono>
class c_sort
{
public:
	/**
	 * @brief Sorts an array using the bogo sort algorithm.
	 * @param arr The array to sort.
	 * @param n The size of the array.
	 */
	static void bogo_sort(int* arr, int n);
	/**
	 * @brief Sorts an array using the bubble sort algorithm.
	 * @param arr The array to sort.
	 * @param n The size of the array.
	 */
	static void bubble_sort(int* arr, int n);
	/**
	 * @brief Sorts an array using the insertion sort algorithm.
	 * @param arr The array to sort.
	 * @param n The size of the array.
	 */
	static void insertion_sort(int* arr, int n);
	/**
	 * @brief Sorts an array using the selection sort algorithm.
	 * @param arr The array to sort.
	 * @param n The size of the array.
	 */
	static void selection_sort(int* arr, int n);
	/**
	 * @brief Sorts an array using the quick sort, randomized algorithm.
	 * @param arr The array to sort.
	 * @param low The lowest index of the array.
	 * @param high The highest index of the array.
	 */
	static void quick_sort(int* arr, int low, int high);
};

