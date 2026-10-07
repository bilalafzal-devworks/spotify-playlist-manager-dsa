#pragma once
template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node(const T& value) : data(value), next(nullptr) {}
};
