#include "cList.h"

cList::cList() : mNodes(0)
{
	mHead = nullptr;
	mNodes = 0;
}
cList::~cList()
{
	cNode* pDelete = mHead;
	cNode* pNext = nullptr;
	for (int iDelete = 0; iDelete < mNodes; iDelete++)
	{
		pNext = pDelete->GetNext();
		delete pDelete;
		pDelete = pNext;
	}
}

//TODO: Add input validation to ensure that the key is unique.
void cList::InsertHead(int _key, float _value)
{
	if (mNodes <= 0) // If the list is empty.
	{
		mHead = new cNode(_key); // Create a new node with the key value _key. Next is set to nullptr by default.
		mHead->SetValue(_value); // Set the value of the new node to _value.
	}
	else // If the list isn't empty.
	{
		cNode* pOldHead = mHead; // Capture old head node.
		mHead = new cNode(_key); // Create a new node with the key value _key.
		mHead->SetValue(_value); // Set the value of the new node to _value.
		mHead->SetNext(pOldHead); // Set the next node of the new head to the old head node.
	}
	mNodes++; // Increment the number of nodes in the list.
}

//TODO: Add input validation to ensure that the key is unique.
void cList::InsertTail(int _key, float _value)
{
	if (mNodes <= 0) // If the list is empty.
	{
		mHead = new cNode(_key); // If the list is empty the tail would be the head.
		mHead->SetValue(_value); // Set the value of the new node to _value.
	}
	else // If the list isn't empty.
	{
		cNode* pCurrent = mHead; // Create a pointer to the current node and set it to the head node.
		while (pCurrent->GetNext() != nullptr) // While the next node isn't nullptr. This goes through the list until the last node is reached.
		{
			pCurrent = pCurrent->GetNext(); // Set the current node to the next node.
		}
		cNode* pNewNode = new cNode(_key); // Create a new node with the key value _key.
		pNewNode->SetValue(_value); // Set the value of the new node to _value.
		pCurrent->SetNext(pNewNode); // Set the next node of the current node to the new node.
	}
	mNodes++; // Increment the number of nodes in the list.
}

void cList::InsertBody(int _position, int _key, float _value)
{
	if (_position == 0) // If the position is the first node.
	{
		InsertHead(_key, _value);
	}
	else if (_position >= mNodes) // If the position is the last node or greater.
	{
		InsertTail(_key, _value);
	}
	else
	{
		cNode* pCurrent = mHead; // Create a pointer to the current node and set it to the head node.
		for (int i = 0; i < _position; ++i) // Move _position amount of spaces from the head. (Starts at head on first iteration)
		{
			pCurrent = mHead->GetNext(); // Set the current node to the next node.
		}
		cNode* pNewNode = new cNode(_key); // Create a new node with the key value _key.
		pNewNode->SetNext(pCurrent->GetNext()); // Set the next node of the new node to the next node of the current node.
		pCurrent->SetNext(pNewNode); // Set the next node of the current node to the new node.
	}
}

void cList::DeleteHead()
{
	if (mNodes <= 0 || mHead == nullptr) // If the list is empty. Need to handle, deleting nullptr does bad stuff.
	{
		// Throw exception.
		std::cout << "List is empty." << '\n';
	}
	else if (mNodes == 1) // If the list only has one node.
	{
		cNode* pOldHead = mHead; // Create a Pointer to current head.
		mHead = nullptr; // Set Head to nullptr.
		delete pOldHead;
		mNodes--;
	}
	else if (mNodes > 1) // If the list has more than one node.
	{
		cNode* pCurrent = mHead->GetNext(); // Create a pointer to the current node and set it to the next node of the head node.
		cNode* pOldHead = mHead; // Create a pointer to the current head.
		mHead = pCurrent; // Set the head node to the pCurrent node (the next node of the old head).
		delete pOldHead;
		mNodes--;
	}
}

void cList::DeleteTail()
{
	if (mNodes <= 0 || mHead == nullptr) // If the list is empty.
	{
		// Throw exception.
		std::cout << "List is empty." << '\n';
	}
	else if (mNodes == 1) // IF the list only has one node.
	{
		cNode* pOldTail = mHead; // Create a Pointer to current head.
		mHead = nullptr; // Set Head to nullptr.
		delete pOldTail;
		mNodes--;
	}
	else if (mNodes > 1)
	{
		cNode* pPrevious = nullptr; // Create a pointer to hold the second to last node.
		cNode* pCurrent = mHead; // Create a pointer to the current node and set it to the head node.
		while (pCurrent->GetNext() != nullptr) // While the next node isn't nullptr. This goes through the list until the last node is reached.
		{
			pPrevious = pCurrent; // Save the node before the current node.
			pCurrent = pCurrent->GetNext(); // Set the current node to the next node.
		}
		pPrevious->SetNext(nullptr); // Set the second to last nodes 'next' node to nullptr.
		delete pCurrent;
		mNodes--;
	}
}

void cList::DeleteBody(int _position)
{
	// if num nodes < _position throw error
	// move _position amount of nodes through list

	if (mNodes < _position || mNodes == 0)
	{
		std::cout << "Position selected out of range."; //throw exception 
	}
	else if (_position == 0) // If first node (head)
	{

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
