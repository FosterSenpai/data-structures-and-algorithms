#include "c_node.h"

// ==================== Constructors and Destructors ====================

c_node::c_node(int key)
{
	key_ = key;
	data_ = 0.0;
	prev_ = nullptr;
	next_ = nullptr;
}

c_node::c_node(int key, float data)
{
	key_ = key;
	data_ = data;
	prev_ = nullptr;
	next_ = nullptr;
}

c_node::c_node(int key, float data, c_node* next)
{
	key_ = key;
	data_ = data;
	prev_ = nullptr;
	next_ = next;
}

c_node::c_node(int key, float data, c_node* prev, c_node* next)
{
	key_ = key;
	data_ = data;
	prev_ = prev;
	next_ = next;
}

c_node::~c_node() = default;
