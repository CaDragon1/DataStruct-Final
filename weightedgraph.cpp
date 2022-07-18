/*********************
* Author: Caleb Drake
* Class: COSC 2436 Data Structures
* Program: Weighted Graph
* File: weightedgraph.cpp
* Purpose: This program creates a full weighted graph with all the necessary getters, setters, and other methods.
*          This is the "weightedgraph.cpp" file, which contains all of the methods and code for creating, traversing, adding, removing, deleting, and manipulating the graph.
**********************/
#include "weightedgraph.h"

// constructor
WeightedGraph::WeightedGraph() {

}
// destructor
WeightedGraph::~WeightedGraph() {
	clearGraph();
}

bool WeightedGraph::addVertex(int id) {
	bool added = false;
	if (contains(id) == -1) {
		LinkedList* newVertex = new LinkedList;		// Create a new linkedlist and add it to the vector
		newVertex->addVertex(id);
		graph.push_back(newVertex);
		added = true;
	}
	return added;
}

bool WeightedGraph::addEdge(int vertex1, int vertex2, int weight) {
	// Check both vertices to make sure they exist
	int v1at = contains(vertex1);
	int v2at = contains(vertex2);
	bool added = false;

	if (v1at > -1 && v2at > -1 && weight > 0) {
		added = graph.at(v1at)->addVertex(vertex2, weight);
		graph.at(v2at)->addVertex(vertex1, weight);
	}

	return added;
}

bool WeightedGraph::removeEdge(int vertex1, int vertex2) {
	int v1at = contains(vertex1);
	int v2at = contains(vertex2);
	bool removed = false;

	if (v1at > -1 && v2at > -1) {
		removed = graph.at(v1at)->deleteEdge(vertex2);
		graph.at(v2at)->deleteEdge(vertex1);
	}
	return removed;
}

bool WeightedGraph::removeVertex(int id) {
	bool removed = false;
	int at = contains(id);

	if (at > -1) {
		for (int i = 0; i < graph.size(); ++i){
			if (i != at) {	// We will call fullClearList later on the removed vertex
				removeEdge(id, graph.at(i)->getHeadID());
			}
		}
		removed = graph.at(at)->fullClearList();
		graph.erase(graph.begin()+at);
	}
	return removed;
}

LinkedList* WeightedGraph::getVertex(int id) {
	int at = contains(id);
	LinkedList* gottenVertex = NULL;
	if (at > -1) {
		gottenVertex = graph.at(at);
	}
	return gottenVertex;
}

int WeightedGraph::countEdge() {
	int edgeCount = 0;
	for (int i = 0; i < graph.size(); ++i) {
		edgeCount += graph.at(i)->getGraphEdgeCount();
	}
	return edgeCount;
}

int WeightedGraph::countVertex() {
	return graph.size();
}

void WeightedGraph::printGraph() {
	for (int i = 0; i < graph.size(); ++i) {
		graph.at(i)->printList();
	}
}

int WeightedGraph::contains(int id) {
	int contains = -1;						// -1 means the vector doesn't contain the id
	for (int i = 0; i < graph.size(); ++i) {
		if (graph.at(i)->getHeadID() == id) {
			contains = i;
		}
	}
	return contains;
}

bool WeightedGraph::isEmpty() {
	return graph.empty();
}

void WeightedGraph::clearGraph() {
	for (int i = 0; i < graph.size(); ++i) {
		graph.at(i)->fullClearList();
	}
	graph.clear();
}