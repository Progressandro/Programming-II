#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <limits>
#include <algorithm>
#include "Edge.hpp"
#include "Vertex.hpp"
#include <list>
using std::ostream;
using std::cout;
using std::endl;
using std::vector;
using std::list;

template <class T, typename C>
class Graph {
private:
  Vertex<T,C>* _graph;

  Edge<T,C>* getEdge(T element) const;
  Vertex<T,C>* getVertex(T element) const;

public:
  Graph(): _graph(NULL) {}
  Graph(const Graph &g);
  ~Graph();
  void destroy();

  //Core functionalities
  void insertVertex(T vertexData);
  vector<T> getVertices() const;
  void removeVertex(T vertexData);
  void insertEdge(T vi, T vj, C weight);
  C edgeWeight(T departureVertex, T arrivalVertex) const;
  vector<T> sourceVertex() const;
  Graph<T,C> findCycle() const;
  vector<T> predecessors(T) const;
  void compressGraph(const Graph<T,C> &cycle);
  C predecessorsMinimumEdge(T e) const;
  Graph<T,C> getCycle() const;
  vector<T> sources() const;
  //Properties
  bool empty() const {return !(this->_graph);}
  int order() const;

  //Traversals
  vector<T> BFS() const;


  template<class M, typename N>
  friend std::ostream& operator<<(std::ostream&, const Graph<M,N>&);
  Graph<T, C>& operator= (const Graph<T, C>& original);
  void copy(const Graph<T,C>& copy);
};

template <class T, typename C>
Graph<T,C>::Graph(const Graph& copy) {
  this->copy(copy);
}

template <class T, typename C>
void Graph<T,C>::copy(const Graph<T,C>& copy) {
  if (copy._graph) {
    Vertex<T,C>* _original;
    Vertex<T,C>* _toCopy;
    this->_graph = new Vertex<T,C>(copy._graph->getData());

    _original = this->_graph;
    _toCopy = copy._graph;

    while (_toCopy->getNext()) {
      _toCopy = _toCopy->getNext();
      _original->setNext(new Vertex<T,C>(_toCopy->getData()));
      _original = _original->getNext();
    }

    for (_toCopy = copy._graph; _toCopy; _toCopy = _toCopy->getNext()) {
      Edge<T,C>* _copyEdges = _toCopy->_edges;
      while (_copyEdges) {
        this->insertEdge(_toCopy->getData(), _copyEdges->getData(), _copyEdges->getWeight());
        _copyEdges = _copyEdges->getNext();
      }
    }
  }
}


template <class T, typename C>
Graph<T,C>::~Graph() {
  if (this) {
    this->destroy();
  }
}

template <class T, typename C>
void Graph<T,C>::destroy() {
  Vertex<T,C>* _toDelete;
  while (this->_graph) {
    _toDelete = this->_graph;
    this->_graph = this->_graph->getNext();
    delete _toDelete;
  }
}

template <class T, typename C>
void Graph<T,C>::insertVertex(T vertexData) {

  if (this->_graph) {
    if (this->_graph->getData() > vertexData) {
      Vertex<T,C>* _newVertex = new Vertex<T,C>(vertexData);
      _newVertex->setNext(this->_graph);
      this->_graph = _newVertex;
    }
    else {
      Vertex<T,C>* _current = this->_graph;
      Vertex<T,C>* _previous;

      while (_current && _current->getData() <= vertexData) {
        if (_current) {
          if (_current->getData() == vertexData) _previous = NULL;
          else _previous = _current;
        }
        _current = _current->getNext();
      }

      if (_previous) {
        _previous->setNext(new Vertex<T,C>(vertexData));
        _previous->getNext()->setNext(_current);
      }

    }
  }
  else this->_graph = new Vertex<T,C>(vertexData);
}

template <class T, typename C>
Vertex<T,C>* Graph<T,C>::getVertex(T element) const {
  Vertex<T,C>* _current = this->_graph;

  while (_current) {
    if (_current->getData() == element) return _current;

    _current = _current->getNext();
  }

  return NULL;
}

template <class T, typename C>
void Graph<T,C>::removeVertex(T vertexData) {
  Vertex<T,C>* _vertex = this->getVertex(vertexData);
  if (_vertex) {
    for (Vertex<T,C>* it = this->_graph; it; it = it->getNext()) {
      it->removeEdge(_vertex);
    }

    if (_vertex != this->_graph) {
      Vertex<T,C>* _aux = this->_graph;

      while (_aux->getNext() != _vertex) {
        _aux = _aux->getNext();
      }
      _aux->setNext(_vertex->getNext());
    }
    else {
      this->_graph = this->_graph->getNext();
    }
    delete _vertex;
  }

}

template <class T, typename C>
void Graph<T,C>::insertEdge(T vi, T vj, C weight) {
  if (vi != vj) {
    Vertex<T,C>* _toVi = getVertex(vi);
    Vertex<T,C>* _toVj = getVertex(vj);

    if (_toVi && _toVj) {
      _toVi->insertEdge(_toVj, weight);
    }
  }
}

