#include <iostream>

class Node {
public:
	int data;
	Node* next;
	Node(int value) : data(value), next(nullptr) {}
};

class Stack
{

public:
	Stack()
	{
		top = nullptr;
	}

	~Stack() {
		while (!isEmpty()) {
			pop();
		}
	}
	void push(int value) {
		Node* newNode = new Node(value);
		newNode->next = top;
		top = newNode;
	}

	int pop() {
		if (isEmpty()) {
			std::cout << "already empy";
		}
		Node* temp = top;
		int poppedValue = temp->data;
		top = top->next;
		delete temp;
		return poppedValue;
	}

	bool isEmpty() const {
		return top == nullptr;
	}

private:
	Node* top;
};


//int main() {
//	Stack stack;
//
//	// Пример использования стека
//	stack.push(10);
//	stack.push(20);
//	stack.push(30);
//
//	std::cout << "Элемент на вершине стека: " << stack.pop() << std::endl;
//	std::cout << "Элемент на вершине стека: " << stack.pop() << std::endl;
//
//	if (stack.isEmpty()) {
//		std::cout << "Стек пуст" << std::endl;
//	}
//	else {
//		std::cout << "Стек не пуст" << std::endl;
//	}
//
//	stack.push(40);
//	std::cout << "Элемент на вершине стека: " << stack.pop() << std::endl;
//
//	return 0;
//}