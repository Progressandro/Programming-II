#include <iostream>
#include <utility>
#include <list>
#include <vector>
#include <string>
#include "NodeBT.hpp"
#include "BinaryTree.hpp"
using namespace std;
vector<string> explode(const string& str, const char& ch);
int main() {
  string element;
  vector<string> paired;
  list<string> prepared_paths;
  list<string> prepared_values;
  BinaryTree<string> tree;
  while (cin >> element) {
    if (element != "()") {
      // removing parentheses
      element = element.substr(1, element.length() - 2);
      paired = explode(element, ',');
      if (!paired.empty()) {
        prepared_values.push_back(paired[0]);
        prepared_paths.push_back(paired[1]);
      }
    } else {
      if (!prepared_paths.empty()) {
        for (list<string>::iterator it = prepared_paths.begin(); it != prepared_paths.end(); it++) {
        }
        if (tree.populatePair(prepared_values, prepared_paths)) {
          tree.levelOrderTraversal();
        }
        else cout << "no completo";
        prepared_paths.clear();
        prepared_values.clear();
        tree.flush();
        cout << endl;
      }
    }
  }
  return 0;
}

vector <string> explode(const string& str, const char& ch) {
    string next;
    vector<string> result;

    for (string::const_iterator it = str.begin(); it != str.end(); it++) {
        if (*it == ch) {
            if (!next.empty()) {
                result.push_back(next);
                next.clear();
            }
        } else {
            next += *it;
        }
    }
    if (!next.empty()) result.push_back(next);

    if (result.size() == 1) result.push_back("R");
    return result;
}
