#include "NodeBT.hpp"
#include <iostream>
void printNode(NodeBT<int>* _node);

int main() {
  NodeBT<int>* _testNode = new NodeBT<int>;
  NodeBT<int>* _leftC = new NodeBT<int>;
  NodeBT<int>* _rightC = new NodeBT<int>;
  _testNode->setData(3);
  _leftC->setData(9);
  _rightC->setData(-3);

  _testNode->setLeft(_leftC);
  _testNode->setRight(_rightC);

  printNode(_testNode);
  _testNode = _rightC;
  printNode(_testNode);
  return 0;
}

void printNode(NodeBT<int>* _node) {
  if (_node->getLeft()) printNode(_node->getLeft());
  if (_node) cout << _node->getData() << " ";
  if (_node->getRight()) printNode(_node->getRight());
}
