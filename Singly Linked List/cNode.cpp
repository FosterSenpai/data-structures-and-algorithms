#include "cNode.h"

// --- Constructors and Destructors ---

cNode::cNode(int _key)
{
	mKey = _key;
	mNext = nullptr;
	mValue = 0;
}

cNode::~cNode() = default;

// --- Accessors ---

/* Question for Mike/Sherry:
 * Is it better that I define even small functions like this in the
 * cpp file to keep a clear separation between blueprint and implementation?
 */

int cNode::GetKey() const { return mKey; }

void cNode::SetValue(float _value) { float mValue = _value; }

float cNode::GetValue() const { return mValue; }

void cNode::SetNext(cNode* _next) { cNode* mNext = _next; }

cNode* cNode::GetNext() const { return mNext; }
