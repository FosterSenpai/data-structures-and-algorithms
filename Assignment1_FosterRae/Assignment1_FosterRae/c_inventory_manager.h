// /***********************************************************************
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
// (c) 2024 Media Design School
// File Name : c_inventory_manager.h
// Description : Handles file I/O operations and user interactions like menus, managing the overall inventory system.
// Author : Foster Rae
// Mail : Foster.Rae@mds.ac.nz
// ************************************************************************/

#pragma once
#include "c_doubly_linked_list.h"
#include <iostream>
// include windows without max and min macros
#define NOMINMAX
#include <Windows.h>

class c_inventory_manager
{
public:
	// *** Constructor ***
	c_inventory_manager();  // Constructor

	// *** Methods ***
	/**
	 * @brief Display the main menu and handle user input, calling the appropriate methods
	 *
	 * @note This is the main method that drives the program
	 */
	void main_menu();

private:
	c_doubly_linked_list inventory_; // The inventory list

	// *** Methods ***
	/**
	 * @brief Display the inventory
	 */
	void display_inventory();
	/**
	 * @brief Sort the inventory
	 * @note Uses Quicksort with pivot as the last element
	 */
	void sort_inventory();
	/**
	 * @brief Menu to add an item to the inventory
	 */
	void add_item();
	/**
	 * @brief Menu to delete an item from the inventory
	 */
	void delete_item();
	/**
	 * @brief Menu to edit an item in the inventory
	 */
	void edit_item();
    void load_inventory_from_file();
    void save_inventory_to_file();
    void handle_invalid_input();
	/**
	 * @brief Clear the console screen
	 *
	 * @note This is a Windows-specific method
	 */
	void clear_screen();

};
