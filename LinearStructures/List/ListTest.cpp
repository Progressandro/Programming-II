#include <iostream>
#include "List.hpp"

using namespace std;

int main() {
  List<int> a, b;

  cout << endl << "List A: " << endl << "--------------" << endl;
  a.insert(4,1);
  cout << "A 4 should appear below: " << endl << endl;
  cout << a.getElement(1) << endl << endl;
  a.insert(3,2);
  cout << "A 3 should appear below: " << endl << endl;
  cout << a.getElement(2) << endl << endl;
  a.insert(2,3);
  cout << "A 2 should appear below: " << endl << endl;
  cout << a.getElement(3) << endl << endl;
  a.insert(1,4);
  cout << "A 1 should appear below: " << endl << endl;
  cout << a.getElement(4) << endl << endl;
  a.insert(0,5);
  cout << "A 0 should appear below: " << endl << endl;
  cout << a.getElement(5) << endl << endl;
  a.insert(5,1);
  cout << "A 5 should appear below: " << endl << endl;
  cout << a.getElement(1) << endl << endl;
  cout << "Now all the elements: " << endl << endl;
  a.print();
  cout << "Now the same list in reverse: " << endl << endl;
  a.reverse(); a.print();
  b = a;
  cout << "Now let's destroy the list. (Not visual)" << endl << endl;
  a.flush();
  cout << "Lenght after flush: " << endl << endl;
  cout << a.getLenght() << endl << endl;
  cout << "Print after flush (shouldn't show anything): " << endl << endl;
  a.print();
  cout << "List B:" << endl << "-----------" << endl;
  cout << "This should print the A list in reverse: " << endl;
  b.print();
  cout << "This should print a 3: " << endl;
  cout << b.indexOf(2) << endl;
  return 0;
}
