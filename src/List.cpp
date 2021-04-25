#include "Node.cpp"
#include <iostream>
using namespace std;

class List {
private:
    Node* head;
    Node* tail;
    int size = 0;
public:
    List() = default;

    bool isEmpty();
    void append(int value); // insert at end
    void prepend(int value); // insert at start
    void insert(int pos, int value); // insert at nth position
    void remove(int pos); // delete from specific position
    void display(); // to display linked list.
};


bool List::isEmpty() {
    if (this->head == nullptr)
        return true;
    return false;
}

void List::append(int value) {
    Node* node = new Node();
    node->setData(value);
    node->setNext(nullptr);
    node->setPrev(nullptr);
    if (isEmpty()) {
        this->head = node;
        this->tail = node;
        this->size++;
        return;
    }
    Node* temp = this->head;
    while (temp->getNext() != nullptr) {
        temp = temp->getNext();
    }

    temp->setNext(node);
    node->setNext(temp);
    this->tail = node;
    this->size++;
}

void List::prepend(int value) {
    Node* node = new Node();
    node->setData(value);
    node->setNext(nullptr);
    node->setPrev(nullptr);
    if (isEmpty()) {
        this->head = node;
        this->tail = node;
        this->size++;
        return;
    }

    Node* node2 = this->head;
    node2->setPrev(node);
    node->setNext(node2);
    this->head = node;
    this->size++;
}

void List::insert(int index, int value) {
    int i = 0;
    Node* node = new Node();
    node->setNext(nullptr);
    node->setPrev(nullptr);
    node->setData(value);
    if (isEmpty() || index <= 0) {
        prepend(value);
        this->size++;
    }
    else if (index >= this->size)
        append(value);
    else {

        Node* temp = this->head;
        while (temp->getNext() != nullptr && i != index) {
            ++i;
            temp = temp->getNext();

        }
        if (i == index) {
            node->setPrev(temp->getPrev());
            node->setNext(temp);
            temp->setPrev(node);
        }
    }
}

void List::remove(int index) {
    int i = 0;
    Node* temp = this->head;
    Node* prev = nullptr;
    while (temp->getNext() != nullptr && index != i) {
        i++;
        prev = temp;
        temp = temp->getNext();
    }
    if (i == index) {
        Node* temp1 = temp->getNext();
        prev->setNext(temp->getNext());
        temp1->setPrev(prev);
        delete temp;

    }
}

void List::display() {
    Node* temp = this->head;
    while (temp != nullptr) {
        std::cout << temp->getData() << std::endl;
        temp = temp->getNext();
    }
}

