#include "cNode.h"
// On the end is the initialization list. Use this to set the values of the data members before the constructor body is executed.
cNode::cNode(int _key) : mKey(_key), mValue(0), mNext(nullptr)
{
	int mKey = _key; // Set the key of the node to the value of the parameter _key.
	int mValue = 0; // Set the value of the node to 0.
	cNode* mNext = nullptr; // Set the next node to nullptr.
}

cNode::~cNode() = default;

int cNode::GetKey() const // const because I don't want to change the value of the key.
{
	return mKey; // Return the key of the node.
}

void cNode::SetValue(float _value)
{
	float mValue = _value; // Set the value of the node to the value of the parameter _value.
}

float cNode::GetValue()
{
	return mValue; // Return the value of the node.
}

void cNode::SetNext(cNode* _next)
{
	cNode* mNext = _next; // Set the next node to the value of the parameter _next.
}

cNode* cNode::GetNext()
{
	return mNext; // Return the next node.
}

