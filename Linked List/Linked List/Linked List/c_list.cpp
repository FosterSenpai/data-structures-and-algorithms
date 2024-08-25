/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2024 Media Design School
File Name :cShaderLoader.h
Description : Static class to load and compile shaders.
Author : Foster Rae
Mail : Foster.Rae@mds.ac.nz
************************************************************************/

// ======================================================================
// Includes
// ======================================================================
#include "c_list.h"
#include <iostream>

// ======================================================================
// Constructors and Destructors
// ======================================================================

cList::cList() : m_nodes_(0)
{
	m_head_ = nullptr;
	m_current_ = nullptr;
	m_nodes_ = 0;
}

cList::~cList()
{
	cNode* p_delete = m_head_;	   // Pointer or the node to delete, starting at the head.
	cNode* p_next = nullptr;       // Pointer to the node after the node to delete.

	// Move through the list deleting each node.
	while (p_delete != nullptr)
	{

		p_next = p_delete->get_next();
		delete p_delete;
		p_delete = p_next;

	}
}

// ======================================================================
// Methods
// ======================================================================

// ****************************
// ------ Insert Methods ------
// ****************************
void cList::insert_head(const int key, const float value)
{
	// Todo: Add input validation to ensure that the key is unique.
	// if (NodeExists(_key)) throw exception

	// Create the new node.
	cNode* p_new = new cNode(key);
	p_new->set_value(value);

	// Insert the new node at the head of the list.
	p_new->set_next(m_head_);    // Set the 'next' node of the new node to the old head node.
	m_head_ = p_new;			  // Set the new node as the head node.
	m_nodes_++;
}

void cList::insert_tail(const int key, const float value)
{
	// Create the new node.
	cNode* p_new = new cNode(key);
	p_new->set_value(value);

	if (m_head_ != nullptr)   // If the list is not empty.
	{

		cNode* p_tail = m_head_;     // Pointer for the last node, starts at the head to traverse the list.
		while (p_tail->get_next() != nullptr)
		{
			p_tail = p_tail->get_next();
		}
		p_tail->set_next(p_new);    // When the last node is found, set its 'next' node to the new node.

	}
	else 				   // If the list is empty.
	{

		m_head_ = p_new;			   // Set the new node as the head node.

	}

	m_nodes_++;
}

void cList::insert_body(const int position, const int key, const float value)
{
	if (position < 0 || position > m_nodes_)   // Range check.
	{

		// Todo: Throw exception.
		std::cout << "Position selected out of range." << '\n';
		return;

	}

	// Create the new node.
	cNode* p_new = new cNode(key);
	p_new->set_value(value);

	if (position == 0) // If the new node is to be inserted at the head. Optimises by removing the need to traverse the list.
	{
		p_new->set_next(m_head_);
		m_head_ = p_new;
	}
	else
	{
		cNode* p_current = m_head_;     // Pointer to the current node, starting at the head.
		int i_current_position = 0;    // Variable to hold the current position in the list.

		while (i_current_position < position - 1)    // Move through the list to the insertion point.
		{
			p_current = p_current->get_next();
			i_current_position++;
		}

		// When the insertion point is reached, insert the new node.
		p_new->set_next(p_current->get_next());
		p_current->set_next(p_new);
	}

	m_nodes_++;
}

// ****************************
// ------ Delete Methods ------
// ****************************

void cList::delete_head()
{
	if (m_head_ != nullptr)    // Check if the list is not empty.
	{
		cNode* p_old_head = m_head_;     // Create a pointer to the current head.
		m_head_ = m_head_->get_next();    // Set the head to the next node.
		delete p_old_head;
		m_nodes_--;
	}
}

void cList::delete_tail()
{
	if (m_nodes_ <= 0 || m_head_ == nullptr)    // If the list is empty.
	{

		// Todo: Throw exception.
		std::cout << "List is empty." << '\n';
		return;

	}

	if (m_nodes_ == 1)    // If the list only has one node.
	{

		// Delete the head node & return before needing to traverse the list.
		delete_head();
		return;

	}

	// Traverse the list until the second to last node is reached.
	cNode* p_current = m_head_;
	while (p_current->get_next()->get_next() != nullptr)    // Can check two nodes ahead this way.
	{
		p_current = p_current->get_next();
	}

	// Delete the last node.
	delete p_current->get_next();
	p_current->set_next(nullptr);
	m_nodes_--;
}

void cList::delete_body(int position)
{
	//  Check if the list is empty or the position is invalid, return if so.
	//  If the head needs to be deleted, update the head and delete the node.
	//  Traverse to the node before the position to be deleted.
	//  If the position is out of range, return.
	//  Store the node to be deleted.
	//  Update the links to bypass the node.
	//  Delete the stored node.

	if (m_nodes_ <= 0 || m_head_ == nullptr)
	{
		std::cout << "Nothing to delete at selected position." << '\n';
		return;
	}

	if (position == 0)
	{
		delete_head();
		return;
	}

	// Traverse to the node before the position to be deleted
    cNode* p_current = m_head_;
    for (int i = 1; i < position - 1 && p_current != nullptr;
         i++) {
        p_current = p_current->get_next();
    }

    // If the position is out of range
    if (p_current == nullptr || p_current->get_next() == nullptr) {
        return;
    }

	// Store the node to be deleted
    cNode* temp = p_current->get_next();

    // Update the links to bypass the node to be deleted
    p_current->set_next(p_current->get_next()->get_next());

    // Delete the node
    delete temp;
	m_nodes_--;
}

cNode* cList::get_node(int position) const
{
	if (position < 0 || position >= m_nodes_)    // Range check.
	{
		std::cout << "Position selected out of range." << '\n';
		return nullptr;
	}

	cNode* p_current = m_head_;    // Pointer to the current node, starting at the head.
	// Move through the list to the selected position.
	// Return the node at the selected position.

	while (p_current != nullptr)   // Traverse the list.
	{
		// Position is being decremented every loop until it reaches 0 (The selected position).
		if (position == 0)
		{
			return p_current;
		}
		p_current = p_current->get_next();
		position--;
	}

	return nullptr;   // If the position is not found, return nullptr.
}

cNode* cList::find_node(int key) const
{
	cNode* p_current = m_head_;    // Pointer to the current node, starting at the head.

	while (p_current != nullptr)   // Traverse the list.
	{
		if (p_current->get_key() == key)    // If the key of the current node matches the key being searched for.
		{
			return p_current;    // Return the current node.
		}
		p_current = p_current->get_next();   // Move to the next node.
	}

	return nullptr;    // If the key is not found, return nullptr.
}

int cList::num_nodes() const
{
	return m_nodes_;
}

bool cList::node_exists(int key) const
{
	cNode* p_current = m_head_;    // Pointer to the current node, starting at the head.

	while (p_current != nullptr)   // Traverse the list.
	{
		if (p_current->get_key() == key)    // If the key of the current node matches the key being searched for.
		{
			return true;    // Return true.
		}
		p_current = p_current->get_next();   // Move to the next node.
	}

	return false;    // If the key is not found, return false.
}

void cList::print_list() const
{
	cNode* p_current = m_head_;    // Pointer to the current node, starting at the head.

	while (p_current != nullptr)   // Traverse the list.
	{
		std::cout << "Key: " << p_current->get_key() << " Value: " << p_current->get_value() << '\n';    // Print the key and value of the current node.
		p_current = p_current->get_next();   // Move to the next node.
	}
}
