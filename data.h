/***************************************************************
* Name: Graziella Buitron
* Coding Final
* Purpose: Create a working bi-directional weighted graph class
***************************************************************/

#ifndef DATA_H
#define DATA_H

#include "string"
using std::string;

struct VertWithEdge {
    int fromVertex;
    int toVertex;
    int weight;
    VertWithEdge *next;
    VertWithEdge *prev;


    //string data;
};

struct Vertex {
    int numEdges;
    VertWithEdge *head;
    int id;

};

#endif /* DATA_H */