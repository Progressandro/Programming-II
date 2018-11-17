#ifndef VERTEX_HPP
#define VERTEX_HPP
#include <iostream>
#include <vector>
#include "Edge.hpp"

using std::vector;
template <class T, typename C>
class Edge;

template <class T, typename C>
class Graph;

template <class T, typename C>
class Vertex {
private:
  friend class Graph<T,C>;
  friend class Edge<T,C>;
  T data;
  bool visited;
  Vertex* _next;
  Edge<T, C>* _edges;
  int innerDegree;
  int outerDegree;

public:
  Vertex(): _edges(NULL), _next(NULL), visited(false), innerDegree(0), outerDegree(0) {}
  Vertex(T data): data(data), _edges(NULL), _next(NULL), innerDegree(0), outerDegree(0){};
  ~Vertex();

  T getData() const {return this->data;}
  bool isVisited() const {return this->visited;}
  Vertex<T, C>* getNext() const {return this->_next;}
  Edge<T,C>* getEdge() const {return this->_edges;}
  vector<T> successors() const;

  void setVisited() {this->visited = true;}
  void setData(T data) {this->data = data;}
  void setNext(Vertex* _newNext) {this->_next = _newNext;}

  void insertEdge(Vertex* _toInsert, C weight);
  void deleteEdge(Vertex* _toDelete);
};

template <class T, typename C>
Vertex<T, C>::~Vertex() {
  Edge<T, C>* _toDelete;
  while (this->_edges) {
    _toDelete = _edges;
    _edges = _toDelete->getNext();
    _toDelete->getVertex()->innerDegree--;
    delete _toDelete;
  }
}

template <class T, typename C>
vector<T> Vertex<T, C>::successors() const {
  vector<T> toReturn;

  Edge<T, C>* _current = this->_edges;
  while (_current) {
    toReturn.push_back(_current->getData());
    _current = _current->getNext();
  }
  return toReturn;
}

template <class T, typename C>
void Vertex<T, C>::insertEdge(Vertex* _owner, C weight) {
  if (this!= _owner) {
    Edge<T, C>* _current = this->_edges;
    Edge<T, C>* _previous = NULL;
    bool inserted = false;
    while (_current && !inserted) {
      inserted = (_current->getData() == _owner->getData());
      _previous = _current;
      _current = _current->getNext();
    }

    if (!inserted) {
      Edge<T, C>* _newEdge;

      if (!_previous && !_current) {
        _current = this->_edges;
        _newEdge = new Edge<T,C>(weight, _owner, _current);
        this->_edges = _newEdge;
      } else {
        _newEdge = new Edge<T, C>(weight, _owner, NULL);
        _previous->setNext(_newEdge);
      }

      _newEdge->getVertex()->innerDegree++;
      this->outerDegree++;
    }
  }
}

template <class T, typename C>
void Vertex<T, C>::deleteEdge(Vertex* _toDelete) {
  Edge<T, C>* _current = this->_edges;
  Edge<T, C>* _aux = NULL;

  while (_current) {
    if (_current->getVertex() == _toDelete) {
      if (_aux) _aux->setNext(_current->getNext());
      else this->_edges = _current->getNext();
    }

    _current->getVertex()->innerDegree--;
    this->outerDegree--;
  }
}

#endif
