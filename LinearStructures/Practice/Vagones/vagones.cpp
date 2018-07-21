#include <iostream>
#include "Stack.hpp"
#include "List.hpp"

void reorganizable(List<int> vagones);

int main() {
  List<int> vagones;
  int numVagones;
  
  while (cin >> numVagones && numVagones) {
    int vagon;
    while (cin >> vagon && vagon) {
      vagones.insert(vagon, 1);
      for (int i = 1; i<numVagones; i++) {
        cin >> vagon;
        vagones.insert(vagon, 1);
      }
      vagones.reverse();
      reorganizable(vagones);
      vagones.flush();
    }
  }
  return 0;
}

void reorganizable(List<int> vagones) {
  for(int i = 0; i < vagones.lenght(); i++) {
    
  }
}
