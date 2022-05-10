/***************************************************************
* Name: Graziella Buitron
* Coding Final
* Purpose: Create a working bi-directional weighted graph class
***************************************************************/

#ifndef DATA_H
#define DATA_H

#include "string"
using std::string;

struct Edge {
    int fromVertex;
    int toVertex;
    //string data;
};

struct Vertex {
    int numEdges;
    Edge edge;
    int id;
    //Node *next;
    //Node *prev;
};

#endif /* DATA_H */