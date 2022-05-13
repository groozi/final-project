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

	if(getVertexCount() < 1){
		flag = true;
	}

	return flag;
}

int Graph::getVertexCount(){
	//vertexCount = vertexVector->size();
	return vertexVector->size();
}

int Graph::getEdgeCount(){
	return edgeCount;
}

bool Graph::hasEdge(int vert1, int vert2){
	bool flag = false;

	if (exists(vert1) && exists(vert2)){

		EdgePair *current = vertexVector->at(findIndex(vert1)).head;

		while(current->toVertex != vert2 && current->next){
			current = current->next;
		}

		if(current->fromVertex == vert1 && current->toVertex == vert2){
			flag = true;
		}

	}

	return flag;
}

bool Graph::addEdge(int vert1, int vert2, int weight){
	bool success = false;
	int currentEdges = edgeCount;

	//checks if edges between vertices already exist in the graph
	if (exists(vert1) && exists(vert2)){

		int index = findIndex(vert1);
		EdgePair *current = vertexVector->at(index).head;
		//EdgePair **edgeHolder;

		if (current == NULL){
			//prepEdgePair(vert1, vert2, weight, *edgeHolder);
			
			EdgePair *newEdgePair = new EdgePair;
			newEdgePair->fromVertex = vert1;
			newEdgePair->toVertex = vert2;
			newEdgePair->weight = weight;
			newEdgePair->next = NULL;
			newEdgePair->prev = NULL;



			vertexVector->at(index).head = newEdgePair;
			/*
			edgeHolder->next = NULL;
		
			vertexVector->at(findIndex(vert1)).head = *edgeHolder;
			*/
			edgeCount++;
			vertexVector->at(index).numEdges++;
			
			if (edgeCount > currentEdges){
				success = true;

			}
		} else{		

			//will not move to next if vert2 is in list already and if next points to null
			while (current->toVertex != vert2 && current->next){
				current = current->next;
            }

            if (current->toVertex != vert2 && current->next == NULL){
            	//prepEdgePair(vert1, vert2, weight, *edgeHolder);
            	
            	EdgePair *newEdgePair = new EdgePair;
				newEdgePair->fromVertex = vert1;
				newEdgePair->toVertex = vert2;
				newEdgePair->weight = weight;
				newEdgePair->next = NULL;
				

				newEdgePair->prev = current;
				current->next = newEdgePair;

            	//&edgeHolder->prev = current;
            	//current->next = *edgeHolder;

				edgeCount++;
				vertexVector->at(index).numEdges++;

				if (edgeCount > currentEdges){
					success = true;
				}
            }
		}
		success = true;
	}
	return success;
}

bool Graph::removeEdge(int vert1, int vert2){
	bool success = false;
	int currentSize = edgeCount;
	int index = findIndex(vert1);

	EdgePair *current = vertexVector->at(index).head;

	//if there are edges in the linkedlist of the starting vertex
	if(current != NULL){

		//find where the edge you're deleting is in the linked list. goes through list stopping if you find vert1 or before going off end of list
		while(current->toVertex != vert2 && current->next){
			current = current->next;
		}

		cout << "current stopped at edge pair" << current->fromVertex << " to " << current->toVertex << "! " << endl;

		//confirming correct edge to delete was found
		if(current->fromVertex == vert1 && current->toVertex == vert2){

			//removing edge when it's the only one in the adjacency list
			if(current->prev == NULL && current->next == NULL){
				delete(current);
				edgeCount--;
				vertexVector->at(findIndex(vert1)).head = NULL;
			//removing edge from beginning of list
			}else if(current->prev == NULL){
				vertexVector->at(findIndex(vert1)).head = current->next;
				current->next->prev = NULL;
				delete(current);
				edgeCount--;
			//removing edge at the end of list
			}else if(current->next == NULL){
				current->prev->next = NULL;
				delete(current);
				edgeCount--;
			//removing edge from middle of adjacency list
			}else if(current->next != NULL){
				current->prev->next = current->next;
				current->next->prev = current->prev;
				delete(current);
				edgeCount--;
			}
		
			if(edgeCount < currentSize){
				success = true;
				vertexVector->at(index).numEdges--;
			}
		}
	}

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
		vertexCount++;
	}
	return success;
}

bool Graph::removeVertex(int id){
	bool success = false;
	int prevCount = getVertexCount();

	vertexVector->pop_back();

	if (prevCount < getVertexCount()){
		success = true;
	}

	return success;
}

bool Graph::getVertex(int id, Vertex* fillVert){
	bool success = false;
	cout << "entered method" << endl;

	if(exists(id)){

		int index = findIndex(id);
		cout << "id exists in vector" << endl;
		cout << "index is " << index << endl;

		if(vertexVector->at(index).id == id){
			cout << "entered. current id at index is " << vertexVector->at(index).id << "~ id: " << id << endl;
			fillVert->id = vertexVector->at(index).id;
			cout << "fillVert id is " << fillVert->id << endl;
			fillVert->numEdges = vertexVector->at(index).numEdges;
			fillVert->head = vertexVector->at(index).head;
			success = true;
		}

	} else{
		cout << "id not in vector" << endl;
		fillVert->id = -1;
		fillVert->head = NULL;
		fillVert->numEdges = 0;
	}
	//EdgePair *current = vertexVector->at(findIndex(id)).head;


	return success;
}

void Graph::printGraph(){
	cout << "current edge count " << edgeCount << endl;
	
	for (int i = 0; i < vertexVector->size(); i++){
		cout << "vertex " << vertexVector->at(i).id << ": ";

		EdgePair *current = vertexVector->at(i).head;

		if (current == NULL){
			cout << "no edges from this vertex" << endl;
		} else{
			while (current){
				cout << "edge with vertex " << current->toVertex << " (weight: " << current->weight << ")";

				if (current->next != NULL){
                    cout << " -> "; 
                } else{
                    cout << endl;
                }
				current = current->next;
			}
		}

	}
		return;
}
	
bool Graph::exists(int id){
	bool vertFound = false;

	//only check through vector for vertex if id number is valid
	if(id > 0){
		for (int i = 0; i < vertexVector->size(); i++){
			if (vertexVector->at(i).id == id){
				vertFound = true;
			}
		}
	}
	return vertFound;
}

int Graph::findIndex(int id){
	int index;

	for(int i = 0; i < vertexVector->size(); i++){

		if (vertexVector->at(i).id == id){
			index = i;
		}
	}
	return index;
}

/*
void Graph::prepEdgePair(int vert1, int vert2, int weight, EdgePair** edgeHolder){
	EdgePair *newEdgePair = new EdgePair;
	newEdgePair->fromVertex = vert1;
	newEdgePair->toVertex = vert2;
	newEdgePair->weight = weight;
	newEdgePair->next = NULL;
	*edgeHolder = newEdgePair;
}
*/

