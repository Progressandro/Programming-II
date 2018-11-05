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
  NodeBT(T data) {this->data = data;}
  ~NodeBT();

  bool getData() {return this->data;}
  void setData(T data) {this->data = data;}
  T getLeft() {return this->_left;}
  void setLeft(T data) {this->_left = data;}
  T getRight() {return this->_right;}
  void setRight(T data) {this->_right = data;}
  NodeBT<T>* copy(NodeBT<T>* _originalNode);
  NodeBT<T>& operator=(const NodeBT<T>& originalList);
  void printNode(NodeBT<T>* _node);

};

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

template <typename T>
void NodeBT<T>::printNode(NodeBT<T>* _node) {
  if (!_node) return;
  if (_node->left) printNode(_node->left);
  if (_node->right) printNode(_node->right);
  cout << _node->getData() << " ";
}

#endif
