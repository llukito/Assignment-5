/**********************************************
 * File: pqueue-extra.h
 *
 * We use Leftiest Heap to make priority queue.
 * It is a variant of a binary heap that supports efficient
 * merging. Each node stores, value, left node, right node and 
 * npl which is minimal distance from null node.
 */
#ifndef PQueue_Extra_Included
#define PQueue_Extra_Included

#include <string>
using namespace std;

/*
 * TODO: Describe this class!
 */
class ExtraPriorityQueue {
public:
	/* Constructs a new, empty priority queue. */
	ExtraPriorityQueue();
	
	/* Cleans up all memory allocated by this priority queue. */
	~ExtraPriorityQueue();
	
	/* Returns the number of elements in the priority queue. */
	int size();
	
	/* Returns whether or not the priority queue is empty. */
	bool isEmpty();
	
	/* Enqueues a new string into the priority queue. */
	void enqueue(string value);
	
	/* Returns, but does not remove, the lexicographically first string in the
	 * priority queue.
	 */
	string peek();
	
	/* Returns and removes the lexicographically first string in the
	 * priority queue.
	 */
	string dequeueMin();

private:
	struct Node {
		string value;
		int npl;
		Node* left;
		Node* right;

		Node(string val) {
			value = val;
			npl = 0;
			left = nullptr;
			right = nullptr;
		}
	};
	Node* root;
	int length;
	void emptyTree(Node*);
	Node* merge(Node*, Node*);
	int npl(Node*);
};

#endif
