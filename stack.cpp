#include "stack.h"



Stack::Stack() {
	// Default constructor initializes empty stack
	previous = nullptr;
	next = nullptr;

}


Stack::~Stack() {
	MakeEmpty();
	delete topPtr;
	// Destructor deallocates all nodes from stack 
	// Must not create a memory leak
}

void Stack::Push(int n) {
	
	if (IsFull()) {
		throw StackFull;
	}

	Node *temp = new Node();
	temp->data = n;
	temp->next = topPtr;
	temp->previous = nullptr;
	topPtr = temp;
	

	// Pushes integer n onto top of stack.  
	// If unable to push, throws StackFull exception.
}

void Stack::Pop() {
	if (IsEmpty()) {
		throw StackEmpty;
	}
	Node *temp = new Node();
	temp = topPtr->next;
	temp->previous = nullptr;
	topPtr = temp;
	delete temp;
	
	// Removes top integer from stack
	// If stack is already empty, throws StackEmpty exception
}

bool Stack::IsEmpty() const {
	// Returns true if stack is empty; false otherwise
	if (topPtr == nullptr) {
		return true;
	}
	else {
		return false;
	}
}


bool Stack::IsFull() const {
	// Returns true if stack is full; false otherwise
	return false;
}


void Stack::MakeEmpty() {

	while (!IsEmpty()) {
		Pop();
	}
	// Removes all nodes from stack leaving an empty, but usable stack
	// Must not create a memory leak
}

int Stack::Top() const {
	if (IsEmpty()) {
		throw StackEmpty;
	}
	return topPtr->data;
	// Returns value of top integer on stack WITHOUT modifying the stack
	// If stack is empty, throws StackEmpty exception
}

int Stack::Size() const {
	int count;
	Node temp = new Node();
	temp = topPtr;

	while (temp->next != nullptr) {
		temp = temp->next;
		count++;
	}
	return count;
	// Returns number of items on stack WITHOUT modifying the stack
}


int Stack::Max() const {
	Node *temp = new Node();
	Node *nextNode = new Node();
	temp = topPtr;
	nextNode = temp->next;
	int max;

	while (nextNode->next != nullptr) {
		if (temp->data > NextNode->data) {
			max = temp->data;
		}
		else {
			max = nextNode->data;
		}
	}
	return max;
	// Returns value of largest integer within stack WITHOUT modifying the stack
	// If stack is empty, throws StackEmpty
}

int Stack::Min() const {
	Node *temp = new Node();
	Node *nextNode = new Node();
	temp = topPtr;
	nextNode = temp->next;
	int min;

	while (nextNode->next != nullptr) {
		if (temp->data < NextNode->data) {
			min = temp->data;
		}
		else {
			min = nextNode->data;
		}
	}
	return min;
	// Returns value of smallest integer within stack WITHOUT modifying the stack
	// If stack is empty, throws StackEmpty
}

int Stack::Peek(int n) const {
	int count = 0;
	Node temp = new Node();
	temp = topPtr;

	while (count < n) {
		count++;
		if (temp->next = nullptr) {
			throw StackInvalidPeek;
		}
		temp = temp->next;
	}
	return temp->data;
	// Returns stack value n levels down from top of stack. Peek(0) = Top()
	// If position n does not exist, throws StackInvalidPeek
}