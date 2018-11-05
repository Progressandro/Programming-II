#ifndef NODEBT_HPP
#define NODEBT_HPP

#include <iostream>
using namespace std;

template <typename T>
class NodeBT {
private:
  T data = T();
  NodeBT<T>* _left = NULL;
  NodeBT<T>* _right = NULL;

public:
  NodeBT();
  NodeBT(T data) {this->data = data;}
  ~NodeBT();

  T getData() {return this->data;}
  void setData(T data) {this->data = data;}
  NodeBT<T>* getLeft() {return this->_left;}
  void setLeft(NodeBT<T>* _newLeft) {this->_left = _newLeft;}
  NodeBT<T>* getRight() {return this->_right;}
  void setRight(NodeBT<T>* _newRight) {this->_right = _newRight;}
  NodeBT<T>* copy(NodeBT<T>* _originalNode);
  NodeBT<T>& operator=(const NodeBT<T>& originalList);
};
template <typename T>
NodeBT<T>::NodeBT() {

}
template <typename T>
NodeBT<T>* NodeBT<T>::copy(NodeBT<T>* _originalNode) {
  NodeBT<T>* _root = new NodeBT<T>;

  _root->setData(_originalNode->data);

  if(_originalNode->_left) _root->_left = copy(_originalNode->_left);

  if(_originalNode->_right) _root->_right = copy(_originalNode->_right);

  return _root;
}

template <typename T>
NodeBT<T>& NodeBT<T>::operator=(const NodeBT<T>& originalNode) {
  NodeBT<T>* _returnedNode;
  _returnedNode = copy(*originalNode);

  return _returnedNode;
}

#endif
