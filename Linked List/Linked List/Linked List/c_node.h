/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2024 Media Design School
File Name : cNode.h
Description : The cNode class represents a node in a linked list.
Author : Foster Rae
Mail : Foster.Rae@mds.ac.nz
************************************************************************/

// ======================================================================
// Includes
// ======================================================================
#pragma once

/// <summary> Class to represent a node in a linked list. </summary>
/// <remarks> Only has one pointer to the next node right now, will need to add a pointer to the previous node for a doubly linked list. </remarks>
class cNode
{
protected:

	// --- Data members ---

	int m_key_;		 // Unique key for each node.
	float m_value_;	 // Value of the node.
	cNode* m_next_;    // Pointer to the next cNode.

public:

	// --- Constructors and Destructors ---

	/// <summary> Default constructor. </summary>
	/// <param name="key"> The Unique key of the node as an Integer </param>
	cNode(int key);
	/// <summary> Default destructor. </summary>
	/// <remarks> Todo: Will Probably need to change</remarks>
	~cNode();


	// --- Methods ---

	// ------ Accessors ------

	/// <summary> Get the key of the node. </summary>
	/// <returns> The key of the node as an Integer </returns>
	int get_key() const;
	/// <summary> Set the value of the node. </summary>
	/// <param name="value"> The value to set the node to as a Float </param>
	void set_value(float value);
	/// <summary> Get the value of the node. </summary>
	/// <returns> The value of the node as a Float </returns>
	float get_value() const;
	/// <summary> Set the next node. </summary>
	/// <param name="next"> The next node to set as a cNode pointer </param>
	void set_next(cNode* next);
	/// <summary> Get the next node. </summary>
	/// <returns> A pointer to the next cNode </returns>
	cNode* get_next() const;
};