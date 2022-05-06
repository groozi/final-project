/***************************************************************
* Name: Graziella Buitron
* Coding Final
* Purpose: Create a working bi-directional weighted graph class
***************************************************************/
#ifndef GRAPH_H
#define GRAPH_H

#include "data.h"
#define MIN_SIZE 2

class Graph {

public:
    Graph();
    ~Graph();

    
private:
   Node **bidGraph;
   int nodeCount;
   Node* row;
   Node* col;
   int rowCount;
   int colCount;
};

#endif //STACK_H