/*************************************************************
 * File: pqueue-heap.cpp
 *
 * Implementation file for the HeapPriorityQueue
 * class.
 */
 
#include "pqueue-heap.h"
#include "error.h"

/*
* we have to initialize size of array.
* I think it is reasonable to have 10
* as starting (task did not specify)
*/
HeapPriorityQueue::HeapPriorityQueue() {
	currSize = 10;
	count = 0;
	array = new string[currSize];
}

HeapPriorityQueue::~HeapPriorityQueue() {
	delete[] array;
}

int HeapPriorityQueue::size() {
	return count;
}

bool HeapPriorityQueue::isEmpty() {
	return count == 0;
}

void HeapPriorityQueue::enqueue(string value) {
	if (count == currSize) {
		grow();
	}
	array[count] = value;
	bubbleUp();
	count++;
}

string HeapPriorityQueue::peek() {
	if (isEmpty()) {
		error("Can't peek from an empty priority queue");
	}
	return array[0];
}

string HeapPriorityQueue::dequeueMin() {
	string minString = peek();
	swap(array[0], array[count - 1]);
	count--;
	bubbleDown();
	return minString;
}

void HeapPriorityQueue::grow() {
	currSize *= 2;
	string* temp = new string[currSize];
	for (int i = 0; i < count; i++) {
		temp[i] = array[i];
	}
	delete[] array;
	array = temp;
}

/*
* Here we check two things. parentIndex != currIndex
* ensures we don't go below starting point. And
* second checks makes sure we sort it properly
*/
void HeapPriorityQueue::bubbleUp() {
	int currIndex = count;
	int parentIndex = (count - 1)/2;
	while (parentIndex != currIndex && array[currIndex] < array[parentIndex]) {
		swap(array[parentIndex], array[currIndex]);
		currIndex = parentIndex;
		parentIndex = (currIndex - 1) / 2;
	}
}

void HeapPriorityQueue::bubbleDown() {
	int currIndex = 0;
	while (true) {
		int firstChild = 2 * currIndex + 1;
		int secondChild = 2 * currIndex + 2;
		bool b1 = firstChild < count && array[currIndex] > array[firstChild];
		bool b2 = secondChild < count && array[currIndex] > array[secondChild];
		if (!b1 && !b2)break;
		if (b1 && !b2) {
			swap(array[currIndex], array[firstChild]);
			currIndex = firstChild;
		}
		else if (!b1 && b2) {
			swap(array[currIndex], array[secondChild]);
			currIndex = secondChild;
		}
		else {
			int swapIndex = array[firstChild] < array[secondChild] ? firstChild : secondChild;
			swap(array[currIndex], array[swapIndex]);
			currIndex = swapIndex;
		}
	}
}