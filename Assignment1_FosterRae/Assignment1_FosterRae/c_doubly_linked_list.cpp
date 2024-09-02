#include "c_doubly_linked_list.h"

#include <iostream>

// *** Constructor & Destructor ***
/**
 * @brief Creates an empty doubly-linked list
 */
c_doubly_linked_list::c_doubly_linked_list(): head_node_(nullptr), tail_node_(nullptr), size_(0) {} // Values set with member initializer list

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
		std::cout << "Error: Position is out of bounds." << std::endl;
		return nullptr;
	}

	// Traverse the list to find the node at the given position
	c_node* current_node = head_node_; // current_node is the node to be returned, starting at the head
	for (int i = 0; i < position; i++) // Loop until the given position
	{
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

int c_doubly_linked_list::calculate_size(c_node* head) const
{
	int count = 0;
	// Traverse the list and count the number of nodes
	for (c_node* current_node = head; current_node != nullptr; current_node = current_node->get_next())
	{
		count++;
	}

	// Check if the count matches the size of the list
	if (count != size_) 
	{
		std::cout << "Error: List size does not match the number of nodes counted." << std::endl;
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



// ** Insertion **
void c_doubly_linked_list::insert_head(int key, const c_item& item)
{
	// Check if the key is unique
	if (!is_key_unique(key))
	{
		std::cout << "Error: Key is not unique." << std::endl;
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
		std::cout << "Error: Key is not unique." << std::endl;
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
		std::cout << "Error: Position is out of bounds." << std::endl;
		return;
	}

	// Check if the key is unique
	if (!is_key_unique(key))
	{
		std::cout << "Error: Key is not unique." << std::endl;
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
		c_node* current_node = head_node_; // current_node is the node to be replaced, starting at the head
		// Traverse the list to find the node at the given position
		for (int i = 0; i < position; i++) // Loop until the given position
		{
			current_node = current_node->get_next(); // Move to the next node
		}

		// Insert the new node in the body of the list
		new_node->set_next(current_node); // Set the next pointer of the new node to the node at the given position
		new_node->set_prev(current_node->get_prev()); // Set the previous pointer of the new node to the previous node of the node at the given position
		current_node->get_prev()->set_next(new_node); // Set the next pointer of the previous node of the node at the given position to the new node, linking it to the new node
		current_node->set_prev(new_node); // Set the previous pointer of the current node to the new node, Finish linking the new node to the list

		size_++; // Increment the size of the list
	}
}

// ** Deletion **
void c_doubly_linked_list::delete_head()
{
	// Check if the list is empty
	if (head_node_ == nullptr)
	{
		std::cout << "Error: List is empty." << std::endl;
		return;
	}

	c_node* current_node = head_node_;   // current_node is the node to be deleted, starting at the head
	head_node_ = head_node_->get_next(); // Move the head to the next node

	// Pointer safety check
	if (head_node_ != nullptr) // If the next node of the head was not nullptr (i.e. the list is not empty)
	{
		head_node_->set_prev(nullptr); // Set the previous pointer of the new head to nullptr
	}
	else // If the list is now empty
	{
		tail_node_ = nullptr; // Set the tail to nullptr
	}

	delete current_node; // Delete the current node
	size_--;
}
void c_doubly_linked_list::delete_tail()
{
	// Check if the list is empty
	if (head_node_ == nullptr)
	{
		std::cout << "Error: List is empty." << std::endl;
		return;
	}

	// Check if the list has only one node (Didn't use delete_head() because it would be less efficient)
	if (head_node_ == tail_node_)
	{
		delete head_node_; // Delete the head node (and tail node)
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
		tail_node_->set_next(nullptr); // Set the next pointer of the new tail to nullptr
	}
	else // If the list is now empty
	{
		head_node_ = nullptr; // Set the head to nullptr
	}

	delete current_node; // Delete the current node
	size_--;
}
void c_doubly_linked_list::delete_body(int position)
{
	// Check if the list is empty
	if (head_node_ == nullptr)
	{
		std::cout << "Error: List is empty." << std::endl;
		return;
	}

	// Check if position is out of bounds
	if (position < 0 || position >= size_)
	{
		std::cout << "Error: Position is out of bounds." << std::endl;
		return;
	}

	c_node* current_node = get_node_from_position(position); // current_node is the node to be deleted

	// If the position is at the head
	if (current_node == head_node_)
	{
		delete_head(); // Delete the head node
	}
	else if (current_node == tail_node_) // If the position is at the tail
	{
		delete_tail(); // Delete the tail node
	}
	else // If the position is in the body of the list
	{
		current_node->get_prev()->set_next(current_node->get_next()); // Set the next pointer of the previous node to the next node, skipping the current node
		current_node->get_next()->set_prev(current_node->get_prev()); // Set the previous pointer of the next node to the previous node, skipping the current node
		// The current node is now disconnected from the list

		delete current_node; // Delete the current node
		size_--;
	}
}
