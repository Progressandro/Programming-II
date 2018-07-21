#include <iostream>
#include "Node.hpp"
using namespace std;

template <typename T>
class Stack {
private:
  Node<T>* _top = NULL;
  int len = 0;
public:
  //Cosntructors
  Stack();
  Stack(T element);

  //Copy
  void copy(const Stack<T>& originalStack);
  Stack(const Stack<T>& originalStack);
  
  //Destructor
  ~Stack();
  void flush();
  
  //Watchers
  bool empty()  const  {return this->_top == NULL;}
  int lenght()  const  {return this->len;}
  T peek()      const  {return this->_top->getData();}
  void print()  const;
  
  //Modifiers
  void push(T element);
  void pop();
  
  //Non-essential
  void reverse();
};

template <typename T>
Stack<T>::Stack() {
  
}

template <typename T>
Stack<T>::Stack(T element) {
  Node<T>* _newTop = new Node<T>;
  _newTop->setData(element);
  this->_top = _newTop;
  this->len++;
}

template <typename T>
Stack<T>::Stack(const Stack<T>& originalStack) {
  if(!originalStack.empty())
    this->copy(originalStack);
}

template <typename T>
void Stack<T>::copy(const Stack<T>& originalStack) {
  this->flush();
  if (!originalStack.empty()) {
    Node<T>* _current;
    
    _current  = originalStack._top;
    
    while (_current) {
      this->push(_current->getData());
      _current = _current->getNext();
    }
    this->reverse();
  }
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
  this->_top = NULL;
  this->len = 0;
}

template <typename T>
void Stack<T>::print() const {
  Node<T>* _current =  this->_top;

  while(_current) {
    cout << _current->getData() << " ";
    _current = _current->getNext();
  }
  cout << endl;
}

template <typename T>
void Stack<T>::push(T element) {
  Node<T>* _newTop = new Node<T>;
  _newTop->setData(element);
  _newTop->setNext(this->_top);
  this->_top = _newTop;
  this->len++;
}

template <typename T>
void Stack<T>::pop() {
  if(!this->empty()) {
    Node<T>* _toDelete = this->_top;
    this->_top = _toDelete->getNext();
    delete _toDelete;
    len--;
  }
}

template <typename T>
void Stack<T>::reverse() {
  if(!this->empty()) {
    Node<T>* _current;
    Stack<T>* _newStack = new Stack<T>;
    
    _current = this->_top;
    while (_current) {
      _newStack->push(_current->getData());
      _current = _current->getNext();
    }
    this->flush();
    *this = *_newStack;
  }
}