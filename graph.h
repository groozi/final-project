/***************************************************************
* Name: Graziella Buitron
* Coding Final
* Purpose: Create a working bi-directional weighted graph class
***************************************************************/
#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>
#include <queue>
#include "data.h"
#define MIN_SIZE 2

using std::queue;
using std::cout;
using std::endl;
using std::vector;

class Graph{

public:
    Graph();
    ~Graph();
    bool isEmpty();
    int getVertexCount();
    int getEdgeCount(); //returns count of edges in entire graph
    bool hasEdge(int, int);
    bool addEdge(int, int, int);
    bool removeEdge(int, int);
    bool addVertex(int);
    bool removeVertex(int);
    bool getVertex(int, Vertex*);
    void printGraph();
    void bFirst(int); //breadth first traversal
    void dFirst(int);  //depth first traversal
    void clearGraph();
    
private:
   vector<Vertex> *vertexVector; 
   int vertexCount;
   int edgeCount;
   bool exists(int);
   int findIndex(int);
};

#endif //GRAPH_H