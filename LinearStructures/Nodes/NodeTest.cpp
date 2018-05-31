#include <iostream>
#include "Node.hpp"

int main() {
  Node<int> first, second, third;

  first.setData(5);
  cout << "Next line should be a 5: " << endl;
  cout << first.getData() << endl;
  second = first;
  cout << "Another 5:" << endl << first.getData() << endl;
  third.copy(second);
  cout << "And another 5:" << endl << third.getData() << endl;

  return 0;
}
