/***************************************************************
* Name: Graziella Buitron
* Coding Final
* Purpose: Create a working bi-directional weighted graph class
***************************************************************/

#include "graph.h"

Graph::Graph(){
	vertexVector = new vector<Vertex>;
	/*
	row = NULL;
	col = NULL;
	vertexCount = 0;
	edgeCount = 0;
	rowCount = 0;
	colCount = 0;
	*/
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
	int currentEdges = edgeCount;

	if (exists(vert1) && exists(vert2)){

		if (vertexVector->at(vert1-1).head == NULL){
			VertWithEdge *newVertEdge = new VertWithEdge;
			newVertEdge->fromVertex = vert1;
			newVertEdge->toVertex = vert2;
			newVertEdge->weight = weight;
			newVertEdge->prev = NULL;
			newVertEdge->next = NULL;
			vertexVector->at(vert1-1).head = newVertEdge;
			edgeCount++;
			
			if (edgeCount > currentEdges){
				success = true;
			}

			//cout << "empty here" << endl;
		} else{
			cout << "not added" << endl;
		}

		success = true;

	}


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
	newVertex->head = NULL;
	newVertex->numEdges = 0;
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
	
	for (int i = 0; i < vertexVector->size(); i++){
		cout << "vertex " << vertexVector->at(i).id << ": ";

		VertWithEdge *current = vertexVector->at(i).head;

		if (current){
			//cout << "edges exists here" << endl;

			cout << "edge to vertex " << current->toVertex << " with weight " << current->weight << endl;

			while (current){
				current = current->next;
			}

			/*
			cout << ": edge from " << vertexVector->at(i).id << " to " << vertexVector->at(i).head->next->toVertex;

			while (current){

			 current = current->next;
			}
			*/

		}else{
			cout << "no edges from this vertex" << endl;
		}

	}
	
	return;
}

bool Graph::exists(int id){
	bool vertFound = false;

	for (int i = 0; i < vertexVector->size(); i++){
		if (vertexVector->at(i).id == id){
			vertFound = true;
		}
	}

	return vertFound;
}



