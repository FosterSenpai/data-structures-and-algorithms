/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2024 Media Design School
File Name : cList.h
Description : The cList class represents a Singly-linked list.
Author : Foster Rae
Mail : Foster.Rae@mds.ac.nz
************************************************************************/

// ======================================================================
// Includes
// ======================================================================
#pragma once
#include "c_node.h"

/// <summary> Class to represent a singly-linked list. </summary>
class cList
{
protected:

	// --- Data members ---

	cNode* m_head_;		// Pointer to the first node in the list.
	cNode* m_current_;    // Pointer to the current node in the list.
	int m_nodes_;			// Number of nodes in the list.

public:

	// --- Constructors and Destructors ---

	/// <summary> Default constructor. </summary>
	cList();
	/// <summary> Default destructor. </summary>
	~cList();


	// --- Methods ---

	// ------ Insert Methods ------

	/// <summary> Inserts a new node at the start of the list. </summary>
	/// <param name="key"> The key of the new node as an Integer </param>
	/// <param name="value"> The value of the new node as a Float </param>
	void insert_head(const int key, const float value);
	/// <summary> Inserts a new node at the end of the list. </summary>
	/// <param name="key"> The key of the new node as an Integer </param>
	/// <param name="value"> The value of the new node as a Float </param>
	void insert_tail(const int key, const float value);
	/// <summary> Inserts a new node at position '<code>_position</code>' in the list </summary>
	/// <param name="position"> The position to insert the new node as an Integer </param>
	/// <param name="key"> The key of the new node as an Integer </param>
	/// <param name="value"> The value of the new node as a Float </param>
	/// <remarks> Remember head/start of list is position 0. </remarks>
	void insert_body(int position, const int key, const float value);


	// ------ Delete Methods ------

	/// <summary> Deletes the head node from the list. </summary>
	void delete_head();
	/// <summary> Deletes the tail node from the list. </summary>
	void delete_tail();
	/// <summary> Deletes the node at position '<code>_position</code>' from the list. </summary>
	/// <param name="position"> The position of the node to delete as an Integer </param>
	void delete_body(int position);


	// ------ Additional Methods ------

	/// <summary> Returns the node at '<code>_position</code>' in the list. </summary>
	/// <param name="position"> The position of the node to return as an Integer </param>
	/// <returns> A pointer to the node at position '<code>_position</code>'. </returns>
	cNode* get_node(int position) const;
	/// <summary> Returns the node with the key value '<code>_key</code>' in the list. </summary>
	/// <param name="key"> The key of the node to return as an Integer </param>
	/// <returns> A pointer to the node with the key value '<code>_key</code>' </returns>
	cNode* find_node(int key) const;
	/// <summary> Returns the number of nodes in the list. </summary>
	///	<returns> The number of nodes in the list as an Integer </returns>
	int num_nodes() const;
	/// <summary> Checks if a node with the key value '<code>_key</code>' exists in the list. </summary>
	///	<param name="key"> The key of the node to check for as an Integer </param>
	///	<returns> True if a node with the key value '<code>_key</code>' exists in the list, false otherwise. </returns>
	bool node_exists(int key) const;

	void print_list() const;
};