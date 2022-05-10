/***************************************************************
* Name: Graziella Buitron
* Coding Final
* Purpose: Create a working bi-directional weighted graph class
***************************************************************/

#include "graph.h"

Graph::Graph(){
	vertexVector = new vector<Vertex>;
	row = NULL;
	col = NULL;
	vertexCount = 0;
	edgeCount = 0;
	rowCount = 0;
	colCount = 0;
}

Graph::~Graph(){

	/*
	for (int i = 0; i < rowCount; i++){
		delete[] bidGraph[i];
	}
	delete[] bidGraph;
	*/
}

bool Graph::isEmpty(){
	bool flag = false;

	return flag;
}

int Graph::getVertexCount(){
	vertexCount = vertexVector->size();
	return vertexCount;
}

int Graph::getEdgeCount(){
	return edgeCount;
}

bool Graph::hasEdge(int vert1, int vert2){
	bool exists = false;

	return exists;
}

bool Graph::addEdge(int vert1, int vert2, int weight){
	bool success = false;



	return success;
}

bool Graph::removeEdge(int vert1, int vert2){
	bool success = false;

	return success;
}

bool Graph::addVertex(int id){
	bool success = false;
	int currentSize = vertexVector->size();

	Vertex *newVertex = new Vertex;
	newVertex->id = id;
	vertexVector->push_back(*newVertex);

	if(vertexVector->size() > currentSize){
		success = true;
	}
	

	return success;
}

bool Graph::removeVertex(int id){
	bool success = false;

	return success;
}

bool Graph::getVertex(int id, Vertex* fillVert){
	bool success;

	return success;
}

void Graph::printGraph(){
	/*
	for (int i = 0; i < vertexVector->size(); i++){
		std::cout << "vertex with id: " << vertexVector[i] << std::endl;
	}
	*/
	return;
}



