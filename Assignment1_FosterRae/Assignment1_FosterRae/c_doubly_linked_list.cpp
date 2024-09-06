#include "c_doubly_linked_list.h"

#include <iostream>

// *** Constructor & Destructor ***
/**
 * @brief Creates an empty doubly-linked list
 */
c_doubly_linked_list::c_doubly_linked_list() : head_node_(nullptr), tail_node_(nullptr), size_(0) {} // Values set with member initializer list

c_doubly_linked_list::~c_doubly_linked_list()
{
	c_node* current_node = head_node_; // current_node is the node to be deleted, starting at the head
	c_node* next_node = nullptr;       // next_node is the node to be deleted next

	// Traverse the list and delete each node
	while (current_node != nullptr)           // Loop until the end of the list
	{
		next_node = current_node->get_next(); // Store the next node
		delete current_node;                  // Delete the current node
		current_node = next_node;             // Move to the next node
	}
}

// *** Methods ***
// ** Utility **

bool c_doubly_linked_list::is_key_unique(int key) const
{
	c_node* current_node = head_node_; // current_node is the node to be checked, starting at the head

	// Traverse the list and check if there are any keys that match
	while (current_node != nullptr)                                // Loop until the end of the list
	{
		if (current_node->get_key() == key)                        // If the key is found
		{
			return false;                                          // Return false, as the key is not unique
		}
		current_node = current_node->get_next();                   // Otherwise, move to the next node
	}

	return true;                                                   // If the loop completes without finding a matching key, return true
}

c_node* c_doubly_linked_list::get_node_from_position(int position) const
{
	// Check if the position is valid
	if (position < 0 || position >= size_)
	{
		std::cout << "Error: Position " << position << " is out of bounds." << '\n';
		return nullptr;
	}

	// Traverse the list to find the node at the given position
	c_node* current_node = head_node_; // current_node is the node to be returned, starting at the head
	for (int i = 0; i < position; i++) // Loop until the given position
	{
		if (current_node == nullptr) // Additional check to ensure current_node is not null
		{
			std::cout << "Error: Unexpected null node at position " << i << '\n';
			return nullptr;
		}
		current_node = current_node->get_next(); // Move to the next node
	}

	return current_node; // Return the node at the given position
}

c_node* c_doubly_linked_list::get_node_from_key(int key) const
{
	c_node* current_node = head_node_; // current_node is the node to be returned, starting at the head

	// Traverse the list to find the node with the given key
	while (current_node != nullptr) // Loop until the end of the list
	{
		if (current_node->get_key() == key)      // If the key is found
		{
			return current_node;                 // Return the node
		}
		current_node = current_node->get_next(); // Otherwise, move to the next node
	}

	return nullptr; // If the key is not found, return nullptr
}

c_node* c_doubly_linked_list::get_node_from_name(const std::string& name) const
{
	c_node* current_node = head_node_; // current_node is the node to be returned, starting at the head

	// Traverse the list to find the node with the given name
	while (current_node != nullptr) // Loop until the end of the list
	{
		if (current_node->get_item().get_name() == name) // If the name is found
		{
			return current_node;                          // Return the node
		}
		current_node = current_node->get_next();          // Otherwise, move to the next node
	}

	return nullptr; // If the name is not found, return nullptr
}

c_node* c_doubly_linked_list::get_node_from_type(c_item::item_type type) const
{
	c_node* current_node = head_node_; // current_node is the node to be returned, starting at the head

	// Traverse the list to find the node with the given type
	while (current_node != nullptr) // Loop until the end of the list
	{
		if (current_node->get_item().get_type() == type) // If the type is found
		{
			return current_node;                          // Return the node
		}
		current_node = current_node->get_next();          // Otherwise, move to the next node
	}

	return nullptr; // If the type is not found, return nullptr
}

