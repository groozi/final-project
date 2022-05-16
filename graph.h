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
    Graph(); //done
    ~Graph();
    bool isEmpty(); //done
    int getVertexCount(); //done
    int getEdgeCount(); //returns count of edges in entire graph done
    bool hasEdge(int, int); //done
    bool addEdge(int, int, int); //done
    bool removeEdge(int, int); //done
    bool addVertex(int); //done
    bool removeVertex(int); //done
    bool getVertex(int, Vertex*); //done
    void printGraph(); //done
    void bFirst(int); //breadth first traversal
    void dFirst(int);  //depth first traversal
    void clearGraph();
    
private:

   vector<Vertex> *vertexVector; 
   int vertexCount;
   int edgeCount;
   bool exists(int);
   int findIndex(int); //done
   //void prepEdgePair(int, int, int, EdgePair**);


};

#endif //STACK_H