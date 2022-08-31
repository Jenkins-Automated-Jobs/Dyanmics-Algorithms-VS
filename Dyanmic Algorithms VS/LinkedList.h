#pragma once
#pragma once
class LinkedList
{
public:
	struct Node {
		Node* next = nullptr;
		int val;

		Node() : val(0) {}
		Node(int val) : val(val) {}
	};

	Node* createNode(int val);
	Node* getHead();
	void addNodeEnd(Node* node);
	void addNodeFront(Node* node);
	void removeNodeEnd();
	void printList();

private:
	Node* head = nullptr;
};

