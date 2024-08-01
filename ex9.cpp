#include <iostream>

// Структура для узла односвязного списка
struct SingleNode {
    float data;
    SingleNode* next;
    SingleNode(float value) : data(value), next(nullptr) {}
};

// Структура для узла двусвязного списка
struct DoubleNode {
    float data;
    DoubleNode* prev;
    DoubleNode* next;
    DoubleNode(float value) : data(value), prev(nullptr), next(nullptr) {}
};

// Функция для преобразования односвязного списка в двусвязный
DoubleNode* convertToDoublyLinkedList(SingleNode* head) {
    if (head == nullptr) return nullptr;

    DoubleNode* newHead = new DoubleNode(head->data);
    DoubleNode* currentD = newHead;
    SingleNode* currentS = head->next;

    while (currentS != nullptr) {
        DoubleNode* newNode = new DoubleNode(currentS->data);
        currentD->next = newNode;
        newNode->prev = currentD;
        currentD = newNode;
        currentS = currentS->next;
    }

    return newHead;
}

// Функция для добавления элемента в конец односвязного списка
void appendSingle(SingleNode*& head, float value) {
    if (head == nullptr) {
        head = new SingleNode(value);
    }
    else {
        SingleNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new SingleNode(value);
    }
}

// Функция для печати элементов односвязного списка
void printSingleList(SingleNode* head) {
    SingleNode* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;
}

// Функция для печати элементов двусвязного списка
void printDoubleList(DoubleNode* head) {
    DoubleNode* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " <-> ";
        temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;
}

// Функция для освобождения памяти из односвязного списка
void freeSingleList(SingleNode* head) {
    while (head != nullptr) {
        SingleNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// Функция для освобождения памяти из двусвязного списка
void freeDoubleList(DoubleNode* head) {
    while (head != nullptr) {
        DoubleNode* temp = head;
        head = head->next;
        delete temp;
    }
}

//int main() {
//    // Создание и заполнение односвязного списка
//    SingleNode* singleHead = nullptr;
//    appendSingle(singleHead, 1.1f);
//    appendSingle(singleHead, 2.2f);
//    appendSingle(singleHead, 3.3f);
//    appendSingle(singleHead, 4.4f);
//
//    std::cout << "Односвязный список: ";
//    printSingleList(singleHead);
//
//    // Преобразование в двусвязный список
//    DoubleNode* doubleHead = convertToDoublyLinkedList(singleHead);
//
//    std::cout << "Двусвязный список: ";
//    printDoubleList(doubleHead);
//
//    // Освобождение памяти
//    freeSingleList(singleHead);
//    freeDoubleList(doubleHead);
//
//    return 0;
//}