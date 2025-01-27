#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
using namespace std;

template <typename T>
class Node {
private:
  T data;
  Node<T>* _next;
  Node<T>* _prev;

public:                                     //Inline declarations
  //Constructors
  Node();
  Node(const Node<T>& originalNode);
  Node(T element);
  Node(T element, Node* _newNext);
  //Getters
  T getData() const                         {return this-> data;}
  Node<T>* getNext() const                     {return this->_next;}
  Node<T>* getPrev() const                     {return this->_prev;}
  //Setters
  void setData(T input)                     {this->data = input;}
  void setNext(Node<T>* _newNext)              {this->_next = _newNext;}
  void setPrev(Node<T>* _newPrev)              {this->_prev = _newPrev;}
  //Copy
  void copy(const Node<T>& originalNode);
  //Assignment
  Node<T>& operator=(const Node<T>& originalNode);

};

//Constructors

template <typename T>
Node<T>::Node() {
  this->data = 0;
  this->_next = NULL;
  this->_prev = NULL;
}

template <typename T>
Node<T>::Node(T element) {
  Node();
  this->data = element;
}

template <typename T>
Node<T>::Node(T element, Node* _newNext) {
  Node();
  this->data = element;
  this->_next = _newNext;
}

template <typename T>
Node<T>::Node(const Node<T>& originalNode) {
  Node();
  this->copyNode(originalNode);
}



template <typename T>
void Node<T>::copy(const Node<T>& originalNode) {
  this->data = originalNode.data;
  this->_next = originalNode._next;
  this->_prev = originalNode._prev;
}

template <typename T>
Node<T>& Node<T>::operator=(const Node<T>& originalNode) {
  this->copy(originalNode);
}

#endif
