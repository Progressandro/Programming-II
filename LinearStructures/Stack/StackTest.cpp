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
  a.print();
  a.flush();
  cout << "After" << endl;
  a.print();
  return 0;
}

void copycheck(Stack<int> a) {
  a.push(5);
  a.print();
}