#ifndef EDGE_HPP
#define EDGE_HPP
#include <iostream>

template <class T, typename C>
class Vertex;

template <class T, typename C>
class Edge {
private:

  C weight;
  Vertex<T, C>* _owner;
  Edge* _next;

public:
  Edge(): weight(0), _owner(NULL), _next(NULL) {}
  Edge(C weight): weight(weight), _owner(NULL), _next(NULL) {}
  Edge(C weight, Vertex<T,C>* _owner): weight(weight), _owner(_owner), _next(NULL) {}
  Edge(C weight, Vertex<T,C>* _owner, Edge* _next): weight(weight), _owner(_owner), _next(_next) {}
  T getData() const {return this->_owner->getData();}
  C getWeight() const {return this->weight;}
  Vertex<T,C>* getVertex() const {return this->_owner;}
  Edge* getNext() const {return this->_next;}

  void setVertex(Vertex<T,C>* _toAssign) {this->_owner = _toAssign;}
  void setWeight(C weight) {this->weight = weight;}
  void setNext(Edge* _next) {this->_next = _next;}
};
#endif
