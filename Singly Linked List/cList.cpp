#include "cList.h"

#include <iostream>
#include <vcruntime.h>

// --- Constructors and Destructors ---

cList::cList() : mNodes(0)
{
	mHead = nullptr;
	mCurrent = nullptr;
	mNodes = 0;
}

cList::~cList()
{
	cNode* pDelete = mHead;	   // Pointer or the node to delete, starting at the head.
	cNode* pNext = nullptr;    // Pointer to the node after the node to delete.

	// Move through the list deleting each node.
	while (pDelete != nullptr)
	{

		pNext = pDelete->GetNext();
		delete pDelete;
		pDelete = pNext;

	}
}

// --- Methods ---

void cList::InsertHead(const int _key, const float _value)
{
	// Todo: Add input validation to ensure that the key is unique.
	// if (NodeExists(_key)) throw exception

	// Create the new node.
	cNode* pNew = new cNode(_key);
	pNew->SetValue(_value);

	// Insert the new node at the head of the list.
	pNew->SetNext(mHead);    // Set the 'next' node of the new node to the old head node.
	mHead = pNew;			 // Set the new node as the head node.
	mNodes++;
}

void cList::InsertTail(const int _key, const float _value)
{
	// Create the new node.
	cNode* pNew = new cNode(_key);
	pNew->SetValue(_value);

	if (mHead != nullptr)   // If the list is not empty.
	{

		cNode* pTail = mHead;    // Pointer for the last node, starts at the head to traverse the list.
		while (pTail->GetNext() != nullptr)
		{
			pTail = pTail->GetNext();
		}
		pTail->SetNext(pNew);    // When the last node is found, set its 'next' node to the new node.

	}
	else 					// If the list is empty.
	{

		mHead = pNew;			 // Set the new node as the head node.

	}

	mNodes++;
}

void cList::InsertBody(const int _position, const int _key, const float _value)
{
	if (_position < 0 || _position > mNodes)   // Range check.
	{

		// Todo: Throw exception.
		std::cout << "Position selected out of range." << '\n';
		return;

	}

	// Create the new node.
	cNode* pNew = new cNode(_key);
	pNew->SetValue(_value);

	if (_position == 0) // If the new node is to be inserted at the head. Optimises by removing the need to traverse the list.
	{
		pNew->SetNext(mHead);
		mHead = pNew;
	}
	else
	{
		cNode* pCurrent = mHead;     // Pointer to the current node, starting at the head.
		int iCurrentPosition = 0;    // Variable to hold the current position in the list.

		while (iCurrentPosition < _position - 1)    // Move through the list to the insertion point.
		{
			pCurrent = pCurrent->GetNext();
			iCurrentPosition++;
		}

		// When the insertion point is reached, insert the new node.
		pNew->SetNext(pCurrent->GetNext());
		pCurrent->SetNext(pNew);
	}

	mNodes++;
}

void cList::DeleteHead()
{
	if (mHead != nullptr)    // Check if the list is not empty.
	{
		const cNode* pOldHead = mHead;     // Create a pointer to the current head.
		mHead = mHead->GetNext();    // Set the head to the next node.
		delete pOldHead;
		mNodes--;
	}
}

void cList::DeleteTail()
{
	if (mNodes <= 0 || mHead == nullptr)    // If the list is empty.
	{

		// Todo: Throw exception.
		std::cout << "List is empty." << '\n';
		return;

	}

	if (mNodes == 1)    // If the list only has one node.
	{

		// Delete the head node & return before needing to traverse the list.
		DeleteHead();
		return;

	}

	// Traverse the list until the second to last node is reached.
	cNode* pCurrent = mHead;
	while (pCurrent->GetNext()->GetNext() != nullptr)    // Can check two nodes ahead this way.
	{
		pCurrent = pCurrent->GetNext();
	}

	// Delete the last node.
	delete pCurrent->GetNext();
	pCurrent->SetNext(nullptr);
	mNodes--;
}








// Todo: Implement DeleteBody, GetNode, FindNode, NumNodes, NodeExists.


void cList::DeleteBody(int _position) const
{
	// if num nodes < _position throw error
	// move _position amount of nodes through list

	if (mNodes < _position || mNodes == 0)
	{
		std::cout << "Position selected out of range."; //throw exception
	}
	else if (_position == 0) // If first node (head)
	{
		// TODO: SOMETHING GOING ON WITH CONST SHIT
		DeleteHead();
	}
	else if (_position == mNodes - 1)// If last node (tail)
	{
	}

	{
		cNode* pCurrent = mHead; // Create a pointer to the current node and set it to the head node.

		while (pCurrent->GetNext() != nullptr) // While the next node isn't nullptr. This goes through the list until the last node is reached.
		{
			cNode* pPrevious = pCurrent; // Save the node before the current node.
			pCurrent = pCurrent->GetNext(); // Set the current node to the next node.
		}

		// move _position amount of nodes through list.
		// save previous node
		// save node to delete as current node
		// set previous nodes 'next' node to the 'next' node of the current node.
		// delete current node.
	}
}

cNode* cList::GetNode(int _position)
{
}

cNode* cList::FindNode(int _key)
{
}

int cList::NumNodes()
{
}

bool cList::NodeExists(int _key)
{
}