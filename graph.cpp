/***************************************************************
* Name: Graziella Buitron
* Coding Final
* Purpose: Create a working bi-directional weighted graph class
***************************************************************/

#include "graph.h"

Graph::Graph(){
	row = NULL;
	col = NULL;

}

Graph::~Graph(){
	for (int i = 0; i < rowCount; i++){
		delete[] bidGraph[i];
	}
	delete[] bidGraph;

}