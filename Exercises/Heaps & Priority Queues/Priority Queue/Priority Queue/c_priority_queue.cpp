#include "c_priority_queue.h"

c_priority_queue::c_priority_queue()
{
		std::make_heap(m_heap_.begin(), m_heap_.end()); // Make the heap a max heap
}
