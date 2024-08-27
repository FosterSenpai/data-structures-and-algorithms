/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2024 Media Design School
File Name : c_list.h
Description : The cList class represents a doubly linked list.
Author : Foster Rae
Mail : Foster.Rae@mds.ac.nz
************************************************************************/
#pragma once
#include "c_node.h"

/**
 * @brief The cList class represents a doubly linked list.
 * @details The list contains a head and tail pointer, and a size variable.
 */
class c_list
{
protected:
	// ========================== Data Members ==========================

	c_node* head_node_;       // Pointer to the head node
	c_node* current_node_;    // Pointer to the current node
	int size_;				  // Number of nodes in the list

public:
	// ================== Constructors and Destructors ==================

	c_list();    // Constructor
	~c_list();    // Destructor

	// ========================== Member Functions ==========================

	//                      ***** Insert Functions *****

	/**
	 * @brief Insert a node at the head of the list
	 * @param key Key of the node
	 * @param data Data of the node
	 *
	 * @note Time Complexity: O(1)
	 */
	void insert_head(const int key, const float data);
	/**
	 * @brief Insert a node at the tail of the list
	 * @param key Key of the node
	 * @param data Data of the node
	 *
	 * @note Time Complexity: O(n)
	 */
	void insert_tail(const int key, const float data);
	/**
	 * @brief Insert a node at a specified position in the list
	 * @param key Key of the node
	 * @param data Data of the node
	 * @param position Position to insert the node
	 *
	 * @note Time Complexity: O(n)
	 */
	void insert_body(const int key, const float data, int position);


	//                      ***** Delete Functions *****

	/**
	 * @brief Delete the head node of the list
	 *
	 *  @note Time Complexity: O(1)
	 */
	void delete_head();
	/**
	 * @brief Delete the tail node of the list
	 *
	 * @note Time Complexity: O(n)
	 */
	void delete_tail();
	/**
	 * @brief Delete a node at a specified position in the list
	 * @param position Position to delete the node
	 *
	 * @note Time Complexity: O(n)
	 */
	void delete_body(int position);


	//                      ***** Accessor Functions *****

	/**
	 * @brief Get the node at the specified position
	 *  @param position Position of the node
	 */
	void get_node_from_position(int position);
	/**
	 * @brief Get the node with the specified key
	 * @param key Key of the node
	 */
	void get_node_from_key(int key);


	//                      ***** Utility Functions *****

	/**
	 * @brief Get the size of the list
	 * @return Size of the list as an integer
	 */
	int list_size(c_node* head) const;
	/**
	 * @brief Check if the list is empty
	 * @return True if the list is empty, false otherwise
	 */
	bool key_exists(int key);
	/**
	 * @brief Traverse the list forward from the head, printing the key and data of each node
	 * @param head Pointer to the head node
	 */
	void traverse_forward(c_node* head);
	/**
	 * @brief Traverse the list backward from the tail, printing the key and data of each node
	 * @param head Pointer to the head node
	 */
	void traverse_backward(c_node* head);
	/**
	 * @brief Print the list from the head to the tail
	 */
	void print_list() const;
};

