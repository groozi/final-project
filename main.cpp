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
	
	if(graph.addVertex(1)){
		cout << "vertex added" << endl;
	} else{
		cout << "add vertex failed" << endl;
	}
	cout << "currently " << graph.getVertexCount() << " vertices in graph! " << endl;

	if(graph.addVertex(2)){
		cout << "vertex added" << endl;
	} else{
		cout << "add vertex failed" << endl;
	}

	cout << "currently " << graph.getVertexCount() << " vertices in graph! " << endl;

	if(graph.addVertex(3)){
		cout << "vertex added" << endl;
	} else{
		cout << "add vertex failed" << endl;
	}

	if(graph.addVertex(4)){
		cout << "vertex added" << endl;
	} else{
		cout << "add vertex failed" << endl;
	}
	if(graph.addVertex(5)){
		cout << "vertex added" << endl;
	} else{
		cout << "add vertex failed" << endl;
	}

	cout << "currently " << graph.getVertexCount() << " vertices in graph! " << endl;

	cout << "printing current contents... " << endl;
	graph.printGraph();
	cout << endl;

	if(graph.exists(5)){
		cout << "vertex 5 exists" << endl;
	} else{
		cout << "vertex 5 does not exist" << endl;
	}

	cout << endl;
	cout << "testing addEdge method" << endl;

	cout << "adding edge from vertex 2 to 5 with weight 6" << endl;

	if(graph.addEdge(2, 5, 6)){
		cout << "add edge successful" << endl;
	} else{
		cout << "add edge failed" << endl;
	}

	cout << "printing current contents... " << endl;
	graph.printGraph();
	cout << endl;

/*
	if(graph.addEdge(2, 1, 4)){
		cout << "add edge successful" << endl;
	} else{
		cout << "add edge failed" << endl;
	}

	if(graph.addEdge(2, 3, 1)){
		cout << "add edge successful" << endl;
	} else{
		cout << "add edge failed" << endl;
	}

	cout << "printing current contents... " << endl;
	graph.printGraph();
	cout << endl;

*/



	return 0;
}