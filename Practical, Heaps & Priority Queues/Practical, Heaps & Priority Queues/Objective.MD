## Practical: Heaps & Priority Queues

### Objective
Implement a priority queue class cPQueue using the STL heap functions. The queue will be composed of objects of class cItem, where each cItem object has a string item identifier and a float priority value.

<br />

#### The cPQueue class should provide the following methods:
* cPQueue(): Constructor for the cPQueue class.  
* ~cPQueue(): Destructor for the cPQueue class.  
* void Push(cItem Item): Adds an item to the queue.  
* cItem Pop(): Returns the highest priority item and removes it from the queue.  
* int GetLength(): Returns the number of items in the queue.  
* float PriorityFront(): Returns the priority of the item at the front of the queue, without removing the item.  