c_node* c_doubly_linked_list::get_lowest_price() const
{
	// Check if the list is empty
	if (head_node_ == nullptr)
	{
		std::cout << "Error: List is empty." << '\n';
		return nullptr;
	}

	c_node* lowest_price_node = head_node_; 				 // lowest_price_node is the node with the lowest price, starting at the head
	float lowest_price = head_node_->get_item().get_price(); // lowest_price is the price of the lowest_price_node

	// Traverse the list to find the node with the lowest price
	for (c_node* current_node = head_node_; current_node != nullptr; current_node = current_node->get_next()) // Loop until the end of the list
	{
		if (current_node->get_item().get_price() < lowest_price) // If the price is lower than the current lowest price
		{
			lowest_price = current_node->get_item().get_price(); // Update the lowest price
			lowest_price_node = current_node;                    // Update the lowest price node
		}
	}

	return lowest_price_node; // Return the node with the lowest price
}

c_node* c_doubly_linked_list::get_highest_price() const
{
	// Check if the list is empty
	if (head_node_ == nullptr)
	{
		std::cout << "Error: List is empty." << '\n';
		return nullptr;
	}

	c_node* highest_price_node = head_node_; 				  // highest_price_node is the node with the highest price, starting at the head
	float highest_price = head_node_->get_item().get_price(); // highest_price is the price of the highest_price_node

	// Traverse the list to find the node with the highest price
	for (c_node* current_node = head_node_; current_node != nullptr; current_node = current_node->get_next()) // Loop until the end of the list
	{
		if (current_node->get_item().get_price() > highest_price) // If the price is higher than the current highest price
		{
			highest_price = current_node->get_item().get_price(); // Update the highest price
			highest_price_node = current_node;                    // Update the highest price node
		}
	}

	return highest_price_node; // Return the node with the highest price
}

c_node* c_doubly_linked_list::get_lowest_quantity() const
{
	// Check if the list is empty
	if (head_node_ == nullptr)
	{
		std::cout << "Error: List is empty." << '\n';
		return nullptr;
	}

	c_node* lowest_quantity_node = head_node_; 					 // lowest_quantity_node is the node with the lowest quantity, starting at the head
	int lowest_quantity = head_node_->get_item().get_quantity(); // lowest_quantity is the quantity of the lowest_quantity_node

	// Traverse the list to find the node with the lowest quantity
	for (c_node* current_node = head_node_; current_node != nullptr; current_node = current_node->get_next()) // Loop until the end of the list
	{
		if (current_node->get_item().get_quantity() < lowest_quantity) // If the quantity is lower than the current lowest quantity
		{
			lowest_quantity = current_node->get_item().get_quantity(); // Update the lowest quantity
			lowest_quantity_node = current_node;                    // Update the lowest quantity node
		}
	}

	return lowest_quantity_node; // Return the node with the lowest quantity
}

c_node* c_doubly_linked_list::get_highest_quantity() const
{
	// Check if the list is empty
	if (head_node_ == nullptr)
	{
		std::cout << "Error: List is empty." << '\n';
		return nullptr;
	}

	c_node* highest_quantity_node = head_node_; 				  // highest_quantity_node is the node with the highest quantity, starting at the head
	int highest_quantity = head_node_->get_item().get_quantity(); // highest_quantity is the quantity of the highest_quantity_node

	// Traverse the list to find the node with the highest quantity
	for (c_node* current_node = head_node_; current_node != nullptr; current_node = current_node->get_next()) // Loop until the end of the list
	{
		if (current_node->get_item().get_quantity() > highest_quantity) // If the quantity is higher than the current highest quantity
		{
			highest_quantity = current_node->get_item().get_quantity(); // Update the highest quantity
			highest_quantity_node = current_node;                       // Update the highest quantity node
		}
	}

	return highest_quantity_node; // Return the node with the highest quantity
}

int c_doubly_linked_list::calculate_size(c_node* head) const
{
	if (head == nullptr)
	{
		std::cout << "Error: Head node is null." << '\n';
		return 0;
	}

	int count = 0;
	c_node* current_node = head;

	// Traverse the list and count the number of nodes
	while (current_node != nullptr)
	{
		if (current_node->get_next() == current_node)
		{
			std::cout << "Error: Circular reference detected at node with key " << current_node->get_key() << '\n';
			return count;
		}

		count++;
		current_node = current_node->get_next();
	}

	// Check if the count matches the size of the list
	if (count != size_)
	{
		std::cout << "Error: List size does not match the number of nodes counted." << '\n';
	}

	return count;
}

