#include <iostream>
#include "Stack.hpp"
using namespace std;

void copycheck(Stack<int> a);
int main() {
  Stack<int> a, b(4), c;
  
  a.push(5);
  a.push(6);
  a.print();
  copycheck(a);
  cout << "After copy: " << endl;
  a.print();
  a.reverse();
  cout << "After reverse: " << endl;
  a.print();
  // a = b;
  // cout << "Should print a 4: " << endl;
  // a.print();
  a.flush();
  cout << "After flush:" << endl;
  a.print();
  return 0;
}

void copycheck(Stack<int> a) {
  cout << "Copy: " << endl;
  a.print();
  a.push(6);
  cout << "Modified copy(+6)" << endl;
  a.print();
}