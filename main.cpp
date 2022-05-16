/***************************************************************
* Name: Graziella Buitron
* Coding Final
* Purpose: Create a working bi-directional weighted graph class
***************************************************************/

#include "main.h"

int main(int argc, char** argv){
	srand(time(NULL));

	//creating the test data
	const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    int weights[testdatasize];
    int testValue;
    int randomIndex1;
    int randomIndex2;

    cout << "generating test data to begin testing" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    //generating random vertices
    for (int i = 0; i < testdatasize; i++){
    	ids[i] = rand() % MAXID +1;
    }

    //making known duplicate vertices
    ids[testdatasize-2] = ids[testdatasize-3];
    ids[testdatasize-1] = -1;

    //generating random weights
    for (int i = 0; i < testdatasize; i++){
    	weights[i] = rand() % OFFSET + 1;
    }

    //making dulpicate weight for testing
    weights[testdatasize-2] = weights[testdatasize-3];
    //making negative weight for testing
    weights[testdatasize-1] = -1;

    cout << "test data created. showing test data to begin testing....." << endl;

    //showing the test data. vertices then weights
    cout << testdatasize << " entries of test data..." << endl;
    cout << "test vertices: " << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << "vertex: " << ids[i] << endl;
    }
    cout << endl;

    cout << "test weights for edges:" << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << "weight: " << weights[i] << endl;
    }
    cout << endl;

    //creating the graph
	cout << "creating the graph..." << endl;
	Graph graph;
	cout << "graph created" << endl;
	cout << endl;
	

	//TESTING FUNCTIONS ON EMPTY GRAPH
	cout << "testing functions on empty graph" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	cout << "testing isEmpty... " << endl;
	if(graph.isEmpty()){
		cout << "graph is empty" << endl;
	}else{
		cout << "graph is not empty" << endl;
	}
	cout << endl;

	cout << "testing getVertexCount... " << endl;
	cout << "currently " << graph.getVertexCount() << " vertices in the graph" << endl << endl;

	cout << "testing getEdgeCount... " << endl;
	cout << "currently " << graph.getEdgeCount() << " edges in the graph" << endl << endl;

	cout << "testing hasEdge... " << endl;
	randomIndex1 = rand() % testdatasize;
	randomIndex2 = rand() % testdatasize;
	cout << "checking if edge exists between vertex " << ids[randomIndex1] << " and vertex " << ids[randomIndex2] << endl;
	if(graph.hasEdge(ids[randomIndex1], ids[randomIndex2])){
		cout << "edge exists" << endl;
	} else{
		cout << "edge does not exist" << endl;
	}
	cout << endl;

	cout << "testing removeEdge... " << endl;
	randomIndex1 = rand() % testdatasize;
	randomIndex2 = rand() % testdatasize;
	cout << "removing edge between vertex " << ids[randomIndex1] << " and vertex " << ids[randomIndex2] << endl;
	if(graph.removeEdge(ids[randomIndex1], ids[randomIndex2])){
		cout << "edge removed" << endl;
	} else{
		cout << "edge not removed" << endl;
	}
	cout << endl;




/*

	if(graph.isEmpty()){
		cout << "graph is empty" << endl;
	}else{
		cout << "graph is not empty" << endl;
	}
	cout << endl;
	
*/





/*

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

	

	if (graph.getVertexCount()){
		cout << "count is " << graph.getVertexCount() << " !" << endl;
	} else{
		cout << "graph is empty. vertex count is " << graph.getVertexCount() << endl;
	}

	if(graph.removeVertex(5)){
		cout << "remove successful" << endl;
	}else{
		cout << "remove failed" << endl;
	}
cout << endl;
	cout << "printing current contents... " << endl;
	graph.printGraph();
	cout << endl;

	cout << "testing remove edge... removing edge from vertex 2 to 5" << endl;

	if(graph.removeEdge(2, 5)){
		cout << "remove edge successful" << endl;
	} else{
		cout << "remove edge failed" << endl;
	}
	cout << endl;
	cout << "printing current contents... " << endl;
	graph.printGraph();
	cout << endl;

	if(graph.addEdge(3, 1, 4)){
		cout << "add edge successful" << endl;
	} else{
		cout << "add edge failed" << endl;
	}

	cout << endl;
	cout << "printing current contents... " << endl;
	graph.printGraph();
	cout << endl;

	cout << "testing remove edge... removing edge from vertex 3 to 1" << endl;

	if(graph.removeEdge(3, 1)){
		cout << "remove edge successful" << endl;
	} else{
		cout << "remove edge failed" << endl;
	}
	cout << endl;
	cout << "printing current contents... " << endl;
	graph.printGraph();
	cout << endl;


	cout << "testing hasEdge... seeing if edge exists from vertex 2 to 3" << endl;

	if(graph.hasEdge(2, 3)){
		cout << "graph has edge" << endl;
	} else{
		cout << "graph does not have edge" << endl;
	}

	cout << endl;
	cout << "printing current contents... " << endl;
	graph.printGraph();
	cout << endl;

	cout << "testing hasEdge for edge that does not exist. checking for edge from vertex 5 to 1" << endl;

	if(graph.hasEdge(5, 1)){
		cout << "graph has edge" << endl;
	} else{
		cout << "graph does not have edge" << endl;
	}

	Vertex newVert;
	

	cout << "testing getVertex function" << endl;
	if(graph.getVertex(2, &newVert)){

		cout << "vertex " << newVert.id << " found. vertex ";

		if (newVert.numEdges == 0){
			cout << "has no edges " << endl;

		}else{
			cout << newVert.numEdges << " edges!";
		}
		
	} else{
		cout << "get vertex failed" << endl;
	}
	cout << endl;

	*/

	return 0;
}