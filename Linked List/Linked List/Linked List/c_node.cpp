#include "c_node.h"

// --- Constructors and Destructors ---

cNode::cNode(int key)
{
	m_key_ = key;
	m_next_ = nullptr;
	m_value_ = 0;
}

cNode::~cNode() = default;

// --- Accessors ---

int cNode::get_key() const { return m_key_; }

void cNode::set_value(float value) { m_value_ = value; }

float cNode::get_value() const { return m_value_; }

void cNode::set_next(cNode* next) { m_next_ = next; }

cNode* cNode::get_next() const { return m_next_; }
