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
    cout << endl;
  }
  return 0;
}

void reorganizable(List<int> vagones) {
  int i = 1;
  Stack<int> calleCiega;
  List<int> salida, respaldo;
  int len = vagones.lenght();
  respaldo = vagones;
  
  while (!vagones.empty() && i <= len) {
    if (vagones.getElement(1) == i) {
      salida.insert(vagones.getElement(1), 1);
      vagones.removePosition(1);
      i++;
    }
    else {
      if(!calleCiega.empty()) {
        if(calleCiega.peek() == vagones.getElement(1)) {
          salida.insert(calleCiega.peek(), 1);
          calleCiega.pop();
          vagones.removePosition(1);
        }
        else {
          calleCiega.push(i);
          i++;
        }
      }
      else {
        calleCiega.push(i);
        i++;
      }
    }
  }
  
  while (!calleCiega.empty()) {
    salida.insert(calleCiega.peek(), 1);
    calleCiega.pop();
  }
  salida.reverse();
  if (salida == respaldo)
    cout << "Si" << endl;
  else 
    cout << "No" << endl;
}
