#pragma once
#include<iostream>
#include <string>
using namespace std;
#include"LinkedList.h"

template <typename T>
class Stack:public DoublyLinkedList<T> {
public:

    ~Stack() {}

    void push(const T& value) {
        this->insertTail(value);
    }

    void pop() {
        this->deleteTail();
    }

    T peek() const {
       return  this->getTail();
    }

    void displayhistory() {
        this->display();
    }
};
