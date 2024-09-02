// /***********************************************************************
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
// (c) 2024 Media Design School
// File Name : c_node.h
// Description : Represents a node in the doubly-linked list, containing an Item and pointers to the next and previous nodes.
// Author : Foster Rae
// Mail : Foster.Rae@mds.ac.nz
// ************************************************************************/

#pragma once
#include "c_item.h"

class c_node
{
public:
	// *** Constructors & Destructor ***
	\
	c_node(int key, const c_item& item);                                // Constructor with data and key
	c_node(int key, const c_item& item, c_node* next, c_node* prev);    // Constructor with data, key, next, and previous pointers

	~c_node(); 											         // Destructor

	// *** Accessors & Mutators ***

	/**
	 * @brief Mutator for item
	 * @param item - a c_item object to store in the node
	 */
	void set_item(const c_item& item);                                  // Mutator for item
	/**
	 * @brief Accessor for item
	 * @return item stored in the node
	 */
	c_item get_item() const;                                     // Accessor for item

	/**
	 * @brief Mutator for key
	 * @param key - an integer to set as the key
	 */
	void set_key(int key);                                       // Mutator for key
	/**
	 * @brief Accessor for key
	 * @return key of the node
	 */
	int get_key() const;                                         // Accessor for key

	/**
	 * @brief Mutator for next pointer
	 * @param next - a c_node pointer to set as the next pointer
	 */
	void set_next(c_node* next);                                 // Mutator for next pointer
	/**
	 * @brief Accessor for next pointer
	 * @return next pointer
	 */
	c_node* get_next() const;                                    // Accessor for next pointer

	/**
	 * @brief Mutator for previous pointer
	 * @param prev - a c_node pointer to set as the previous pointer
	 */
	void set_prev(c_node* prev);                                 // Mutator for previous pointer
	/**
	 * @brief Accessor for previous pointer
	 * @return previous pointer
	 */
	c_node* get_prev() const;                                    // Accessor for previous pointer

protected:

	// *** Member Variables ***

	c_item m_item_;  // Item stored in the node
	int m_key_;      // Key for the node
	c_node* m_next_; // Pointer to the next node
	c_node* m_prev_; // Pointer to the previous node
};
