#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

// ����� ��� �������
class Queue {
private:
    Node* front; // ��������� �� ������ �������
    Node* rear;  // ��������� �� ����� �������

public:
    // �����������
    Queue() : front(nullptr), rear(nullptr) {}

    // ����������
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // ����� ��� ���������� �������� � ������� (Enqueue)
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == nullptr) {
            // ���� ������� �����
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // ����� ��� �������� �������� �� ������� � ��������� �������� (Dequeue)
    int dequeue() {
        if (isEmpty()) {
            std::cout << "empty";
        }
        Node* temp = front;
        int dequeuedValue = temp->data;
        front = front->next;
        if (front == nullptr) {
            // ���� ������� ���������� ������ ����� �������� ��������
            rear = nullptr;
        }
        delete temp;
        return dequeuedValue;
    }

    // ����� ��� �������� ������� �� ������� (EMPTY)
    bool isEmpty() const {
        return front == nullptr;
    }
};


//int main() {
//    Queue queue;
//
//    // ������ ������������� �������
//    queue.enqueue(10);
//    queue.enqueue(20);
//    queue.enqueue(30);
//
//    std::cout << "������� � ������ �������: " << queue.dequeue() << std::endl;
//    std::cout << "������� � ������ �������: " << queue.dequeue() << std::endl;
//
//    if (queue.isEmpty()) {
//        std::cout << "������� �����" << std::endl;
//    }
//    else {
//        std::cout << "������� �� �����" << std::endl;
//    }
//
//    queue.enqueue(40);
//    std::cout << "������� � ������ �������: " << queue.dequeue() << std::endl;
//
//    return 0;
//}