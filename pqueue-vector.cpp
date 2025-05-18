/*************************************************************
 * File: pqueue-vector.cpp
 *
 * Implementation file for the VectorPriorityQueue
 * class.
 */
 
#include "pqueue-vector.h"
#include "error.h"

VectorPriorityQueue::VectorPriorityQueue() {
	// no need to initialize vector
}

VectorPriorityQueue::~VectorPriorityQueue() {
	// memory has not been allocated manually
}

int VectorPriorityQueue::size() {
	return vect.size();
}

bool VectorPriorityQueue::isEmpty() {
	return vect.empty();
}

void VectorPriorityQueue::enqueue(string value) {
	vect.push_back(value);
}

string VectorPriorityQueue::peek() {
	if (isEmpty()) {
		error("Can't peek from an empty priority queue");
	}
	string res = vect[0];
	for (int i = 1; i < vect.size(); i++) {
		string s = vect[i];
		if (s < res) {
			res = s;
		}
	}
	return res;
}

string VectorPriorityQueue::dequeueMin() {
	string minString = peek();
	int index = find(vect.begin(), vect.end(), minString) - vect.begin();
	vect.erase(vect.begin() + index);
	return minString;
}

