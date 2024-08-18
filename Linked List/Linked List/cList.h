#pragma once
#include "cNode.h"
#include <iostream>
#include "Windows.h"


class cList
{
	// Data members.
	cNode* mHead; // Pointer to the first node in the list.
	int mNodes; // Number of nodes in the list.

public:
	// Constructors.
	///
	/// <summary> Default constructor. </summary>
	cList();
	///
	/// <summary> Default destructor. </summary>
	~cList();

	// Public methods.
	/// <summary> Inserts a new node at the head of the list. </summary>
	/// <param name="_key"> The key of the new node as an Integer </param>
	/// <param name="_value"> The value of the new node as a Float </param>
	void InsertHead(int _key, float _value);
	/// <summary> Inserts a new node at the tail of the list. </summary>
	/// <param name="_key"> The key of the new node as an Integer </param>
	/// <param name="_value"> The value of the new node as a Float </param>
	void InsertTail(int _key, float _value);
	/// <summary> Inserts a new node at position <code>_position</code> in the list </summary>
	/// <param name="_position"> The position to insert the new node as an Integer </param>
	/// <param name="_key"> The key of the new node as an Integer </param>
	/// <param name="_value"> The value of the new node as a Float </param>
	void InsertBody(int _position, int _key, float _value);
	///
	/// <summary> Deletes the head node from the list. </summary>
	void DeleteHead();
	///
	/// <summary> Deletes the tail node from the list. </summary>
	void DeleteTail();
	/// <summary> Deletes the node at position <code>_position</code> from the list. </summary>
	/// <param name="_position"> The position of the node to delete as an Integer </param>
	void DeleteBody(int _position);
	/// <param name="_position"> The position of the node to return as an Integer </param>
	/// <returns> A pointer to the node at position <code>_position</code> </returns>
	cNode* GetNode(int _position);
	/// <param name="_key"> The key of the node to return as an Integer </param>
	/// <returns> A pointer to the node with the key value <code>_key</code> </returns>
	cNode* FindNode(int _key);

	int NumNodes();
	bool NodeExists(int _key);

	// Todo: Extend the classes and methods above to implement a "current" node pointer and a set of methods to move it around the list.

};