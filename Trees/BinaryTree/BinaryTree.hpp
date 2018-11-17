#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP
#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include "NodeBT.hpp"

using namespace std;
using std::list;

template <typename T>
class BinaryTree {
private:
  NodeBT<T>* _root;

public:
  BinaryTree();
  ~BinaryTree();
  void flush();
  void flush(NodeBT<T>* _destroy);
  void copy(BinaryTree<T> originalTree);
  NodeBT<T>* copy(NodeBT<T>* _root);
  void setRoot(NodeBT<T>* _newRoot) {this->_root = _newRoot;}
  bool isNull() {return this->_root;}
  BinaryTree<T> getLeft();
  BinaryTree<T> getRight();
  void levelOrderTraversal();
  bool populatePair(list<string> input_values, list<string> input_paths);
  BinaryTree<T>& operator= (const BinaryTree<T> originalTree);
};

template <typename T>
BinaryTree<T>::BinaryTree() {
  this->_root = NULL;
}

template <typename T>
BinaryTree<T>::~BinaryTree() {
  this->flush(this->_root);
}

template <typename T>
void BinaryTree<T>::flush() {
  this->flush(this->_root);
  this->_root = NULL;
}

template <typename T>
void BinaryTree<T>::flush(NodeBT<T>* _destroy) {
  if (_destroy) {
    if (!_destroy->getLeft() && !_destroy->getRight()) {
      delete(_destroy);
    } else {
      this->flush(_destroy->getLeft());
      this->flush(_destroy->getRight());
      delete(_destroy);
    }
  }
}
template <typename T>
void BinaryTree<T>::copy(BinaryTree<T> originalTree) {
  NodeBT<T>* _newRoot = new NodeBT<T>;
  _newRoot.copy(originalTree._root);

  this->_root = _newRoot;
}

template <typename T>
NodeBT<T>* BinaryTree<T>::copy(NodeBT<T>* _root) {
  NodeBT<T>* _newRoot;

  if (_root) {
    _newRoot = new NodeBT<T>;
    _newRoot->build(_root->data, this->copy(_root->_left), this->copy(_root->_right));
  }
}

template <typename T>
bool BinaryTree<T>::populatePair(list<string> input_values, list<string> input_paths) {

	string path;
	string placeholder = "unassigned";
	int balance = 1;
	NodeBT<T> *_current, *_newNode;

	this->_root = new NodeBT<T>;
	this->_root->setData(placeholder);

	while (!input_paths.empty()) {

		_current = this->_root;
		if (input_paths.front() != "R") {

			path = input_paths.front();

			for(string::iterator it = path.begin(); it != path.end(); it++) {
				if (*it == 'I') {

					if (!_current->getLeft()) {
						_newNode = new NodeBT<T>;
						_newNode->setData(placeholder);
						_current->setLeft(_newNode);
						balance++;
					}
					_current = _current->getLeft();
				} else {
					if (!_current->getRight()) {
						_newNode = new NodeBT<T>;
						_newNode->setData(placeholder);
						_current->setRight(_newNode);
						balance++;
					}
					_current = _current->getRight();
				}
			}

		}
		if (_current->getData() == placeholder) {
			_current->setData(input_values.front());
			balance--;
		}else {
			return (false);
		}
		input_values.pop_front();
		input_paths.pop_front();
	}
	return (balance == 0);
}

template <typename T>
void BinaryTree<T>::levelOrderTraversal() {
  queue<NodeBT<T>*> q;

  q.push(this->_root);

  while (!q.empty()) {
    NodeBT<T>* _current = q.front();
    cout << _current->getData() << " ";
    q.pop();
    if (_current->getLeft()) q.push(_current->getLeft());
    if (_current->getRight()) q.push(_current->getRight());
  }
}

template <typename T>
BinaryTree<T>& BinaryTree<T>::operator= (const BinaryTree<T> originalTree) {
  if (originalTree != this) {
    this->copy(originalTree);
  }
}

#endif
