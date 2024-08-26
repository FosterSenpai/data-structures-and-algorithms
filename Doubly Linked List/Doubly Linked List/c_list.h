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
	c_node* tail_node_;       // Pointer to the tail node
	c_node* current_node_;    // Pointer to the current node
	int size_;				  // Number of nodes in the list

public:
	// ================== Constructors and Destructors ==================

	c_list();    // Constructor
	~c_list();    // Destructor

	// ========================== Member Functions ==========================

	//                      ***** Insert Functions *****

	void insert_head(const int key, const float data);
	void insert_tail(const int key, const float data);
	void insert_body(const int key, const float data);


	//                      ***** Delete Functions *****

	void delete_head();
	void delete_tail();
	void delete_body();


	//                      ***** Accessor Functions *****

	void get_node_from_position(int position) const;
	void get_node_from_key(int key) const;


	//                      ***** Utility Functions *****

int c_list::list_size(c_node* head) const;
	bool node_exists(int key) const;
	void traverse_forward(c_node* head);
	void traverse_backward(c_node* tail);
	void print_list() const;
};

