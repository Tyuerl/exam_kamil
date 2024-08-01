#include <iostream>
#include <fstream>
#include <unordered_set>
#include <stdexcept>

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head; // указатель на начало списка

public:
    LinkedList() : head(nullptr) {}
    ~LinkedList() {
        clear();
    }
    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void createFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file) {
            std::cout << "no file";
        }
        int value;
        while (file >> value) {
            append(value);
        }
        file.close();
    }
    void removeDuplicates() {
        if (head == nullptr) return;

        std::unordered_set<int> seen;
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr) {
            if (seen.find(current->data) != seen.end()) {
                Node* temp = current;
                prev->next = current->next;
                current = current->next;
                delete temp;
            }
            else {
                seen.insert(current->data);
                prev = current;
                current = current->next;
            }
        }
    }
    void printAndClear() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        std::cout << std::endl;
    }
    void clear() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
    }
};

//int main() {
//    LinkedList list;
//
//    try {
//        list.createFromFile("input.txt");
//    }
//    catch (const std::runtime_error& e) {
//        std::cerr << e.what() << std::endl;
//        return 1;
//    }
//
//    std::cout << "Список после чтения из файла: ";
//    list.printAndClear();
//
//    list.createFromFile("input.txt");
//    list.removeDuplicates();
//    std::cout << "Список после удаления повторных вхождений: ";
//    list.printAndClear();
//
//    return 0;
//}