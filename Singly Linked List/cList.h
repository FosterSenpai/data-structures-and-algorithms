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

/* Comment Reading tip:
 * All my function comments are XML, so they will appear when you hover over the function or variable.
 * Minimise all function comments for clarity.
 */

 // --- Include Files ---

#pragma once
#include "cNode.h"

/// <summary> Class to represent a singly-linked list. </summary>
class cList
{
protected:

	// --- Data members ---

	cNode* mHead;		// Pointer to the first node in the list.
	cNode* mCurrent;    // Pointer to the current node in the list.
	int mNodes;			// Number of nodes in the list.

public:

	// --- Constructors and Destructors ---

	/// <summary> Default constructor. </summary>
	cList();
	/// <summary> Default destructor. </summary>
	~cList();


	// --- Methods ---

	// ------ Insert Methods ------

	/// <summary> Inserts a new node at the start of the list. </summary>
	/// <param name="_key"> The key of the new node as an Integer </param>
	/// <param name="_value"> The value of the new node as a Float </param>
	void InsertHead(const int _key, const float _value);
	/// <summary> Inserts a new node at the end of the list. </summary>
	/// <param name="_key"> The key of the new node as an Integer </param>
	/// <param name="_value"> The value of the new node as a Float </param>
	void InsertTail(const int _key, const float _value);
	/// <summary> Inserts a new node at position '<code>_position</code>' in the list </summary>
	/// <param name="_position"> The position to insert the new node as an Integer </param>
	/// <param name="_key"> The key of the new node as an Integer </param>
	/// <param name="_value"> The value of the new node as a Float </param>
	/// <remarks> Remember head/start of list is position 0. </remarks>
	void InsertBody(const int _position, const int _key, const float _value);


	// ------ Delete Methods ------

	/// <summary> Deletes the head node from the list. </summary>
	void DeleteHead();
	/// <summary> Deletes the tail node from the list. </summary>
	void DeleteTail();
	/// <summary> Deletes the node at position '<code>_position</code>' from the list. </summary>
	/// <param name="_position"> The position of the node to delete as an Integer </param>
	void DeleteBody(int _position) const;


	// ------ Additional Methods ------

	/// <summary> Returns the node at '<code>_position</code>' in the list. </summary>
	/// <param name="_position"> The position of the node to return as an Integer </param>
	/// <returns> A pointer to the node at position '<code>_position</code>'. </returns>
	cNode* GetNode(int _position);
	/// <summary> Returns the node with the key value '<code>_key</code>' in the list. </summary>
	/// <param name="_key"> The key of the node to return as an Integer </param>
	/// <returns> A pointer to the node with the key value '<code>_key</code>' </returns>
	cNode* FindNode(int _key);
	/// <summary> Returns the number of nodes in the list. </summary>
	///	<returns> The number of nodes in the list as an Integer </returns>
	int NumNodes();
	/// <summary> Checks if a node with the key value '<code>_key</code>' exists in the list. </summary>
	///	<param name="_key"> The key of the node to check for as an Integer </param>
	///	<returns> True if a node with the key value '<code>_key</code>' exists in the list, false otherwise. </returns>
	bool NodeExists(int _key);

	// Todo: Extend the classes and methods above to implement a "current" node pointer and a set of methods to move it around the list.
};