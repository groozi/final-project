/***************************************************************
* Name: Graziella Buitron
* Coding Final
* Purpose: Create a working bi-directional weighted graph class
***************************************************************/

#include "graph.h"

Graph::Graph(){
	vertexVector = new vector<Vertex>;
	vertexCount = 0;
	edgeCount = 0;
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
	bool flag = true;

	if(vertexVector->size() > 0){
		flag = false;
	}

	return flag;
}

int Graph::getVertexCount(){
	//vertexCount = vertexVector->size();
	return vertexVector->size();
	//return vertexCount;
}

int Graph::getEdgeCount(){
	return edgeCount;
}


bool Graph::hasEdge(int vert1, int vert2){
	bool flag;

	if(exists(vert1) && exists(vert2)){
		EdgePair *current = vertexVector->at(findIndex(vert1)).head;

		if(current == NULL){
			flag = false;
		}else{
			if(current->toVertex == vert2){
				flag = true;
			}else{
				while(current->toVertex != vert2 && current->next){
					current = current->next;
				}
				if(current->toVertex == vert2){
					flag = true;
				}else{ 
					flag = false;
				}
			}
		}
	}
	return flag;
}

bool Graph::addEdge(int vert1, int vert2, int weight){
	bool success = false;
	bool enter = false;
	int currentEdges = edgeCount;

	if(exists(vert1) && exists(vert2)){
		if(weight > 0){
			enter = true;
		}
	}

	//checks if vertices shared by edge already exist in the graph
	if (enter){

		int index = findIndex(vert1);
		EdgePair *current = vertexVector->at(index).head;
		//EdgePair **edgeHolder;

		//if no edges exist in vert1's adjacency list
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

            //makes sure edge with vertex doesn't already exists and adding to end of adjacency list
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
		//success = true;
	}
	return success;
}

bool Graph::removeEdge(int vert1, int vert2){
	bool success = false;
	bool enter = true;
	int currentSize = edgeCount;
	int index;
	EdgePair *current = NULL;

	if (isEmpty()){
		enter = false;
	}else{
		//creating needed variables for function only if we can actually call the function(vertices exist in graph)
		index = findIndex(vert1);
		current = vertexVector->at(index).head;
	}

	//if there are edges in the linkedlist of the starting vertex
	if(enter && current != NULL){

		//find where the edge you're deleting is in the linked list. goes through list stopping if you find vert1 or before going off end of list
		while(current->toVertex != vert2 && current->next){
			current = current->next;
		}

		//cout << "current stopped at edge pair" << current->fromVertex << " to " << current->toVertex << "! " << endl;

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

	if(id > 0 && !exists(id)){
		Vertex *newVertex = new Vertex;
		newVertex->head = NULL;
		newVertex->numEdges = 0;
		newVertex->id = id;
		vertexVector->push_back(*newVertex);
		//delete(newVertex);

		if(currentSize < vertexVector->size()){
			success = true;
			vertexCount++;
		}
	}
	return success;
}

bool Graph::removeVertex(int id){
	bool success = false;

	//only performs remove vertex process if vector is not empty and id exists in the vector
	if(!isEmpty() && exists(id)){
		int prevCount = vertexVector->size();
		//finding vertex in the vector to delete
		vertexVector->erase(vertexVector->begin() + findIndex(id));

		if (vertexVector->size() < prevCount){
			success = true;
			vertexCount--;
		}
	}
	return success;
}

bool Graph::getVertex(int id, Vertex* fillVert){
	bool success = false;
	//cout << "entered method" << endl;

	if(!isEmpty() && exists(id)){

		int index = findIndex(id);
		//cout << "id exists in vector" << endl;
		//cout << "index is " << index << endl;

		if(vertexVector->at(index).id == id){
			//cout << "entered. current id at index is " << vertexVector->at(index).id << "~ id: " << id << endl;
			fillVert->id = vertexVector->at(index).id;
			//cout << "fillVert id is " << fillVert->id << endl;
			fillVert->numEdges = vertexVector->at(index).numEdges;
			fillVert->head = vertexVector->at(index).head;
			success = true;
		}

	} else{
		//cout << "id not in vector" << endl;
		fillVert->id = -1;
		fillVert->head = NULL;
		fillVert->numEdges = 0;
	}
	//EdgePair *current = vertexVector->at(findIndex(id)).head;


	return success;
}

void Graph::printGraph(){

	if (vertexVector->size() > 0){

		cout << "current vertex count: " << vertexCount << " current edge count: " << edgeCount << endl;

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

	} else{
		cout << "graph is empty" << endl;
		
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
	int index = -1;

	if(!isEmpty()){
		for(int i = 0; i < vertexVector->size(); i++){

			if (vertexVector->at(i).id == id){
				index = i;
			}
		}
	}

	return index;
}

void Graph::bFirst(int id){
	//created a vector of booleans to mark if nodes have been visited. initalized all to false
	vector<bool> visted (vertexVector->size(), false);

	//creating a queue to implement breadth first traversal (fifo)
	queue<int> traversalQueue;

	//mark current node as visited and enqueue it 
	//visited[]


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

