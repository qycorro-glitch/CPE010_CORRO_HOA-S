#ifndef NODES_H
#define NODES_H

#include <cstddef> // for NULL / nullptr

// Definition of single linked list node
template <typename T>
class Node {
public:
    T data;
    Node *next;
};

// Function that creates a new node and initializes next pointer to null
template <typename T>
Node<T>* new_node(T newData) {
    Node<T> *newNode = new Node<T>;
    newNode->data = newData;
    newNode->next = NULL;
    return newNode;
}

#endif