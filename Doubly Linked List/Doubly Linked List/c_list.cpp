#include "c_list.h"
#include <iostream>

// ==================== Constructors and Destructors ====================

c_list::c_list()
{
	head_node_ = nullptr;
	tail_node_ = nullptr;
	current_node_ = nullptr;
	size_ = 0;
}

c_list::~c_list()
{
	c_node* deletion_node = head_node_; // Node to delete, starting at the head
	c_node* next_node = nullptr;        // Node to move to next

	while (deletion_node != nullptr) // While there are nodes to delete
	{
		next_node = deletion_node->get_next(); // Get the next node
		delete deletion_node;                  // Delete the current node
		deletion_node = next_node;             // Move to the next node
	}
}

// ========================== Member Functions ==========================

//                     ***** Insert Functions *****

/**
 * @brief Insert a node at the head of the list
 * @param key Key of the node
 * @param data Data of the node
 */
void c_list::insert_head(const int key, const float data)
{

	c_node* new_node = new c_node(key, data, nullptr, head_node_); // Create node, using constructor with key, data and pointers

	if (head_node_ != nullptr) // If the list is not empty
	{
		head_node_->set_prev(new_node); // Set the previous pointer of the current head to the new node
	}
	else // If the list is empty, set 
	{
		head_node_ = new_node;
		tail_node_ = new_node;

	}
	size_++;
}

void c_list::insert_tail(const int key, const float data)
{
	c_node* new_node = new c_node(key, data, tail_node_, nullptr); // Create node, using constructor with key, data and pointers

	if (head_node_ == nullptr) // If the list is empty, set the head and tail to the new node
	{
		head_node_ = new_node;
		tail_node_ = new_node;
		size_++;
		return;
	}
	else
	{
		
	}


	size_++;

}

void c_list::insert_body(const int key, const float data)
{
}


//                     ***** Delete Functions *****

void c_list::delete_head()
{
}

void c_list::delete_tail()
{
}

void c_list::delete_body()
{
}


// 					   ***** Accessor Functions *****

void c_list::get_node_from_position(int position) const
{
}

void c_list::get_node_from_key(int key) const
{
}

int c_list::list_size(c_node* head) const
{
    int count = 0;

    // Traverse the list and count the number of nodes
    for (c_node* current_node = head; current_node != nullptr; current_node = current_node->get_next())
    {
        count++;
    }

	// Check to see if all inserts and deletes have been incrementing and decrementing the size variable correctly.
    if (count != size_)
    {
        std::cerr << "Error: Size variable does not match the number of nodes in the list\n";
    }

    return count;
}


//                     ***** Utility Functions *****

bool c_list::node_exists(int key) const
{
	return false;
}

void c_list::traverse_forward(c_node* head)
{
	c_node* current_node = head; // Start at the head

	while (current_node != nullptr) // While there are nodes to traverse
	{
		// Print the key and data of the current node
		std::cout << "| Key: " << current_node->get_key() << " Data: " << current_node->get_data() << " |\n";
		current_node = current_node->get_next(); // Move to the next node
	}

	std::cout << '\n';
}

void c_list::traverse_backward(c_node* tail)
{
	c_node* current_node = tail; // Start at the tail

	while (current_node != nullptr) // While there are nodes to traverse
	{
		// Print the key and data of the current node
		std::cout << "| Key: " << current_node->get_key() << " Data: " << current_node->get_data() << " |\n";
		current_node = current_node->get_prev(); // Move to the previous node
	}

	std::cout << '\n';
}

void c_list::print_list() const
{
}

        
