/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2024 Media Design School
File Name : c_node.h
Description : The c_node class represents a node in a doubly linked list.
Author : Foster Rae
Mail : Foster.Rae@mds.ac.nz
************************************************************************/
#pragma once

/**
 * @brief The c_node class represents a node in a doubly linked list.
 * @details Each node contains a key, data, and pointers to the previous and next nodes.
 */
class c_node
{
protected:

	// ========================== Data Members ==========================

	float data_;      // *** May need to change the data type later for the project ***
	int key_;
	c_node* prev_;
	c_node* next_;

public:

	// ================== Constructors and Destructors ==================

	c_node(int key);                                            // Constructor with key
	c_node(int key, float data);                                // Constructor with data and key
	c_node(int key, float data, c_node* next); 				    // Constructor with data, key and next pointer
	c_node(int key, float data, c_node* prev, c_node* next);    // Constructor with data, key and both pointers

	~c_node();

	// ======================== Member Functions ========================

	//                    ***** Accessor Functions *****

	/**
	 * @brief Get the key of the node
	 * @return Key as an integer
	 */
	int get_key() const { return key_; }
	/**
	 * @brief Get the data of the node
	 * @return Data as a float
	 */
	float get_data() const { return data_; }
	/**
	 * @brief Get the previous node
	 * @return Pointer to the previous node
	 */
	c_node* get_prev() const { return prev_; }
	/**
	 * @brief Get the next node
	 * @return Pointer to the next node
	 */
	c_node* get_next() const { return next_; }


	//					  ***** Mutator Functions *****

	/**
	 * @brief Set the key of the node
	 * @param key Key as an integer
	 */
	void set_key(int key) { key_ = key; }
	/**
	 * @brief Set the data of the node
	 * @param data Data as a float
	 */
	void set_data(float data) { data_ = data; }
	/**
	 * @brief Set the previous node
	 * @param prev Pointer to the previous node
	 */
	void set_prev(c_node* prev) { prev_ = prev; }
	/**
	 * @brief Set the next node
	 * @param next Pointer to the next node
	 */
	void set_next(c_node* next) { next_ = next; }
};

