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

void c_list::insert_head(const int key, const float data)
{

	c_node* new_node = new c_node(key, data, nullptr, head_node_); // Create node, using constructor with key, data and pointers

	if (head_node_ != nullptr) // If the list is not empty
	{
		head_node_->set_prev(new_node); // Set the previous pointer of the current head to the new node
		head_node_ = new_node;          // Set the head to the new node
	}
	else                       // If the list is empty
	{
		head_node_ = new_node;
	}

	size_++;
}

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
	// Check if the position is out of bounds
    if (position < 1 || position > size_ + 1)
    {
        std::cerr << "Error: Position out of bounds\n";
        return;
    }

    c_node* new_node = new c_node(key, data);

    if (position == 1) // If the position is the head
    {
        insert_head(key, data);
    }
    else 
    {
        current_node_ = head_node_;

        // Traverse to the node before the position
        for (int i = 1; i < position - 1 && current_node_ != nullptr; i++)
        {
            current_node_ = current_node_->get_next();
        }

		// Pointer safety check
        if (current_node_ == nullptr)
        {
            std::cerr << "Error: Position out of bounds\n";
            delete new_node;
            return;
        }

        new_node->set_prev(current_node_);                // Set the previous pointer of the new node to the current node
        new_node->set_next(current_node_->get_next());    // Set the next pointer of the new node to the next node of the current node

        // If the new node is not the last node in the list
        // Update the next node's previous pointer to the new node
        if (new_node->get_next() != nullptr)
        {
            new_node->get_next()->set_prev(new_node);
        }

        current_node_->set_next(new_node); // Set the next pointer of the current node to the new node
    }

    size_++;
}


//                     ***** Delete Functions *****

/**
 * @brief Delete the head node of the list
 */
void c_list::delete_head()
{
	// Empty check
	if (head_node_ == nullptr)
	{
		std::cerr << "Error: List is empty\n";
		return;
	}

	c_node* deletion_node = head_node_;  // Node to delete
	head_node_ = head_node_->get_next(); // Move the head to the next node

	// Pointer safety check
	if (head_node_ != nullptr)
	{
		head_node_->set_prev(nullptr);   // Set the previous pointer of the new head to null
	}

	delete deletion_node; // Delete the old head
	size_--;
}

void c_list::delete_tail()
{
	// Empty check
	if (head_node_ == nullptr)
	{
		std::cerr << "Error: List is empty\n";
		return;
	}
	// Head check
	if (head_node_->get_next() == nullptr)
	{
		delete head_node_;
		head_node_ = nullptr;
		size_--;
		return;
	}


	// Traverse from the head to the tail
	c_node* deletion_node = head_node_;
	while (deletion_node->get_next() != nullptr)
	{
		deletion_node = deletion_node->get_next();
	}

	deletion_node->get_prev()->set_next(nullptr); // Set the next pointer of the previous node to null
	delete deletion_node;                         // Delete the old tail
}

void c_list::delete_body(int position)
{
	// Empty & out of bounds check
	if(head_node_ == nullptr) 
	{
		std::cerr << "Error: List is empty\n";
		return;
	}
	// Out of bounds check
	if(position < 1 || position > size_)
	{
		std::cerr << "Error: Position out of bounds\n";
		return;
	}


	if(position == 1) // If the position is the head
	{
		delete_head();
		return;
	}
	else
	{
		// Traverse to the node at the position
		c_node* deletion_node = head_node_;
        for (int i = 1; i < position && deletion_node != nullptr; i++)
        {
            deletion_node = deletion_node->get_next();
        }

		// Pointer safety check
        if (deletion_node == nullptr)
        {
            std::cerr << "Error: Position out of bounds\n";
            delete deletion_node;
            return;
        }

		if (deletion_node->get_next() != nullptr) // If the node is not the last node
		{
			deletion_node->get_next()->set_prev(deletion_node->get_prev()); // Set the previous pointer of the next node to the previous node
		}

		if (deletion_node->get_prev() != nullptr) // If the node is not the first node
		{
			deletion_node->get_prev()->set_next(deletion_node->get_next()); // Set the next pointer of the previous node to the next node
		}

		delete deletion_node; // Delete the node
		size_--;
	}
}


// 					   ***** Accessor Functions *****

void c_list::get_node_from_position(int position)
{
	// traverse the list to the position
	// print the key and data of the node

	// Empty check
	if (head_node_ == nullptr)
	{
		std::cerr << "Error: List is empty\n";
		return;
	}

	// Out of bounds check
	if (position < 1 || position > size_)
	{
		std::cerr << "Error: Position out of bounds\n";
		return;
	}

	// Traverse to the node at the position
	current_node_ = head_node_;
	for (int i = 1; i < position && current_node_ != nullptr; i++)
	{
		current_node_ = current_node_->get_next();
	}

	// Print the key and data of the node
	std::cout << "****************** NODE ******************" << '\n';

	std::cout << "Node at position " << position << " has key: " << current_node_->get_key() << " and data: " << current_node_->get_data() << '\n';

	std::cout << "****************** NODE ******************" << '\n';
}

void c_list::get_node_from_key(int key)
{
	// Empty check
	if (head_node_ == nullptr)
	{
		std::cerr << "Error: List is empty\n";
		return;
	}

	// Traverse the list to the key
	current_node_ = head_node_;
	while (current_node_ != nullptr)
	{
		if (current_node_->get_key() == key) // If the key is found, print the key and data
		{
			std::cout << "****************** NODE ******************" << '\n';

			std::cout << "Node with key " << key << " has data: " << current_node_->get_data() << '\n';

			std::cout << "****************** NODE ******************" << '\n';
			return;
		}
		current_node_ = current_node_->get_next();
	}

	std::cerr << "Error: Node with key " << key << " not found\n";
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

bool c_list::key_exists(int key)
{
	// Traverse the list and check if the key exists
	current_node_ = head_node_;
	while (current_node_ != nullptr)
	{
		if (current_node_->get_key() == key)
		{
			return true;
		}
		current_node_ = current_node_->get_next();
	}

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

void c_list::traverse_backward(c_node* head)
{
	c_node* current_node = head; // Start at the head

	while (current_node->get_next() != nullptr) // Traverse to the tail
	{
		current_node = current_node->get_next();
	}

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


