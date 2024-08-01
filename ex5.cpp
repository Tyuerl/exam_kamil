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
//	// ������ ������������� �����
//	stack.push(10);
//	stack.push(20);
//	stack.push(30);
//
//	std::cout << "������� �� ������� �����: " << stack.pop() << std::endl;
//	std::cout << "������� �� ������� �����: " << stack.pop() << std::endl;
//
//	if (stack.isEmpty()) {
//		std::cout << "���� ����" << std::endl;
//	}
//	else {
//		std::cout << "���� �� ����" << std::endl;
//	}
//
//	stack.push(40);
//	std::cout << "������� �� ������� �����: " << stack.pop() << std::endl;
//
//	return 0;
//}