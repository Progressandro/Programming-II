#include <iostream>
#include "List.hpp"

using namespace std;

int main() {
  List<int> a;

  a.insert(4,1);
  cout << "A 4 should appear below: " << endl;
  cout << a.getElement(1) << endl;
  a.insert(3,2);
  cout << "A 3 should appear below: " << endl;
  cout << a.getElement(2) << endl;
  a.insert(2,3);
  cout << "A 2 should appear below: " << endl;
  cout << a.getElement(3) << endl;
  a.insert(1,4);
  cout << "A 1 should appear below: " << endl;
  cout << a.getElement(4) << endl;
  a.insert(0,5);
  cout << "A 0 should appear below: " << endl;
  cout << a.getElement(5) << endl;
  a.insert(5,1);
  cout << "A 5 should appear below: " << endl;
  cout << a.getElement(1) << endl;
  cout << "Now all the elements: " << endl;
  a.print();
  return 0;
}