bool c_doubly_linked_list::key_exists(const int key) const
{
	c_node* current_node = head_node_; // current_node is the node to be checked, starting at the head

	// Traverse the list and check if the key exists
	while (current_node != nullptr) // Loop until the end of the list
	{
		if (current_node->get_key() == key)      // If the key is found
		{
			return true; 					     // Return true
		}
		current_node = current_node->get_next(); // Otherwise, move to the next node
	}

	return false; // If the key is not found, return false
}

bool c_doubly_linked_list::is_empty() const
{
	return head_node_ == nullptr; // Will return true if the head is nullptr (i.e. the list is empty)
}

void c_doubly_linked_list::swap(c_node* a, c_node* b)
{
	// nullptr check
	if (a == nullptr || b == nullptr)
	{
		std::cout << "Error: One or both nodes are nullptr." << '\n';
		return;
	}

	c_item temp_item = a->get_item(); // Store the item of node a
	int temp_key = a->get_key();       // Store the key of node a

	a->set_item(b->get_item()); // Set the item of node a to the item of node b
	a->set_key(b->get_key());   // Set the key of node a to the key of node b

	b->set_item(temp_item); // Set the item of node b to the stored item of node a
	b->set_key(temp_key);   // Set the key of node b to the stored key of node a
}

// ** Insertion **
void c_doubly_linked_list::insert_head(int key, const c_item& item)
{
	// Check if the key is unique
	if (!is_key_unique(key))
	{
		std::cout << "Error: Key is not unique." << '\n';
		return;
	}

	// Create a new node with the given key and item
	c_node* new_node = new c_node(key, item);

	// If the list is empty, set the new node as the head and tail
	if (head_node_ == nullptr)
	{
		head_node_ = new_node;
		tail_node_ = new_node;
	}
	else // If the list is not empty
	{
		// Set the new node as the head and link it to the current head
		new_node->set_next(head_node_); // Set the next pointer of the new node to the current head
		head_node_->set_prev(new_node); // Set the previous pointer of the current head to the new node
		head_node_ = new_node;          // Set the new node as the head, replacing the current head

		// Note: The previous pointer of the new head is already nullptr
	}

	size_++; // Increment the size of the list
}
void c_doubly_linked_list::insert_tail(int key, const c_item& item)
{
	// Check if the key is unique
	if (!is_key_unique(key))
	{
		std::cout << "Error: Key is not unique." << '\n';
		return;
	}

	// Create a new node with the given key and item
	c_node* new_node = new c_node(key, item);

	// If the list is empty, set the new node as the head and tail
	if (head_node_ == nullptr)
	{
		head_node_ = new_node;
		tail_node_ = new_node;
	}
	else // If the list is not empty
	{
		// Set the new node as the tail and link it to the current tail
		new_node->set_prev(tail_node_); // Set the previous pointer of the new node to the current tail
		tail_node_->set_next(new_node); // Set the next pointer of the current tail to the new node
		tail_node_ = new_node;          // Set the new node as the tail, replacing the current tail

		// Note: The next pointer of the new tail is already nullptr
	}

	size_++; // Increment the size of the list
}
void c_doubly_linked_list::insert_body(int key, const c_item& item, int position)
{
	// Check if position is out of bounds
	if (position < 0 || position > size_)
	{
		std::cout << "Error: Position is out of bounds." << '\n';
		return;
	}

	// Check if the key is unique
	if (!is_key_unique(key))
	{
		std::cout << "Error: Key is not unique." << '\n';
		return;
	}

	// Create a new node with the given key and item
	c_node* new_node = new c_node(key, item);

	// If the list is empty or the position is at the head
	if (head_node_ == nullptr || position == 0)
	{
		insert_head(key, item); // Insert the new node at the head
	}
	else if (position == size_) // If the position is at the tail
	{
		insert_tail(key, item); // Insert the new node at the tail
	}
	else // If the position is in the body of the list
	{
		// Traverse the list to find the node at the given position
		c_node* current_node = head_node_; // current_node is the node to be replaced, starting at the head
		for (int i = 0; i < position; i++) // Loop until the given position
		{
			current_node = current_node->get_next(); // Move to the next node
		}

		// Insert the new node in the body of the list
		new_node->set_next(current_node);             // Set the next pointer of the new node to the node at the given position
		new_node->set_prev(current_node->get_prev()); // Set the previous pointer of the new node to the previous node of the node at the given position
		current_node->get_prev()->set_next(new_node); // Set the next pointer of the previous node of the node at the given position to the new node, linking it to the new node
		current_node->set_prev(new_node);             // Set the previous pointer of the current node to the new node, Finish linking the new node to the list

		size_++; // Increment the size of the list
	}
}

