#pragma once
#include<iostream>
using namespace std;
#include<string>

template <typename T>
class Node2 {
public:
    T data;
    Node2* next;
    Node2* prev;

    Node2(const T& value) : data(value), next(nullptr),prev(nullptr) {}
};


template <typename T>
class DoublyLinkedList {
private:
    Node2<T>* head;
    Node2<T>* tail; 
    int size;
public:

    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~DoublyLinkedList() {
        while (head) {
            Node2<T>* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    void insertFront(const T& value) {
        Node2<T>* newNode2 = new Node2<T>(value);
        if (isEmpty()) {
            head = tail = newNode2;
        }
        else {
            newNode2->next = head;
            head->prev = newNode2;
            head = newNode2;
        }
        size++;
    }

    void insertTail(const T&value) {
        Node2<T>* temp = new Node2<T>(value);
        if (!isEmpty()){
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        else {
            head = tail = temp;
        }
    }
    void deleteTail() {
        if (isEmpty()) cout << "List is empty";
        Node2<T>* temp = tail;
        if (tail->prev) {
            tail = tail->prev;
            tail->next = nullptr;
            temp->prev = nullptr;
            delete temp;
            temp = nullptr;
        }
        size--;
    }

    void deleteFront() {
        if (isEmpty()) cout<<"List is empty";
        Node2<T>* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr; 
        }
        delete temp;
        size--;
    }

    bool isEmpty() const { return head == nullptr; }
    int getSize() const { return size; }

    void display(ostream &out=cout) const {
        if (&out == &cout) {
            Node2<T>* current = head;
            while (current) {
                cout << *current->data << " \n ";
                current = current->next;
            }
            cout << "nullptr" << endl;
        }
        else {
            Node2<T>* current = head;
            while (current) {
                out << *current->data << " \n ";
                current = current->next;
            }
            cout << "nullptr" << endl;
        }
    }
    Node2<T>* getHead() const { return head; }
    Node2<T>* getTail() const { return tail; }
    void setTail(Node2<T>* t) { tail = t; }
    void decrementSize() { size--; }

};