template <class T, typename C>
C Graph<T,C>::edgeWeight(T departureVertex, T arrivalVertex) const {

  Edge<T,C> searchedEdge = getEdge(departureVertex, arrivalVertex);
  if (searchedEdge) return searchedEdge->getWeight();
  else return -1;
}

template <class T, typename C>
vector<T> Graph<T,C>::sourceVertex() const {
  Vertex<T,C> *_v = this->_graph;
  vector<T> to_return;

  while (_v) {
    if (_v->getIn() == 0) {
      to_return.push_back(_v->getIn());
    }
    _v = _v->getNext();
  }
  return to_return;
}

template<class T, typename C>
Graph<T,C> Graph<T,C>::findCycle() const {
    Graph<T,C> in(*this);
    vector<T> suc;
    suc = in.sourceVertex();

    while (!suc.empty()) {
        while (!suc.empty()) {
            T u = suc.back();
            suc.pop_back();
            in.deleteVertex(u);
        }
        suc = in.sourceVertex();
    }
    return in;;
}

template<class T, typename C>
vector<T> Graph<T,C>::predecessors(T e) const {
  vector<T> output;
  for (Vertex<T,C>* _vertex = this->_graph; _vertex; _vertex = _vertex->getNext()) {
    if (_vertex->getData() != e) {
      for (Edge<T,C>* _edgeList = _vertex->_edges; _edgeList; _edgeList = _edgeList->getNext()) {
        if (_edgeList->getData()  == e) {
          output.push_back(_vertex->getData());
        }
      }
    }
  }
  return output;
}

template<class T, typename C>
C Graph<T,C>::predecessorsMinimumEdge(T e) const {
    Vertex<T,C>* _currentVertex;
    C min = 1000000;

    _currentVertex = this->_graph;
    while (_currentVertex) {
      if (_currentVertex->getData() != e) {
        Edge<T,C> *_currentEdge = _currentVertex->_edges;
        while (_currentEdge) {
          if (_currentEdge->getVertex()->getData() == e && _currentEdge->getWeight() < min) {
            min = _currentEdge->getWeight();
          }

          _currentEdge = _currentEdge->getNext();
        }
      }
      _currentVertex = _currentVertex->getNext();
    }
    return min;
}

template <class T, typename C>
Graph<T,C> Graph<T,C>::getCycle() const {
  Graph<T,C> copy(*this);
  vector<T> sources = copy.sources();

  while(!sources.empty()) {
    while(!sources.empty()) {
      T u = *(sources.begin());
      sources.erase(sources.begin());
      copy.removeVertex(u);
    }
    sources = copy.sources();
  }
  cout << copy;
  return copy;
}

template<class T, typename C>
vector<T> Graph<T,C>::sources() const
{
    Vertex<T,C>* _current = this->_graph;
    vector<T> output;
    while (_current)
    {
        if (_current->innerDegree == 0)
            output.push_back(_current->getData());
        _current = _current->getNext();
    }
    return output;
}

template <class T, typename C>
void Graph<T,C>::compressGraph(const Graph<T,C> &cycle) {

  vector<T> cyclicVertices = cycle.getVertices();
  Vertex<T,C> *_new = new Vertex<T,C>(this->order());
  Vertex<T,C> *_act, *_aux;
  C weight;

  while (!cyclicVertices.empty()) {
    vector<T> pre = this->predecessors(cyclicVertices.front());

    while (!pre.empty()) {
      if (!std::find(cyclicVertices.begin(), cyclicVertices.end(), pre.front())) {
        weight = this->edgeWeight(pre.front(), cyclicVertices.front());
        _act = this->getVertex(pre.front());
        _aux = this->getVertex(cyclicVertices.front());
        _act->removeEdge(_aux);
        _act->insertEdge(_new, weight - this->predecessorsMinimumEdge(_aux->getData()));
      }
      pre.erase(pre.begin());
    }
    cyclicVertices.erase(cyclicVertices.begin());
  }
}

template <class T, typename C>
int Graph<T,C>::order() const {
  Vertex<T,C>* _current = _graph;
  int vertexCount = 0;
  while (_current) {
    _current = _current->getNext();
    vertexCount++;
  }

  return vertexCount;
}

template <class T, typename C>
vector<T> Graph<T,C>::getVertices() const {
  vector<T> output;
  Vertex<T,C>* _current = this->_graph;

  while (_current) {
    output.push_back(_current->getData());
    _current = _current->getNext();
  }

  return output;
}



template<class M, typename N>
std::ostream& operator<<(std::ostream& output, const Graph<M,N> &toPrint)
{
    Vertex<M,N> *_current = toPrint._graph;
    while (_current)
    {
        output << "Vertex: " << _current->getData() << " || Edges: ";
        Edge<M,N>* _edge = _current->getEdge();
        while (_edge)
        {
            output << " " << _edge->getData();
            _edge = _edge->getNext();
        }
        output << endl;
        _current = _current->getNext();
    }
    return output;
}

template <class T, typename C>
Graph<T, C>& Graph<T,C>::operator= (const Graph<T, C>& original) {

}
#endif
