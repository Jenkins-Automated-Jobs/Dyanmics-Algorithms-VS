#include "LinkedList.h"
#include <iostream>

using namespace std;


LinkedList::Node* LinkedList::createNode(int val) { return new Node(val); }
LinkedList::Node* LinkedList::getHead() { return head; }

void LinkedList::addNodeEnd(Node* node) {
	Node* temp = head;

	if (temp != nullptr) {
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = node;
	}
	else {
		head = node;
	}
}

void LinkedList::addNodeFront(Node* node) {
	node->next = head;
	head = node;
}

void LinkedList::removeNodeEnd()
{
	Node* temp = head;

	if (temp != nullptr) {
		while (temp->next != nullptr && temp->next->next != nullptr) {
			temp = temp->next;
		}
		delete temp->next;
		temp->next = nullptr;
	}

}

void LinkedList::printList()
{
	Node* temp = head;

	cout << "[ ";
	while (temp != nullptr) {
		//cout << temp << " ";
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << "]\n";
}



