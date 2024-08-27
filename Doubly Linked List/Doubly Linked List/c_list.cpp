#include "c_list.h"
#include <iostream>

// ==================== Constructors and Destructors ====================

c_list::c_list()
{
	head_node_ = nullptr;
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
		head_node_ = new_node;          // Set the head to the new node
	}
	else // If the list is empty
	{
		head_node_ = new_node;
	}

	size_++;
}

/**
 * @brief Insert a node at the tail of the list
 * @param key Key of the node
 * @param data Data of the node
 */
void c_list::insert_tail(const int key, const float data)
{
	c_node* new_node = new c_node(key, data);

	if (head_node_ == nullptr)    // If the list is empty
	{
		head_node_ = new_node;
	}
	else                          // If the list is not empty
	{
		current_node_ = head_node_;
		while (current_node_->get_next() != nullptr) // Traverse from the head to the tail.
		{
			current_node_ = current_node_->get_next();
		}

		current_node_->set_next(new_node); // Set the next pointer of old tail to the new node
		new_node->set_prev(current_node_); // Set the previous pointer of the new node to the old tail
		current_node_ = nullptr;
	}
	size_++;
}

void c_list::insert_body(const int key, const float data, int position)
{
	c_node* new_node = new c_node(key, data);

	if (position ==1) // TODO - may be an issue here, test out inserting at pos 1.
	{
		insert_head(key, data);
	}
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
	c_node* current_node = head_node_; // Start at the head
	int position = 1; // Head is position 1, list is 1-indexed
	std::cout << "=============== PRINT LIST ===============" << '\n';
	while (current_node != nullptr) // While there are nodes to traverse
	{

		// Print previous node if it exists
		if(current_node->get_prev() == nullptr)
		{
			std::cout << "NULL <-\n\n";
		}

		// Print positions
		if (position == 1)
		{
			std::cout << "[POS: HEAD";
		}
		else if (current_node->get_next() == nullptr)
		{
			std::cout << "[POS: TAIL";
		}
		else
		{
			std::cout << "[POS: " << position;
		}
		position++; // Increment position

		// Print key and data
		std::cout << "| KEY: " << current_node->get_key() << "| VAL: " << current_node->get_data() << "]";

		// Print next node if it exists
		if(current_node->get_next() == nullptr)
		{
			std::cout << "\n\n-> NULL\n";
		}
		else
		{
			std::cout << "\n";
		}
		current_node = current_node->get_next(); // Move to the next node
	}


	std::cout << "================ END LIST ================" << '\n';
	std::cout << '\n';
}


