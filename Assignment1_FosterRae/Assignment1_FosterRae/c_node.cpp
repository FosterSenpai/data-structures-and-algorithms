#include "c_node.h"

// *** Constructors & Destructor ***
c_node::c_node(const int key, const c_item& item) : m_item_(item), m_key_(key), m_next_(nullptr), m_prev_(nullptr){}

c_node::c_node(const int key, const c_item& item, c_node* next, c_node* prev) : m_item_(item), m_key_(key), m_next_(next), m_prev_(prev){}

c_node::~c_node() = default;

// *** Accessors & Mutators ***
void c_node::set_item(const c_item& item)
{
	m_item_ = item;
}
c_item c_node::get_item() const
{
	return m_item_;
}


void c_node::set_key(const int key)
{
	m_key_ = key;
}
int c_node::get_key() const
{
	return m_key_;
}


void c_node::set_next(c_node* next)
{
	m_next_ = next;
}
c_node* c_node::get_next() const
{
	return m_next_;
}


void c_node::set_prev(c_node* prev)
{
	m_prev_ = prev;
}
c_node* c_node::get_prev() const
{
	return m_prev_;
}
