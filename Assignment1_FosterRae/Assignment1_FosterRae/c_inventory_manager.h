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
#include <fstream>
#include <sstream>
#include <io.h>

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
	c_doubly_linked_list get_inventory() { return inventory_; }

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
	/**
	 * @brief Populate the inventory with some items for testing
	 */
	void populate();

	// *** File I/O ***
	/**
	 * @brief Replace all backslashes in a string with forward slashes
	 */
	void replace_backslashes(std::string& file_path);
	/**
	 * @brief Load the inventory from a file
	 * @param file_path The path to the file to load
	 *
	 *  @note Not currently working
	 */
	void load_inventory_from_file(const std::string& file_path);
	/**
	 * @brief Save the inventory to a file
	 *
	 *  @note Not currently implemented
	 */
	void save_inventory_to_file();
	/**
	 * @brief Get the item type from a string
	 * @param type The string to convert
	 * @return The item type as an enum
	 */
	c_item::item_type string_to_item_type(const std::string& type);
	/**
	 * @brief Trim whitespace from a string
	 * @param str The string to trim
	 * @return The trimmed string
	 */
	std::string trim(const std::string& str);
	/**
	 * @brief Generate a unique key for an item
	 * @return The unique key
	 */
	int generate_unique_key();
};
