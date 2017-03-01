#include "stack.h"



Stack::Stack() {
	// Default constructor initializes empty stack
	topPtr=nullptr;
}







void Stack::Push(int n) {
	Node *temp = new Node();
	//Node *prev = new Node();
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
	if(topPtr!= nullptr){
		topPtr->previous = nullptr;		
	} 
	delete temp;
	}
	
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


void Stack::MakeEmpty() {

	while (!IsEmpty()) {
		Pop();
	}
	// Removes all nodes from stack leaving an empty, but usable stack
	// Must not create a memory leak
}



bool Stack::IsFull() const {
	// Returns true if stack is full; false otherwise
	return false;
}



int Stack::Top() const {
	if (IsEmpty()) {	
		//cout << "Test";
		throw StackEmpty();
		//cout << "Test";
	} else {
		return topPtr->data;
	}
	//cout << "test";
	return 0;
	// Returns value of top integer on stack WITHOUT modifying the stack
	// If stack is empty, throws StackEmpty exception
}

int Stack::Size() const {
	int count;
	Node *temp = new Node();
	temp = topPtr;

	while (temp != nullptr) {
		temp = temp->next;
		count++;
	}
	return count;
	// Returns number of items on stack WITHOUT modifying the stack
}


int Stack::Max() const {
	if (IsEmpty()) {	
		//cout << "Test";
		throw StackEmpty();
		//cout << "Test";
	}
	Node *nextNode = new Node();
	nextNode = topPtr->next;
	int max = topPtr->data;

	while (nextNode != nullptr) {
		if (max < nextNode->data) {
			max = nextNode->data;
		}
		nextNode = nextNode->next;
	}
	return max;
	// Returns value of largest integer within stack WITHOUT modifying the stack
	// If stack is empty, throws StackEmpty
}

int Stack::Min() const {
	if (IsEmpty()) {	
		//cout << "Test";
		throw StackEmpty();
		//cout << "Test";
	}
	Node *nextNode = new Node();
	nextNode = topPtr->next;
	int min = topPtr->data;

	while (nextNode != nullptr) {
		if (min > nextNode->data) {
			min = nextNode->data;
		}
		nextNode = nextNode->next;
	}
	return min;
	// Returns value of smallest integer within stack WITHOUT modifying the stack
	// If stack is empty, throws StackEmpty
}

int Stack::Peek(int n) const {
	if(Size()>n) {
		Node *temp = topPtr;
		for(int i = 0; i < n; i++) 
		{
			temp = temp->next;
		}
		return temp->data;

	} else {
		throw StackInvalidPeek();	
	}
	// Returns stack value n levels down from top of stack. Peek(0) = Top()
	// If position n does not exist, throws StackInvalidPeek
}

Stack::~Stack() {
	MakeEmpty();
	// Destructor deallocates all nodes from stack 
	// Must not create a memory leak
}
