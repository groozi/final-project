/***************************************************************
* Name: Graziella Buitron
* Coding Final
* Purpose: Create a working bi-directional weighted graph class
***************************************************************/

#ifndef DATA_H
#define DATA_H

#include "string"
using std::string;

struct EdgePair {
    int fromVertex;
    int toVertex;
    int weight;
    EdgePair *next;
    EdgePair *prev;


    //string data;
};

struct Vertex {
    int numEdges; //must account for adding edges to vertex
    EdgePair *head;
    int id;

};

#endif /* DATA_H */