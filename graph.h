/***************************************************************
* Name: Graziella Buitron
* Coding Final
* Purpose: Create a working bi-directional weighted graph class
***************************************************************/
#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
//#include <iostream>
#include "data.h"
#define MIN_SIZE 2

//using std::cout;
//using std::endl;
using std::vector;

class Graph{

public:
    Graph();
    ~Graph();
    bool isEmpty();
    int getVertexCount();
    int getEdgeCount();
    bool hasEdge(int, int);
    bool addEdge(int, int, int);
    bool removeEdge(int, int);
    bool addVertex(int);
    bool removeVertex(int);
    bool getVertex(int, Vertex*);
    void printGraph(); 


    
private:

   vector<Vertex> *vertexVector; 
   //Vertex *bidGraph;
   int vertexCount;
   int edgeCount;
   Vertex* row;
   Vertex* col;
   int rowCount;
   int colCount;
};

#endif //STACK_H