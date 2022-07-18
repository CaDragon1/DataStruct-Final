/*********************
* Author: Caleb Drake
* Class: COSC 2436 Data Structures
* Program: Weighted Graph
* File: main.cpp
* Purpose: This program creates a full weighted graph with all the necessary getters, setters, and other methods.
*          This is the "main.cpp" file, which contains all of the test code for the weighted graph.
**********************/

#include "main.h"

int main(int argc, char** argv) {
	
	int testIDs[TESTLISTLENGTH] = {2, 5, 1, 30, 3, -1, 4, 6};
	int testWeights[TESTLISTLENGTH] = { 11, 14, 23, 9, 45, 17, 32, 29 };

	// FIRST I test that the linkedlist file works correctly. If it doesn't work, neither will the weighted graph.
	cout << " ----- LINKEDLIST TESTING ----- " << endl;
	cout << "Initializing linked list 'testList'... ";
	LinkedList* testList = new LinkedList;
	if (testList) {
		cout << "Done." << endl;
	}
	else {
		cout << "Failed initialization." << endl;
	}

	// Empty list testing
	cout << "\nTesting list attributes for empty list" << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << "Printing empty list: ";
	testList->printList();
	cout << "Edges: " << testList->getEdgeCount() << "   '5' exists: " << testList->exists(5) << "   getWeight of '5': " << testList->getWeight(5) << endl;
	cout << "Testing getGraphEdgeCount: " << testList->getGraphEdgeCount() << "   Deleting nonexistant '5' edge: " << testList->deleteEdge(5) << endl;
	cout << "Clearing edges of empty list: " << testList->clearList() << "   Clearing entire list: " << testList->fullClearList() << endl << endl;

	// Adding elements to the list for testing
	cout << "Adding single vertex node of id 3 as the head of the list: " << testList->addVertex(3) << endl << endl;

	// Testing single-element list
	cout << "Testing list attributes for head-only list" << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << "Printing list: ";
	testList->printList();
	cout << "Edges: " << testList->getEdgeCount() << endl;
	cout << "'3' exists: " << testList->exists(3) << endl;
	cout << "'5' exists: " << testList->exists(5) << endl;
	cout << "getWeight of '3': " << testList->getWeight(3) << endl;
	cout << "getWeight of '5': " << testList->getWeight(5) << endl;
	cout << "Testing getGraphEdgeCount: " << testList->getGraphEdgeCount() << endl;
	cout << "Deleting '3' edge (should fail): " << testList->deleteEdge(3) << endl;
	cout << "Clearing edges of head-only list: " << testList->clearList() << endl;
	cout << "Printing edgeless list: ";
	testList->printList();
	cout << "Clearing entire list: " << testList->fullClearList() << endl;
	cout << "Printing empty list: ";
	testList->printList();

	// Adding elements to create a full list for testing
	cout << "\nAdding head: " << testList->addVertex(testIDs[0]) << endl;
	for (int i = 1; i < TESTLISTLENGTH; i++) {
		cout << "adding " << testIDs[i] << "... " << testList->addVertex(testIDs[i], testWeights[i]) << endl;		
	}
	cout << "Printing list: ";
	testList->printList();

	// Testing list with multiple elements
	cout << "\nTesting list attributes for list with multiple elements" << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << "Printing list: ";
	testList->printList();
	cout << "\nAdding duplicate edge '" << testIDs[1] << "': " << testList->addVertex(testIDs[1], testWeights[1]) << endl;
	cout << "Adding duplicate head '" << testIDs[0] << "': " << testList->addVertex(testIDs[0], testWeights[0]) << endl;
	cout << "Edges: " << testList->getEdgeCount() << endl;
	cout << "'" << testIDs[7] << "' exists: " << testList->exists(testIDs[7]) << endl;
	cout << "'12345' exists: " << testList->exists(12345) << endl;
	cout << "getWeight of '" << testIDs[7] << "': " << testList->getWeight(testIDs[7]) << endl;
	cout << "getWeight of '12345': " << testList->getWeight(12345) << endl;
	cout << "getWeight of ''" << testIDs[5] << "': " << testList->getWeight(testIDs[5]) << endl;
	cout << "Testing getGraphEdgeCount: " << testList->getGraphEdgeCount() << endl;
	cout << "Deleting '" << testIDs[4] << "' edge: " << testList->deleteEdge(testIDs[4]) << endl;
	cout << "Duplicate delete '" << testIDs[4] << "' edge (should fail): " << testList->deleteEdge(testIDs[4]) << endl;
	cout << "Printing list: ";
	testList->printList();
	cout << "Clearing edges of list: " << testList->clearList() << endl;
	cout << "Printing edgeless list: ";
	testList->printList();
	cout << "Clearing entire list: " << testList->fullClearList() << endl;
	cout << "Printing empty list: ";
	testList->printList();

	cout << endl;

	// TESTING WEIGHTED GRAPH
	cout << " ----- WEIGHTED GRAPH TESTING ----- " << endl;
	cout << "Initializing weighted graph 'graph'... ";
	WeightedGraph* graph = new WeightedGraph;
	if (graph) {
		cout << "Done." << endl;
	}
	else {
		cout << "Failed initialization." << endl;
	}

	// Testing empty graph
	cout << "\nTesting weightedGraph methods for empty graph" << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << "isEmpty: " << graph->isEmpty() << endl;
	cout << "Number of edges: " << graph->countEdge() << endl;
	cout << "Number of vertices: " << graph->countVertex() << endl;
	cout << "Contains '4' at location " << graph->contains(4) << "   (-1 means doesn't exist)" << endl;
	cout << "Printing graph:" << endl;
	graph->printGraph();
	cout << "Removing nonexistent vertex '1': " << graph->removeVertex(1) << endl;
	cout << "Removing nonexistent edge between '1' and '3': " << graph->removeEdge(1, 3) << endl;
	cout << "Getting nonexistent vertex '1': ";
	LinkedList* vertexGet = graph->getVertex(1);
	if (vertexGet) {
		cout << "Success" << endl;
	}
	else {
		cout << "Failure" << endl;
	}

	// Adding element to empty graph for single-vertex testing
	cout << "\nAdding vertex " << testIDs[0] << " to graph: " << graph->addVertex(testIDs[0]) << endl;
	cout << "Adding duplicate vertex " << testIDs[0] << " to graph: " << graph->addVertex(testIDs[0]) << endl;
	cout << "Printing graph:" << endl;
	graph->printGraph();
	cout << "isEmpty: " << graph->isEmpty() << endl;
	cout << "Number of edges: " << graph->countEdge() << endl;
	cout << "Number of vertices: " << graph->countVertex() << endl;
	cout << "Contains '4' at location " << graph->contains(4) << "   (-1 means doesn't exist)" << endl;
	cout << "Contains '" << testIDs[0] << "' at location " << graph->contains(testIDs[0]) << "   (-1 means doesn't exist)" << endl;
	cout << "Removing nonexistent vertex '1': " << graph->removeVertex(1) << endl;
	cout << "Removing nonexistent edge between '1' and '3': " << graph->removeEdge(1, 3) << endl;
	cout << "Getting nonexistent vertex '1': ";
	vertexGet = graph->getVertex(1);
	if (vertexGet) {
		cout << "Success" << endl;
	}
	else {
		cout << "Failure" << endl;
	}
	cout << "Removing vertex " << testIDs[0] << ": " << graph->removeVertex(testIDs[0]) << endl;
	cout << "Printing graph:" << endl;
	graph->printGraph();

	// Fully filling out graph
	cout << "\nFilling out graph with multiple elements" << endl;
	for (int i = 0; i < TESTLISTLENGTH; i++) {
		cout << "Adding vertex " << testIDs[i] << ": " << graph->addVertex(testIDs[i]) << endl;
	}
	cout << "\nPopulating vertices with edges" << endl;
	cout << "Adding edge from " << testIDs[0] << " to " << testIDs[1] << " (weight 11): " << graph->addEdge(testIDs[0], testIDs[1], 11) << endl;
	cout << "Adding edge from " << testIDs[0] << " to " << testIDs[2] << " (weight 14): " << graph->addEdge(testIDs[0], testIDs[2], 14) << endl;
	cout << "Adding edge from " << testIDs[0] << " to " << testIDs[3] << " (weight 9): " << graph->addEdge(testIDs[0], testIDs[3], 9) << endl;
	cout << "Adding edge from " << testIDs[1] << " to " << testIDs[2] << " (weight 23): " << graph->addEdge(testIDs[1], testIDs[2], 23) << endl;
	cout << "Adding edge from " << testIDs[2] << " to " << testIDs[3] << " (weight 45): " << graph->addEdge(testIDs[2], testIDs[3], 45) << endl;
	cout << "Adding edge from " << testIDs[2] << " to " << testIDs[7] << " (weight 17): " << graph->addEdge(testIDs[2], testIDs[7], 17) << endl;
	cout << "Adding edge from " << testIDs[3] << " to " << testIDs[4] << " (weight 7): " << graph->addEdge(testIDs[3], testIDs[4], 7) << endl;
	cout << "Adding edge from " << testIDs[4] << " to " << testIDs[5] << " (weight 32): " << graph->addEdge(testIDs[4], testIDs[5], 32) << endl;
	cout << "Adding edge from " << testIDs[4] << " to " << testIDs[7] << " (weight 14): " << graph->addEdge(testIDs[4], testIDs[7], 14) << endl;
	cout << "Adding edge from " << testIDs[5] << " to " << testIDs[6] << " (weight 29): " << graph->addEdge(testIDs[5], testIDs[6], 29) << endl;
	cout << endl;

	cout << "Testing weighted graph methods with populated graph" << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << "Adding duplicate edge from " << testIDs[0] << " to " << testIDs[1] << " (weight 11): " << graph->addEdge(testIDs[0], testIDs[1], 11) << endl;
	cout << "Adding impossible edge from " << testIDs[0] << " to 12345: " << graph->addEdge(testIDs[0], 12345, 1) << endl;
	cout << "Adding impossible negative weight to new edge from " << testIDs[5] << " to " << testIDs[0] << " (weight -5): " << graph->addEdge(testIDs[5], testIDs[0], -5) << endl << endl;	
		// Negative weights are impossible in this graph (for possible implementation of Dijkstra's algorithm)
	graph->printGraph();
	cout << "\nisEmpty: " << graph->isEmpty() << endl;
	cout << "Number of edges: " << graph->countEdge() << endl;
	cout << "Number of vertices: " << graph->countVertex() << endl;
	cout << "Removing edge between " << testIDs[2] << " and " << testIDs[3] << ": " << graph->removeEdge(testIDs[2], testIDs[3]) << endl;
	cout << "Vertex " << testIDs[2] << " and edges: ";
	graph->getVertex(testIDs[2])->printList();
	cout << "Vertex " << testIDs[3] << " and edges: ";
	graph->getVertex(testIDs[3])->printList();
	
	cout << "\nCLEARING GRAPH" << endl;
	graph->clearGraph();
	graph->printGraph();

	return 0;
}