#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

// Класс для очереди
class Queue {
private:
    Node* front; // указатель на начало очереди
    Node* rear;  // указатель на конец очереди

public:
    // Конструктор
    Queue() : front(nullptr), rear(nullptr) {}

    // Деструктор
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Метод для добавления элемента в очередь (Enqueue)
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == nullptr) {
            // Если очередь пуста
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Метод для удаления элемента из очереди с возвратом значения (Dequeue)
    int dequeue() {
        if (isEmpty()) {
            std::cout << "empty";
        }
        Node* temp = front;
        int dequeuedValue = temp->data;
        front = front->next;
        if (front == nullptr) {
            // Если очередь становится пустой после удаления элемента
            rear = nullptr;
        }
        delete temp;
        return dequeuedValue;
    }

    // Метод для проверки очереди на пустоту (EMPTY)
    bool isEmpty() const {
        return front == nullptr;
    }
};