// ** Deletion **
void c_doubly_linked_list::delete_head()
{
	// Check if the list is empty
	if (head_node_ == nullptr)
	{
		std::cout << "Error: List is empty." << '\n';
		return;
	}

	c_node* current_node = head_node_;   // current_node is the node to be deleted, starting at the head
	head_node_ = head_node_->get_next(); // Move the head to the next node

	// Pointer safety check
	if (head_node_ != nullptr) // If the next node of the head was not nullptr (i.e. the list is not empty)
	{
		head_node_->set_prev(nullptr);     // Set the previous pointer of the new head to nullptr
	}
	else                       // If the list is now empty
	{
		tail_node_ = nullptr;              // Set the tail to nullptr
	}

	delete current_node; // Delete the current node
	size_--;
}
void c_doubly_linked_list::delete_tail()
{
	// Check if the list is empty
	if (head_node_ == nullptr)
	{
		std::cout << "Error: List is empty." << '\n';
		return;
	}

	// Check if the list has only one node (Didn't use delete_head() because it would be less efficient)
	if (head_node_ == tail_node_)
	{
		delete head_node_;    // Delete the head node (and tail node)
		head_node_ = nullptr; // Set the head to nullptr
		tail_node_ = nullptr; // Set the tail to nullptr
		size_--;
		return;
	}

	c_node* current_node = tail_node_;   // current_node is the node to be deleted, starting at the tail
	tail_node_ = tail_node_->get_prev(); // Move the tail to the previous node

	// Pointer safety check
	if (tail_node_ != nullptr) // If the previous node of the tail was not nullptr (i.e. the list is not empty)
	{
		tail_node_->set_next(nullptr);     // Set the next pointer of the new tail to nullptr
	}
	else                       // If the list is now empty
	{
		head_node_ = nullptr;              // Set the head to nullptr
	}

	delete current_node; // Delete the current node
	size_--;
}

void c_doubly_linked_list::delete_body(int position)
{
	// Check if the position is valid
	if (position <= 0 || position >= size_ - 1)
	{
		std::cerr << "Error: Invalid position for body deletion.\n";
		return;
	}

	// Get the node to be deleted
	c_node* node_to_delete = get_node_from_position(position);
	if (node_to_delete == nullptr)
	{
		std::cerr << "Error: Node to delete not found.\n";
		return;
	}

	// Get the previous and next nodes
	c_node* prev_node = node_to_delete->get_prev();
	c_node* next_node = node_to_delete->get_next();

	// Update the previous node's next pointer
	if (prev_node != nullptr)
	{
		prev_node->set_next(next_node);
	}

	// Update the next node's previous pointer
	if (next_node != nullptr)
	{
		next_node->set_prev(prev_node);
	}

	// Delete the node
	delete node_to_delete;

	// Decrement the size of the list
	size_--;
}

void c_doubly_linked_list::quick_sort_ascending(c_node* low, c_node* high, int sort_choice)
{
	// Ensure the pointers are valid
	if (low == nullptr || high == nullptr)
	{
		return;
	}

	// Ensure there is more than one element to sort
	if (low == high || low == high->get_next())
	{
		return;
	}

	// Ensure that 'low' comes before 'high'
	c_node* temp = low;
	while (temp != nullptr && temp != high)
	{
		temp = temp->get_next();
	}
	if (temp != high)
	{
		return;
	}
	// Partition the list and get the pivot node
	c_node* pivot = partition_ascending(low, high, sort_choice);

	// Recursively sort the elements before and after the pivot
	quick_sort_ascending(low, pivot->get_prev(), sort_choice);
	quick_sort_ascending(pivot->get_next(), high, sort_choice);
}

