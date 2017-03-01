#include "stack.h"



Stack::Stack() {
	// Default constructor initializes empty stack
	topPtr=nullptr;
	//topPtr->next = nullptr;
	//topPtr->previous = nullptr;

}


Stack::~Stack() {
	MakeEmpty();
	delete topPtr;
	// Destructor deallocates all nodes from stack 
	// Must not create a memory leak
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


void Stack::MakeEmpty() {

	while (!IsEmpty()) {
		Pop();
	}
	// Removes all nodes from stack leaving an empty, but usable stack
	// Must not create a memory leak
}


void Stack::Push(int n) {
	Node *temp = new Node();
	if (IsFull()) {
		throw StackFull();
	} else {
	temp->data = n;
	cout << "data";
	temp->previous = nullptr;
	temp->next = topPtr;
	if(!IsEmpty()){
	topPtr->previous = temp;
	}
	topPtr = temp;
	}
	// Pushes integer n onto top of stack.  
	// If unable to push, throws StackFull exception.
}

void Stack::Pop() {
	if (IsEmpty()) {
		cout << "Is Empty";
		throw StackEmpty();
	} else {
	Node *temp = new Node();
	temp = topPtr;
	topPtr = topPtr->next;
	topPtr->previous = nullptr;
	cout << topPtr->data;
	cout << topPtr->next;
	delete temp;
	}
	
	// Removes top integer from stack
	// If stack is already empty, throws StackEmpty exception
}




bool Stack::IsFull() const {
	// Returns true if stack is full; false otherwise
	return false;
}



int Stack::Top() const {
	if (IsEmpty()) {	
		cout << "Test";
		throw StackEmpty();
		cout << "Test";
	} else {
		return topPtr->data;
	}
	cout << "test";
	return 0;
	// Returns value of top integer on stack WITHOUT modifying the stack
	// If stack is empty, throws StackEmpty exception
}

int Stack::Size() const {
	int count;
	Node *temp = new Node();
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
		if (temp->data > nextNode->data) {
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
		if (temp->data < nextNode->data) {
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
	Node *temp = new Node();
	temp = topPtr;

	while (count < n) {
		count++;
		if (temp->next = nullptr) {
			throw StackInvalidPeek();
		}
		temp = temp->next;
	}
	return temp->data;
	// Returns stack value n levels down from top of stack. Peek(0) = Top()
	// If position n does not exist, throws StackInvalidPeek
}
