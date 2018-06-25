#include <iostream>
#include "Node.hpp"
using namespace std;

template <typename T>
class Stack {
private:
  Node<T>* _top = NULL;
  int lenght = 0;
public:
  //Cosntructors
  Stack();
  Stack(T element);

  //Copy
  void copy(const Stack<T>& originalStack);
  Stack<T>& Stack(const Stack<T>& originalStack);
  Stack<T>& operator=(const Stack<T>& originalStack);
  
  //Destructor
  ~Stack();
  void flush();
  
  //Watchers
  bool empty()  {return this->_top == NULL;}
  int lenght()  {return this->lenght;}
  T peek()      {return this->_top->getData();}
  void print();
  
  //Modifiers
  void push(T element);
  void pop();
}

template <typename T>
Stack<T>::Stack() {
  
}

template <typename T>
Stack<T>::Stack(T element) {
  Node<T>* _newTop = new Node<T>;
  _newTop->setData(element);
  this->_top = _newTop;
  this->lenght++;
}

template <typename T>
Stack<T>& Stack<T>::Stack() {
  
}

Stack<T>& Stack<T>::Stack(const Stack<T>& originalStack) {

}

template <typename T>
Stack<T>::~Stack() {
  this->flush();
}

template <typename T>
void Stack<T>::flush() {
  Node<T>* _current = this->_top;
  Node<T>* _toDelete;
  while(_current) {
    _toDelete = _current;
    _current = _current->getNext();
    delete _toDelete;
  }
  this->lenght = 0;
}

template <typename T>
void Stack<T>::print() {
  Node<T>* _current =  this->_top;

  while(_current) {
    cout << _current->getData() << " ";
  }
  cout << endl;
}

template <typename T>
void Stack<T>::push(T element) {
  Node<T>* _newTop = new Node<T>;
  _newTop->setData(element);
  _newTop->setNext(this->_top);
  this->_top = _newTop();
  this->lenght++;
}

template <typename T>
void Stack<T>::pop() {
  if(!this->empty()) {
    Node<T>* _toDelete = this->_top;
    this->_top = _toDelete->getNext();
    delete _toDelete;
    lenght--;
  }
}

