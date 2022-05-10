/***************************************************************
* Name: Graziella Buitron
* Coding Final
* Purpose: Create a working bi-directional weighted graph class
***************************************************************/

#include "main.h"

int main(int argc, char** argv){

	cout << "creating the adjacency list" << endl;
	Graph graph;
	cout << "created" << endl;
	
	if(graph.addVertex(5)){
		cout << "vertex added" << endl;
	} else{
		cout << "add vertex failed" << endl;
	}

	cout << "currently " << graph.getVertexCount() << " vertices in graph! " << endl;

	cout << "printing current contents... " << endl;
	graph.printGraph();






	return 0;
}