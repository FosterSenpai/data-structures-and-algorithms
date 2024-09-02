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
	 * @brief Get the head node
	 *  @return a pointer to the head node
	 */
	c_node* get_head() const { return head_node_; }
	/**
	 * @brief Get the tail node
	 * @return a pointer to the tail node
	 */
	c_node* get_tail() const { return tail_node_; }
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
	 * @brief Get the node from a given name
	 * @param name - the name to search for
	 * @return a pointer to the node with the given name, or nullptr if the name is not found
	 *
	 * @note not case-sensitive, NAME, Name, and name are considered the same
	 */
	c_node* get_node_from_name(const std::string& name) const;
	/**
	 * @brief Get the node from a given type
	 * @param type - the type to search for (e.g. WEAPON, ARMOR, POTION, CONSUMABLE, UTILITY) as a string.
	 * @return a pointer to the node with the given type, or nullptr if the type is not found
	 *
	 * @note not case-sensitive, WEAPON, Weapon, and weapon are considered the same
	 */
	c_node* get_node_from_type(c_item::item_type type) const;
	/**
	 * @brief Get the node with the lowest price
	 * @return a pointer to the node with the lowest price
	 */
	c_node* get_lowest_price() const;
	/**
	 * @brief Get the node with the highest price
	 * @return a pointer to the node with the highest price
	 */
	c_node* get_highest_price() const;
	/**
	 * @brief Get the node with the lowest quantity
	 * @return a pointer to the node with the lowest quantity
	 */
	c_node* get_lowest_quantity() const;
	/**
	 * @brief Get the node with the highest quantity
	 * @return a pointer to the node with the highest quantity
	 */
	c_node* get_highest_quantity() const;

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
	/**
	 * @brief Check if the list is empty
	 * @return true if the list is empty, false otherwise
	 */
	bool is_empty() const;
	/**
	 * @brief Swap node a with node b
	 */
	void swap(c_node* a, c_node* b);

	// ** Insertion **
	/**
	 * @brief Insert an item at the head of the list
	 * @param key - the key of the item to insert (must be unique)
	 * @param item - the item to insert
	 */
	void insert_head(int key, const c_item& item);
	/**
	 * @brief Insert an item at the tail of the list
	 * @param key - the key of the item to insert (must be unique)
	 * @param item - the item to insert
	 */
	void insert_tail(int key, const c_item& item);
	/**
	 * @brief Insert an item in the body of the list
	 * @param key - the key of the item to insert (must be unique)
	 * @param item - the item to insert
	 * @param position - the position to insert the item at
	 */
	void insert_body(int key, const c_item& item, int position);

	// ** Deletion **
	/**
	 * @brief Delete the head node
	 */
	void delete_head();
	/**
	 * @brief Delete the tail node
	 */
	void delete_tail();
	/**
	 * @brief Delete the current node
	 * @param position - the position of the node to delete
	 */
	void delete_body(int position);

	// ** Sorting **
	/**
	 * @brief Sort the list using Quicksort
	 *
	 * @note Uses the last node as the pivot
	 */
	void quick_sort_ascending(c_node* low, c_node* high, int sort_choice);
	/**
	 * @brief Sort the list in descending order using Quicksort
	 *
	 * @note Uses the last node as the pivot
	 */
	void quick_sort_descending(c_node* low, c_node* high, int sort_choice);
	/**
	 * @brief Partition the list for Quicksort
	 * @param low - a c_node pointer to the lower bound of the partition
	 * @param high - a c_node pointer to the upper bound of the partition
	 * @param sort_choice - the column to sort by (0 = name, 1 = type, 2 = price, 3 = quantity)
	 * @return the partition index
	 */
	c_node* partition_ascending(c_node* low, c_node* high, int sort_choice);
	/**
	 * @brief Partition the list for Quicksort in descending order
	 * @param low - a c_node pointer to the lower bound of the partition
	 * @param high - a c_node pointer to the upper bound of the partition
	 * @param sort_choice - the column to sort by (0 = name, 1 = type, 2 = price, 3 = quantity)
	 * @return the partition index
	 */
	c_node* partition_descending(c_node* low, c_node* high, int sort_choice);


protected:

	// *** Data Members ***

	c_node* head_node_;       // Pointer to the head node
	c_node* tail_node_;       // Pointer to the tail node
	int size_;				  // Number of nodes in the list
};
