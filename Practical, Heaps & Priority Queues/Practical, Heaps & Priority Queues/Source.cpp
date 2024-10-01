#include <iostream>
#include "c_priority_queue.h"
#include "c_item.h"

//main function
int main()
{
	// Create a priority queue.
	c_priority_queue priority_queue;

	// Create some items to add to the priority queue.
	c_item item1;
	item1.set_identifier("Item 1");
	item1.set_priority(5.0f);

	c_item item2;
	item2.set_identifier("Item 2");
	item2.set_priority(3.0f);

	c_item item3;
	item3.set_identifier("Item 3");
	item3.set_priority(7.0f);

	// Push the items onto the priority queue.
	priority_queue.push(item1);
	priority_queue.push(item2);
	priority_queue.push(item3);

	//Test popping
	//Test pushing
	//Test priority front
	//Test get length
	//Test empty

	return 0;
}