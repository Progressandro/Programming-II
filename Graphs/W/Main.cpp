#include <iostream>
#include <vector>
#include "Graph.hpp"
using namespace std;

void testPrint(Graph<int,int> graph);

int main() {
  Graph<int, int> graph;
  int vertices, edges, u, v, w;
  cin >> vertices >> edges;

  for (int i = 0; i < vertices; i++) graph.insertVertex(i);

  for (int j = 0; j < edges; j++) {
    cin >> u >> v >> w;
    graph.insertEdge(u, v, w);
  }
  vector<int> pre = graph.predecessors(6);
  for (int vertex : pre) {
    cout << "Predecessor: " << vertex << endl;
  }
  return 0;
}

void testPrint(Graph<int, int> graph) {
  cout << graph;
}
