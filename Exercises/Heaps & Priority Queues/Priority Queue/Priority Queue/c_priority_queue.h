// /***********************************************************************
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
// (c) 2024 Media Design School
// File Name : c_priority_queue.h
// Description : The priority queue is a special type of queue in which every
//				 element is associated with a priority value. The element that
//				 has the highest priority is the one that is served first.
// Author : Foster Rae
// Mail : Foster.Rae@mds.ac.nz
// ************************************************************************/

#pragma once
class c_item;
#include <vector>
#include <iostream>
#include <algorithm>

class c_priority_queue
{
public:
	// *** Constructors & Destructor ***
	c_priority_queue();
	~c_priority_queue();

	// *** Public Functions ***
	void push(c_item* item); // Add an item to the queue
	c_item* pop(); // Return the item with the highest priority and remove it from the queue
	int get_length(); // Return the number of items in the queue
	float priority_front(); // Return the priority of the item at the front of the queue, without removing it

	void heapify(); // Rearrange the heap to maintain the heap property (parent is greater than children)
	int parent(const int i){ return (i - 1) / 2; } // Return the index of the parent of the item at index i
	int left(const int i){ return ((2 * i) + 1); } // Return the index of the left child of the item at index i
	int right(const int i){return ((2 * i) + 2); } // Return the index of the right child of the item at index i

	// *** The heap ***
	std::vector<c_item*> m_heap_; // The heap is stored in a vector

};

