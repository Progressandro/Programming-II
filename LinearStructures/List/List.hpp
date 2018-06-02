#include <iostream>
#include "Node.hpp"
using namespace std;

template <typename T>
class List {
private:
  Node<T>* _header = NULL;
  int lenght = 0;


public:
  //Constructors
  List();
  List(T element);
  List(const List& originalList);
  //Destructor
  ~List();
  void flush();
  //Watchers
  int getLenght() const {return this->lenght;}
  bool empty() const    {return this->_header==NULL;}
  T getElement(int position) const;
  int indexOf(T element) const;
  bool find(T element) const;
  void print() const;
  //Modifiers
  void insert(T element, int position);
  void remove(T element);
  //Copy
  void copy();
  List& operator=(const List<T>& originalList);
};

template <typename T>
List<T>::List() {

}

template <typename T>
List<T>::List(T element) {
  Node<T>* newHeader = new Node<T>;
  this->_header = newHeader;
}

template <typename T>
List<T>::List(const List& originalList) {

}

template <typename T>
List<T>::~List() {
  this->flush();
}

template <typename T>
void List<T>::flush() {
  if(!this->empty()) {
    Node<T>* _current = this->_header;
    Node<T>* _saveNext;
    while (_current != NULL) {
      _saveNext = _current->getNext();
      delete _current;
      _current = _saveNext;
    }
    this->_header = NULL;
    this->lenght = 0;
  }
}

template <typename T>
T List<T>::getElement(int position) const {
  if (position > 0 && position <= this->lenght) {

    Node<T>* _current = this->_header;
    Node<T>* _next = _current->getNext();

    for (int i = 1; i < position; i++) {
      _current = _next;
      _next = _current->getNext();
    }
    return _current->getData();
  }
  else {
    cout << "Error: Non-existend position requested." << endl;
  }
}

template <typename T>
int List<T>::indexOf(T element) const {

}

template <typename T>
bool List<T>::find(T element) const {

}

template <typename T>
void List<T>::print() const {
  if (this->lenght > 0) {

    Node<T>* _current = this->_header;
    Node<T>* _next = _current->getNext();

    for(int i = 1; i < this->lenght; i++) {
      cout << _current->getData() << " ";
      _current = _next;
      _next = _current->getNext();
    }
    cout << _current->getData() << endl;
  }
}

template <typename T>
void List<T>::insert(T element, int position) {
  if(position > 0 && position <= (this->lenght)+1) {

    Node<T>* _newNode = new Node<T>;
    _newNode->setData(element);

    if (position > 1) {
      Node<T>* _current = this->_header;
      Node<T>* _next = _current->getNext();
      for(int i = 1; i < position-1; i++) {
        _current = _next;
        _next = _current->getNext();
      }
      _current->setNext(_newNode);
      _newNode->setNext(_next);
    }
    else {
      Node<T>* _currentHeader = this->_header;
      _newNode->setNext(_currentHeader);
      this->_header = _newNode;
    }
    this->lenght++;
  }
  else {
    cout << "Tried to insert in invalid position" << endl;
  }
}