void c_doubly_linked_list::quick_sort_descending(c_node* low, c_node* high, int sort_choice)
{
	// Ensure the pointers are valid
	if (low == nullptr || high == nullptr)
	{
		return;
	}
	// Ensure there is more than one element to sort
	if (low == high || low == high->get_next())
	{
		return;
	}

	// Ensure that 'low' comes before 'high'
	c_node* temp = low;
	while (temp != nullptr && temp != high)
	{
		temp = temp->get_next();
	}
	if (temp != high)
	{
		return;
	}

	// Partition the list and get the pivot node
	c_node* pivot_node = partition_descending(low, high, sort_choice);

	// Recursively sort the elements before and after the pivot
	quick_sort_descending(low, pivot_node->get_prev(), sort_choice);  // Sort the left sublist
	quick_sort_descending(pivot_node->get_next(), high, sort_choice); // Sort the right sublist
}

c_node* c_doubly_linked_list::partition_ascending(c_node* low, c_node* high, int sort_choice)
{
	c_item pivot = high->get_item();  // Select the pivot as the last element
	c_node* i = low->get_prev();      // 'i' is the index of the node containing the last element less than or equal to the pivot

	// Traverse through the list from low to high and move elements less than the pivot to the left
	for (c_node* j = low; j != high; j = j->get_next())
	{
		bool condition = false; // Condition to compare the elements

		switch (sort_choice)    // switch statement to compare the elements based on column being sorted, returns true if the condition is met
		{
		case 0: // Name
			condition = j->get_item().compare_by_name(pivot);
			break;
		case 1: // Type
			condition = j->get_item().compare_by_type(pivot);
			break;
		case 2: // Price
			condition = j->get_item().compare_by_price(pivot);
			break;
		case 3: // Quantity
			condition = j->get_item().compare_by_quantity(pivot);
			break;
		default:
			condition = j->get_item() < pivot;
			break;
		}

		// If the condition is true for the column being sorted, swap the elements
		if (condition)
		{
			i = (i == nullptr) ? low : i->get_next();
			swap(i, j);
		}
	}
	i = (i == nullptr) ? low : i->get_next(); // If 'i' is null, move to the next node
	swap(i, high);                       // Swap the pivot with the element at index i
	return i;                            // Return a pointer to the node containing the pivot item
}

c_node* c_doubly_linked_list::partition_descending(c_node* low, c_node* high, int sort_choice)
{
	c_item pivot = high->get_item();  // Select the pivot as the last element
	c_node* i = low->get_prev();      // 'i' is the index of the node containing the last element greater than or equal to the pivot

	// Traverse through the list from low to high and move elements greater than the pivot to the left
	for (c_node* j = low; j != high; j = j->get_next())
	{
		bool condition = false; // Condition to compare the elements

		switch (sort_choice)    // switch statement to compare the elements based on column being sorted, returns true if the condition is met
		{
		case 0: // Name
			condition = !j->get_item().compare_by_name(pivot);
			break;
		case 1: // Type
			condition = !j->get_item().compare_by_type(pivot);
			break;
		case 2: // Price
			condition = !j->get_item().compare_by_price(pivot);
			break;
		case 3: // Quantity
			condition = !j->get_item().compare_by_quantity(pivot);
			break;
		default:
			condition = j->get_item() > pivot;
			break;
		}

		// If the condition is true for the column being sorted, swap the elements
		if (condition)
		{
			i = (i == nullptr) ? low : i->get_next();
			swap(i, j);
		}
	}
	i = (i == nullptr) ? low : i->get_next(); // if 'i' is null, move to the next node
	swap(i, high);                       // Swap the pivot with the element at index i
	return i;                                 // Return a pointer to the node containing the pivot item
}