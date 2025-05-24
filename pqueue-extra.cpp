/*************************************************************
 * File: pqueue-extra.cpp
 *
 * Implementation file for the ExtraPriorityQueue class.  You
 * do not need to implement this class, but we're happy to
 * give you extra credit if you do!
 */
 
#include "pqueue-extra.h"
#include "error.h"

ExtraPriorityQueue::ExtraPriorityQueue() {
	root = nullptr;
	length = 0;
}

ExtraPriorityQueue::~ExtraPriorityQueue() {
	emptyTree(root);
}

void ExtraPriorityQueue::emptyTree(Node* nd) {
	if (nd) {
		emptyTree(nd->left);
		emptyTree(nd->right);
		delete nd;
	}
}

int ExtraPriorityQueue::size() {
	return length;
}

bool ExtraPriorityQueue::isEmpty() {
	return length == 0;
}

void ExtraPriorityQueue::enqueue(string value) {
	Node* node = new Node(value);
	root = merge(root, node);
	length++;
}

ExtraPriorityQueue::Node* ExtraPriorityQueue::merge(Node* root, Node* node) {
	if (!root)return node;
	if (!node)return root;
	if (root->value > node->value) {
		swap(root, node);
	}
	root->right = merge(root->right, node);
	if (npl(root->right) > npl(root->left)) {
		swap(root->right, root->left);
	}
	root->npl = 1 + min(npl(root->left), npl(root->right));
	return root;
}

int ExtraPriorityQueue::npl(Node* node) {
	return !node ? -1 : node->npl;
}

string ExtraPriorityQueue::peek() {
	if (isEmpty()) {
		error("Queue is empty");
	}
	return root->value;
}

string ExtraPriorityQueue::dequeueMin() {
	if (isEmpty()) {
		error("Queue is empty");
	}
	string res = root->value;
	Node* oldRoot = root;
	root = merge(root->left, root->right);
	delete oldRoot;
	length--;
	return res;
}

