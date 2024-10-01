#include "c_priority_queue.h"
#include <algorithm>
#include <stdexcept>

/**
 * @brief Define the comparator for the priority queue.\n
 *	The comparator is used to determine the order of the items in the priority queue.\n
 * @param item_a The first item to compare.
 * @param item_b The second item to compare.
 * @return True if the first item has a higher priority than the second item, false otherwise.
 */
struct s_comparator
{
	// Overload the function call operator to compare two items.
	bool operator()(const c_item& item_a, const c_item& item_b) const
	{
		return item_a.get_priority() < item_b.get_priority(); // Compare the priorities of the two items.
	}
};

void c_priority_queue::push(const c_item& item) 
{
	mv_heap_.push_back(item); // Add the new item to the end of the heap.
	// push_heap is used to heapify the heap after adding the new item.
	std::push_heap(mv_heap_.begin(), mv_heap_.end(), s_comparator());
}

c_item c_priority_queue::pop()
{
	// If the heap is empty, throw an exception.
	if (mv_heap_.empty())
	{
		throw std::runtime_error("Priority queue is empty.");
	}

	// Pop the item with the highest priority from the heap, moving it to the back of the heap.
	std::pop_heap(mv_heap_.begin(), mv_heap_.end(), s_comparator());
	c_item item = mv_heap_.back(); 	// Get the item from the back of the heap.
	mv_heap_.pop_back();			// Remove the item from the back of the heap.
	return item;					// Return the item that was popped.
}

float c_priority_queue::priority_front() const
{
	if (mv_heap_.empty())
	{
		throw std::runtime_error("Priority queue is empty.");
	}

	const c_item item = mv_heap_.front(); // Get the item with the highest priority from the heap.
	return item.get_priority();           // Return the priority of the item.
}
