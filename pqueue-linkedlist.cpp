/*************************************************************
 * File: pqueue-linkedlist.cpp
 *
 * Implementation file for the LinkedListPriorityQueue
 * class.
 */
 
#include "pqueue-linkedlist.h"
#include "error.h"

LinkedListPriorityQueue::LinkedListPriorityQueue() {
	// initialize node
	node = new Node("", nullptr);
	// initialize length
	length = 0;
}

LinkedListPriorityQueue::~LinkedListPriorityQueue() {
	Node* curr = node;
	while (curr) {
		Node* temp = curr->next;
		delete curr;
		curr = temp;
	}
}

int LinkedListPriorityQueue::size() {
	return length;
}

bool LinkedListPriorityQueue::isEmpty() {
	return size() == 0;
}

/*
* If we insert for the first time (lenght == 0),
* then we just change already made node's value
* (which had empty string before). In other cases
* we user insert function
*/
void LinkedListPriorityQueue::enqueue(string value) {
	if (length == 0) {
		node->value = value;
	}
	else {
		insert(value);
	}
	length++;
}

string LinkedListPriorityQueue::peek() {
	if (isEmpty()) {
		error("Can't peek from an empty priority queue");
	}
	return node->value;
}

string LinkedListPriorityQueue::dequeueMin() {
	string minString = peek();
	Node* temp = node;
	node = node->next;
	delete temp;
	temp = nullptr;
	length--;
	return minString;
}

/*
* This is our private helper function, that
* inserts element so linked lists stay sorted
*/
void LinkedListPriorityQueue::insert(string& value) {
	Node* insertNode = new Node(value);
	if (isEmpty() || value < node->value) {
		insertNode->next = node;
		node = insertNode;
		return;
	}
	Node* prev = node;
	Node* curr = node->next;
	while (curr) {
		if (curr->value > value) {
			insertNode->next = curr;
			prev->next = insertNode;
			return;
		}
		prev = curr;
		curr = curr->next;
	}
	prev->next = insertNode;
}

