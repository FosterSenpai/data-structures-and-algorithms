#pragma once

class cNode
{
	// Data members
	int mKey; // Unique key for each node.
	float mValue; // Value of the node.
	cNode* mNext; // Pointer to the next cNode.

public:
	// Constructors
	///
	/// <summary> Default constructor. </summary>
	/// <param name="_key"> The Unique key of the node as an Integer </param>
	cNode(int _key);
	///
	/// <summary> Default destructor. </summary>
	~cNode();

	// Accessors

	/// <summary> Get the key of the node. </summary>
	/// <returns> The key of the node as an Integer </returns>
	int GetKey() const;
	/// <summary> Set the value of the node. </summary>
	/// <param name="_value"> The value to set the node to as a Float </param>
	void SetValue(float _value);
	/// <summary> Get the value of the node. </summary>
	/// <returns> The value of the node as a Float </returns>
	float GetValue();
	/// <summary> Set the next node. </summary>
	/// <param name="_next"> The next node to set as a cNode pointer </param>
	void SetNext(cNode* _next);
	/// <summary> Get the next node. </summary>
	/// <returns> A pointer to the next cNode </returns>
	cNode* GetNext();

};