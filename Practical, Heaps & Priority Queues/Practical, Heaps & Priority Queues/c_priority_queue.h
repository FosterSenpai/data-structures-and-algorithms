// ************************************************************************
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
// (c) 2024 Media Design School
// File Name : c_priority_queue.h
// Description : ????????? FILL OUT ?????????
// Author : Foster Rae
// Mail : Foster.Rae@mds.ac.nz
// ************************************************************************/

#pragma once
#include <vector>
#include "c_item.h"

/**
 * @brief Class for a priority queue
 * \n\n
 * A priority queue is a data structure that allows for the insertion of elements
 * with a priority and the removal of the element with the highest priority.
 * \n\n
 * This class provides methods to insert elements and remove the element with the highest priority.
 */
class c_priority_queue
{
public:
	// Constructors and Destructors
	c_priority_queue() = default;
	~c_priority_queue() = default;

	// Member Functions
	/**
	 * @brief Pushes an item onto the priority queue.\n
	 * @param item The item to push onto the priority queue, passed as a reference to a constant c_item.
	 */
	void push(const c_item& item);
	/**
	 * @brief Returns the highest priority item and removes it from the queue.\n
	 * @return The item with the highest priority that was popped.
	 */
	c_item pop();
	/**
	 * @brief Returns the number of items in the priority queue.\n
	 * @return The length of the priority queue as an integer.
	 */
	int get_length() const { return mv_heap_.size(); }
	/**
	 * @brief returns the priority of the item at the front of the queue, without popping the item.\n
	 * @return The priority of the item with the highest priority as a float.
	 */
	float priority_front() const;

protected:
	// Member Variables
	std::vector<c_item> mv_heap_;  // The heap that stores the items in the priority queue.
};
