#ifndef NODEBT_HPP
#define NODEBT_HPP

#include <iostream>
using namespace std;

template <typename T>
class NodeBT {
private:
  T data;
  NodeBT<T>* _left;
  NodeBT<T>* _right;
public:
  NodeBT();
  NodeBT(T data) {this->data = data;}
  void build(T data, NodeBT<T>* lc, NodeBT<T>* rc);
  T getData() const{return this->data;}
  void setData(T data) {this->data = data;}
  NodeBT<T>* getLeft() const {return this->_left;}
  void setLeft(NodeBT<T>* _newLeft) {this->_left = _newLeft;}
  NodeBT<T>* getRight() const {return this->_right;}
  void setRight(NodeBT<T>* _newRight) {this->_right = _newRight;}
  int getLevel() const {return this->level;}
  void setLevel(int level) {this->level = level;}
  NodeBT<T>* copy(NodeBT<T>* _originalNode);
  NodeBT<T>& operator=(const NodeBT<T>& originalList);
};
template <typename T>
NodeBT<T>::NodeBT() {
  this->data = T();
  this->_left = NULL;
  this->_right = NULL;
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
void NodeBT<T>::build(T data, NodeBT<T>* lc, NodeBT<T>* rc) {
  this->data = data;
  this->_left = lc;
  this->_right = rc;
}

template <typename T>
NodeBT<T>& NodeBT<T>::operator=(const NodeBT<T>& originalNode) {
  NodeBT<T>* _returnedNode;
  _returnedNode = copy(*originalNode);

  return _returnedNode;
}

#endif
