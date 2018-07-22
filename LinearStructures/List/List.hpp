#include <iostream>
#include "Node.hpp"
using namespace std;

template <typename T>
class List {
private:
  Node<T>* _header;
  int len;


public:
  //Constructors
  List();
  List(T element);
  List(const List<T>& originalList);
  //Destructor
  ~List();
  void flush();
  //Watchers
  int lenght() const {return this->len;}
  bool empty() const    {return this->_header==NULL;}
  T getElement(int position) const;
  int indexOf(T element) const;
  bool exists(T element) const;
  void print() const;
  //Modifiers
  void insert(T element, int position);
  void removeElement(T element);
  void removePosition(int position);
  void reverse();
  //Copy
  void copy(const List<T>& originalList);
  List<T>& operator=(const List<T>& originalList);
  bool operator==(const List<T>& toCompare);
  
};

template <typename T>
List<T>::List() {
  this->_header = NULL;
  this->len = 0;
}

template <typename T>
List<T>::List(T element) {
  List();
  Node<T>* _newHeader = new Node<T>;
  this->_header = _newHeader;
}

template <typename T>
List<T>::List(const List& originalList) {
  List();
  if(this->_header != originalList._header) {
    this->copy(originalList);
  }
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
    while (_current) {
      _saveNext = _current->getNext();
      delete _current;
      _current = _saveNext;
    }
    this->_header = NULL;
    this->len = 0;
  }
}

template <typename T>
T List<T>::getElement(int position) const {
  if (position > 0 && position <= this->len) {

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
  if(!this->empty()) {
    Node<T>* _current = this->_header;
    Node<T>* _next = _current->getNext();

    int i = 1;
    bool found = false;
    while(i <= this->len && !found) {
      if(_current->getData() == element) found = true;
      _current = _next;
      _next = _current->getNext();
      i++;
    }
    if (found) return i-1;
    else return -1;
  }
}

template <typename T>
bool List<T>::exists(T element) const {
  if(!this->empty()) {
    Node<T>* _current = this->_header;
    Node<T>* _next = _current->getNext();
    bool found = false;
    while(_current) {
      if(_current->getData() == element) found = true;
      _current = _next;
      _next = _current->getNext();
    }
    if(found) return true;
    else return false;
  }
}

template <typename T>
void List<T>::print() const {
  if (this->len > 0) {

    Node<T>* _current = this->_header;
    Node<T>* _next = _current->getNext();

    for(int i = 1; i < this->len; i++) {
      cout << _current->getData() << " ";
      _current = _next;
      _next = _current->getNext();
    }
    cout << _current->getData() << endl << endl;
  }
}

template <typename T>
void List<T>::insert(T element, int position) {
  if(position > 0 && position <= (this->len)+1) {

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
    this->len++;
  }
  else {
    cout << "Tried to insert in invalid position" << endl;
  }
}

template <typename T>
void List<T>::removePosition(int position) {
  if (!this->empty() && position >= 1 && position <= this->len) {
    Node<T>* _current = this->_header;
    if (position == 1) {
      this->_header = _current->getNext();
      delete _current;
    }
    else {
      Node<T>* _previous = NULL;
      for (int i = 1; i <= position-1; i++) {
        _previous = _current;
        _current = _current->getNext();
      }
      _previous->setNext(_current->getNext());
      delete _current;
    }
    this->len--;
  }
}
template <typename T>
void List<T>::reverse() {
  if(!this->empty()) {
    Node<T>* _current = this->_header;
    Node<T>* _previous = NULL;
    Node<T>* _next = NULL;

    while(_current) {
      _next = _current->getNext();
      _current->setNext(_previous);
      _previous = _current;
      _current = _next;
    }
    this->_header = _previous;
  }
}

template <typename T>
void List<T>::copy(const List<T>& originalList) {
  if(!originalList.empty()) {
    for(int i = 1; i <= originalList.len; i++) {
      this->insert(originalList.getElement(i), 1);
    }
    this->reverse();
  }
}

template <typename T>
List<T>& List<T>::operator=(const List<T>& originalList) {
  if(!originalList.empty() && this != &originalList) {
    this->flush();
    this->copy(originalList);
  }
  return (*this);
}

template <typename T>
bool List<T>::operator==(const List<T>& toCompare) {
  if(this == &toCompare)
    return true;
  if(this->len != toCompare.len)
    return false;
  
  Node<T>* _currentThis = this->_header;
  Node<T>* _currentCompare = toCompare._header;
  
  while(_currentThis) {
    if(_currentThis->getData() != _currentCompare->getData())
      return false;
    _currentThis = _currentThis->getNext();
    _currentCompare = _currentCompare->getNext();
  }
  return true;
}