/*************************************************************
 * File: pqueue-doublylinkedlist.cpp
 *
 * Implementation file for the DoublyLinkedListPriorityQueue
 * class.
 */
 
#include "pqueue-doublylinkedlist.h"
#include "error.h"

DoublyLinkedListPriorityQueue::DoublyLinkedListPriorityQueue() {
	node = nullptr;
	length = 0;
}

DoublyLinkedListPriorityQueue::~DoublyLinkedListPriorityQueue() {
	doubleNode* temp = node;
	while (temp) {
		doubleNode* nd = temp->next;
		delete temp;
		temp = nd;
	}
}

int DoublyLinkedListPriorityQueue::size() {
	return length;
}

bool DoublyLinkedListPriorityQueue::isEmpty() {
	return length == 0;
}

void DoublyLinkedListPriorityQueue::enqueue(string value) {
	doubleNode* insertNode = new doubleNode(value, node, nullptr);
	if (node) {
		node->prev = insertNode;
	}
	node = insertNode;
	length++;
}

string DoublyLinkedListPriorityQueue::peek() {
	if (isEmpty()) {
		error("Can't peek from an empty priority queue");
	}
	doubleNode* temp = node;
	string res = temp->value;
	while (temp) {
		if (temp->value < res) {
			res = temp->value;
		}
		temp = temp->next;
	}
	return res;
}

string DoublyLinkedListPriorityQueue::dequeueMin() {
	string minString = peek();
	doubleNode* temp = node;
	while (temp) {
		if (temp->value == minString) {
			if (temp == node) {
				node = temp->next;
			}
			if (temp->prev) {
				temp->prev->next = temp->next;
			}
			if (temp->next) {
				temp->next->prev = temp->prev;
			}
			delete temp;
			break;
		}
		temp = temp->next;
	}
	length--;
	return minString;
}

