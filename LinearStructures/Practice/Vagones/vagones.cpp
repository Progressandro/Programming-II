#include <iostream>
#include "Stack.hpp"
#include "List.hpp"

int main() {
  Stack<int> vagones;
  int numVagones;
  
  while (cin >> numVagones && numVagones) {
    int vagon;
    while (cin >> vagon && vagon) {
      vagones.push(vagon);
      for (int i = 1; i<numVagones; i++) {
        cin >> vagon;
        vagones.push(vagon);
      }
      vagones.print();
      vagones.flush();
    }
  }
  return 0;
}