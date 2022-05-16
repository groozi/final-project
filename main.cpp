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
    int testWeight;
    int randomIndex1;
    int randomIndex2;
    int randomIndex3;
    Vertex newVert;

    cout << "generating test data to begin testing" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

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
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

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
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "creating the graph..." << endl;
	Graph graph;
	cout << "graph created" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	//TESTING FUNCTIONS ON EMPTY GRAPH
	cout << "testing functions on empty graph" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
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

	cout << "testing removeVertex... ";
	randomIndex1 = rand() % testdatasize;
	cout << "removing vertex " << ids[randomIndex1] << "..." << endl;

		if(graph.removeVertex(ids[randomIndex1])){
			cout << "vertex removed" << endl;
		} else{
			cout << "vertex not removed" << endl;
		}
		cout << endl;	
	
	cout << "testing getVertex... ";
	randomIndex1 = rand() % testdatasize;
	cout << "getting vertex " << ids[randomIndex1] << "..." << endl;
	if(graph.getVertex(ids[randomIndex1], &newVert)){
		cout << "vertex found" << endl;

		if (newVert.numEdges != 0){
			cout << ". vertex has " << newVert.numEdges << " adjacent edges";
		}
	} else{
		cout << "vertex not found" << endl;
	}
	cout << endl;

	cout << "printing the current graph... " << endl;
	graph.printGraph();
	cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    //TESTING FUNCTIONS ON FILLED GRAPH
	cout << "adding test data to perform testing on non-empty graph " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "filling the graph with test vertices..." << endl << endl;
	for (int i = 0; i < testdatasize; i++){
		cout << "adding vertex " << ids[i] << " to the graph..." << endl;

		if(graph.addVertex(ids[i])){
			cout << "add successful" << endl;
		}else{
			cout << "add failed" << endl;
		}
		cout << endl;
	}
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "filling the graph with edges...." << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	for (int i = 0; i < testdatasize; i++){
		randomIndex1 = rand() % testdatasize;
		randomIndex2 = rand() % testdatasize;
		testWeight = rand() % testdatasize;
		cout << "adding edge from vertex " << ids[randomIndex1] << " to vertex " << ids[randomIndex2] <<" with weight " << weights[testWeight] << endl;
		if(graph.addEdge(ids[randomIndex1], ids[randomIndex2], weights[testWeight])){
			cout << "edge successfully added" << endl;
		}else{
			cout << "add edge failed" << endl;
		}
		cout << endl;
	}

	cout << "attempting to find and add duplicate...";
	cout << "adding edge from vertex " << ids[randomIndex1] << " to vertex " << ids[randomIndex2] <<" with weight " << weights[testWeight] << endl;
	if(graph.addEdge(ids[randomIndex1], ids[randomIndex2], weights[testWeight])){
		cout << "edge successfully added" << endl;
	}else{
		cout << "add edge failed" << endl;
	}
	cout << endl;

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "printing the current graph... " << endl << endl;
	graph.printGraph();
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	//TESTING FUNCTIONS ON FILLED GRAPH
	cout << "testing functions on filled graph" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
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

	for(int i = 0; i < LOOP; i++){
		randomIndex1 = rand() % testdatasize;
		randomIndex2 = rand() % testdatasize;

		cout << "checking if edge exists between vertex " << ids[randomIndex1] << " and vertex " << ids[randomIndex2] << endl;

		if(graph.hasEdge(ids[randomIndex1], ids[randomIndex2])){
			cout << "edge exists" << endl;
		} else{
			cout << "edge does not exist" << endl;
		}
		cout << endl;
	}
	cout << endl;

	cout << "checking if edge exists between vertex " << ids[randomIndex1] << " and vertex " << ids[randomIndex2] << endl;
	if(graph.hasEdge(ids[randomIndex1], ids[randomIndex2])){
			cout << "edge exists" << endl;
	} else{
		cout << "edge does not exist" << endl;
	}
	cout << endl;

	cout << "testing getVertex function for known vertex... getting vertex " << ids[randomIndex1] << endl;
	EdgePair pointer;

	if(graph.getVertex(ids[randomIndex1], &newVert)){
		if (newVert.numEdges == 0){
			cout << "has no adjacent edges " << endl;

		}else{
			pointer = *newVert.head;
			cout << "vertex has " << newVert.numEdges << " adjacent edges " << endl;
		}
	} else{
		cout << "get vertex failed" << endl;
	}
	cout << endl;

	for (int i = 0; i < LOOP; i++){
		randomIndex1 = rand() % testdatasize;
		cout << "testing getVertex function... getting vertex " << ids[randomIndex1] << endl;

		if(graph.getVertex(ids[randomIndex1], &newVert)){
			if (newVert.numEdges == 0){
				cout << "vertex has no adjacent edges " << endl;
			}else{
				pointer = *newVert.head;
				cout << "vertex has " << newVert.numEdges << " adjacent edges " << endl;
			}
		} else{
			cout << "get vertex failed" << endl;
		}
		cout << endl;
	}

	cout << "testing getVertex function... getting vertex " << ids[randomIndex1] << endl;
	if(graph.getVertex(ids[randomIndex1], &newVert)){
		if (newVert.numEdges == 0){
			cout << "vertex has no adjacent edges " << endl;
		}else{
			pointer = *newVert.head;
			cout << "vertex has " << newVert.numEdges << " adjacent edges " << endl;
		}
	} else{
		cout << "get vertex failed" << endl;
	}
	cout << endl;

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "printing the current graph... " << endl;
	graph.printGraph();
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << endl;
	
	cout << "testing removeVertex... ";

	for(int i = 0; i < testdatasize; i++){
		randomIndex1 = rand() % testdatasize;
		cout << "removing vertex " << ids[randomIndex1] << "..." << endl;

		if(graph.removeVertex(ids[randomIndex1])){
			cout << "vertex removed" << endl;
		} else{
			cout << "vertex not removed" << endl;
		}
		cout << endl;
	}
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "printing the current graph... " << endl;
	graph.printGraph();
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	//clearing the graph
	cout << "clearing the graph" << endl;
	graph.clearGraph();
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "printing the current graph... " << endl;
	graph.printGraph();
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "performing randomized testing..." << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	cout << "testing random methods execution.." << endl << endl;
    int choice = rand() % CHOICES + 1;
    for (int i = 0; i < RANDOM_MULTIPLIER*BUFFERSIZE; i++){

        switch(choice){
            case 1:
            case 2:
                //testing add Vertex
            	cout << "adding vertex " << ids[randomIndex1] << " to the graph..." << endl;
				if(graph.addVertex(ids[randomIndex1])){
					cout << "add successful" << endl;
				} else{
					cout << "add failed" << endl;
				}
                break;

            case 3:
            case 4:
            	//testing remove Vertex
                cout << "removing vertex " << ids[randomIndex1] << "..." << endl;
				if(graph.removeVertex(ids[randomIndex1])){
					cout << "vertex removed" << endl;
				} else{
					cout << "vertex not removed" << endl;
				}
                break;

            case 5:
            	//testing isEmpty
             	cout << "testing isEmpty... " << endl;
				if(graph.isEmpty()){
					cout << "graph is empty" << endl;
				}else{
					cout << "graph is not empty" << endl;
				}
                break;

            case 6:
                //testing getVertexCount and getEdgeCount   
                cout << "testing getVertexCount... " << endl;
				cout << "currently " << graph.getVertexCount() << " vertices in the graph" << endl << endl;

				cout << "testing getEdgeCount... " << endl;
				cout << "currently " << graph.getEdgeCount() << " edges in the graph" << endl;
                break;

            case 7:
            	//testing removeVertex
            	cout << "testing removeVertex... ";
				for(int i = 0; i < LOOP; i++){
					randomIndex1 = rand() % testdatasize;
					cout << "removing vertex " << ids[randomIndex1] << "..." << endl;
					if(graph.removeVertex(ids[randomIndex1])){
						cout << "vertex removed" << endl;
					} else{
						cout << "vertex not removed" << endl;
					}
					cout << endl;
				}
				break;

            case 8:
            	//testing getVertex
            	cout << "testing getVertex function... getting vertex " << ids[randomIndex1] << endl;
				if(graph.getVertex(ids[randomIndex1], &newVert)){
					if (newVert.numEdges == 0){
						cout << "vertex has no adjacent edges " << endl;
					}else{
						pointer = *newVert.head;
						cout << "vertex has " << newVert.numEdges << " adjacent edges " << endl;
					}
				}else{
					cout << "get vertex failed" << endl;
				}
				cout << endl;
				break;

            case 9:
            	//testing hasEdge
            	cout << "testing hasEdge... " << endl;

				for(int i = 0; i < LOOP; i++){
					randomIndex1 = rand() % testdatasize;
					randomIndex2 = rand() % testdatasize;
					cout << "checking if edge exists between vertex " << ids[randomIndex1] << " and vertex " << ids[randomIndex2] << endl;

					if(graph.hasEdge(ids[randomIndex1], ids[randomIndex2])){
						cout << "edge exists" << endl;
					} else{
						cout << "edge does not exist" << endl;
					}
				}
				cout << endl;
				break;

            case 10:
            	//testing addEdge
				cout << "adding edge from vertex " << ids[randomIndex1] << " to vertex " << ids[randomIndex2] <<" with weight " << weights[testWeight] << endl;
				if(graph.addEdge(ids[randomIndex1], ids[randomIndex2], weights[testWeight])){
					cout << "edge successfully added" << endl;
				}else{
					cout << "add edge failed" << endl;
				}
				break;

			case 11:
				//testing print graph
				cout << "printing the current graph... " << endl;
				graph.printGraph();
				break;
        }
                choice = rand() % CHOICES + 1;
                randomIndex1 = rand() % testdatasize;
            	randomIndex2 = rand() % testdatasize;
                cout << endl; 
    }
    //clearing the graph
	cout << "clearing the graph" << endl;
	graph.clearGraph();
		if(graph.isEmpty()){
			cout << "graph is empty" << endl;
		}else{
			cout << "graph is not empty" << endl;
		}
		cout << endl;
		cout << "testing complete" << endl;


			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "filling the graph with test vertices..." << endl << endl;
	for (int i = 0; i < testdatasize; i++){
		cout << "adding vertex " << ids[i] << " to the graph..." << endl;

		if(graph.addVertex(ids[i])){
			cout << "add successful" << endl;
		}else{
			cout << "add failed" << endl;
		}
		cout << endl;
	}
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "filling the graph with edges...." << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	for (int i = 0; i < testdatasize; i++){
		randomIndex1 = rand() % testdatasize;
		randomIndex2 = rand() % testdatasize;
		testWeight = rand() % testdatasize;
		cout << "adding edge from vertex " << ids[randomIndex1] << " to vertex " << ids[randomIndex2] <<" with weight " << weights[testWeight] << endl;
		if(graph.addEdge(ids[randomIndex1], ids[randomIndex2], weights[testWeight])){
			cout << "edge successfully added" << endl;
		}else{
			cout << "add edge failed" << endl;
		}
		cout << endl;
	}

	cout << "printing the current graph... " << endl;
	graph.printGraph();
	graph.bFirst(ids[testdatasize-4]);

	return 0;
}