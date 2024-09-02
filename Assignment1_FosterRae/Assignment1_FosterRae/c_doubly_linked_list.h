// /***********************************************************************
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
// (c) 2024 Media Design School
// File Name : c_doubly_linked_list.h
// Description : Manages the doubly-linked list, providing methods to add, remove, find, edit, and display items, as well as to sort the list using Quicksort.
// Author : Foster Rae
// Mail : Foster.Rae@mds.ac.nz
// ************************************************************************/

#pragma once
#include "c_node.h"

class c_doubly_linked_list
{
public:

	// *** Constructor & Destructor ***

	c_doubly_linked_list();  // Constructor
	~c_doubly_linked_list(); // Destructor

	// *** Methods ***
	// ** Utility **
	/**
	 * @brief Check if a key is unique in the list
	 * @param key - the key to check
	 * @return true if the key is unique, false otherwise
	 *
	 * @note using this is increases time complexity by O(n) as it has to traverse the list
	 */
	bool is_key_unique(int key) const;
	/**
	 * @brief Get the node at a given position
	 * @param position - the position of the node to get
	 * @return a pointer to the node at the given position
	 *
	 * @note Will print an error message if the position is out of bounds
	 */
	c_node* get_node_from_position(int position) const;
	/**
	 * @brief Get the node from a given key
	 * @param key - the key to search for
	 * @return a pointer to the node with the given key
	 */
	c_node* get_node_from_key(int key) const;
	/**
	 * @brief Calculate the size of the list
	 * @param head - pointer to the head node
	 * @return the number of nodes in the list as an integer
	 *
	 * @note Will print an error message if the count does not match the size of the list
	 */
	int calculate_size(c_node* head) const;
	/**
	 * @brief Check if a key exists in the list
	 * @param key - the key to search for
	 * @return true if the key exists, false otherwise
	 */
	bool key_exists(int key) const;

	// ** Insertion **
	void insert_head(int key, const c_item& item); // Insert an item at the head of the list
	void insert_tail(int key, const c_item& item); // Insert an item at the tail of the list
	void insert_body(int key, const c_item& item, int position); // Insert an item in the body of the list

	// ** Deletion **
	void delete_head(); // Delete the head node
	void delete_tail(); // Delete the tail node
	void delete_body(int position); // Delete the current node


protected:

	// *** Data Members ***

	c_node* head_node_;       // Pointer to the head node
	c_node* tail_node_;       // Pointer to the tail node
	int size_;				  // Number of nodes in the list
};
