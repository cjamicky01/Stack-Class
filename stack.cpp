



Stack::Stack() {
	// Default constructor initializes empty stack
}


Stack::~Stack() {
	// Destructor deallocates all nodes from stack 
	// Must not create a memory leak
}

void Stack::Push(int n) {
	// Pushes integer n onto top of stack.  
	// If unable to push, throws StackFull exception.
}

void Stack::Pop() {
	// Removes top integer from stack
	// If stack is already empty, throws StackEmpty exception
}

bool Stack::IsEmpty() const {
	// Returns true if stack is empty; false otherwise
}


bool Stack::IsFull() const {
	// Returns true if stack is full; false otherwise
}


void Stack::MakeEmpty() {
	// Removes all nodes from stack leaving an empty, but usable stack
	// Must not create a memory leak
}

int Stack::Top() const {
	// Returns value of top integer on stack WITHOUT modifying the stack
	// If stack is empty, throws StackEmpty exception
}

int Stack::Size() const {
	// Returns number of items on stack WITHOUT modifying the stack
}


int Stack::Max() const {
	// Returns value of largest integer within stack WITHOUT modifying the stack
	// If stack is empty, throws StackEmpty
}

int Stack::Min() const {
	// Returns value of smallest integer within stack WITHOUT modifying the stack
	// If stack is empty, throws StackEmpty
}

int Stack::Peek(int n) const {
	// Returns stack value n levels down from top of stack. Peek(0) = Top()
	// If position n does not exist, throws StackInvalidPeek
}