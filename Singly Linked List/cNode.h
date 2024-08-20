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

/* Comment Reading tip:
 * All my function comments are XML, so they will appear when you hover over the function or variable.
 * Minimise all function comments for clarity.
 */

 // --- Include Files ---

#pragma once

/// <summary> Class to represent a node in a linked list. </summary>
/// <remarks> Only has one pointer to the next node right now, will need to add a pointer to the previous node for a doubly linked list. </remarks>
class cNode
{
protected:

	// --- Data members ---

	int mKey;		 // Unique key for each node.
	float mValue;	 // Value of the node.
	cNode* mNext;    // Pointer to the next cNode.

public:

	// --- Constructors and Destructors ---

	/// <summary> Default constructor. </summary>
	/// <param name="_key"> The Unique key of the node as an Integer </param>
	cNode(int _key);
	/// <summary> Default destructor. </summary>
	/// <remarks> Todo: Will Probably need to change</remarks>
	~cNode();


	// --- Methods ---

	// ------ Accessors ------

	/// <summary> Get the key of the node. </summary>
	/// <returns> The key of the node as an Integer </returns>
	int GetKey() const;
	/// <summary> Set the value of the node. </summary>
	/// <param name="_value"> The value to set the node to as a Float </param>
	void SetValue(float _value);
	/// <summary> Get the value of the node. </summary>
	/// <returns> The value of the node as a Float </returns>
	float GetValue() const;
	/// <summary> Set the next node. </summary>
	/// <param name="_next"> The next node to set as a cNode pointer </param>
	void SetNext(cNode* _next);
	/// <summary> Get the next node. </summary>
	/// <returns> A pointer to the next cNode </returns>
	cNode* GetNext() const;
};