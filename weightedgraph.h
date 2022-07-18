/*********************
* Author: Caleb Drake
* Class: COSC 2436 Data Structures
* Program: Weighted Graph
* File: weightedgraph.h
* Purpose: This program creates a full weighted graph with all the necessary getters, setters, and other methods.
*          This is the "weightedgraph.h" file, which contains all of the weightedgraph headers and prototypes.
**********************/
#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H

#include <vector>
#include "linkedlist.h"

using std::vector;

class WeightedGraph {

public:
	// constructor
	WeightedGraph();
	// destructor
	~WeightedGraph();

	bool addVertex(int);
	bool addEdge(int, int, int);
	bool removeEdge(int, int);
	bool removeVertex(int);
	LinkedList* getVertex(int);
	int countEdge();
	int countVertex();
	void printGraph();
	int contains(int);
	bool isEmpty();
	void clearGraph();

private:
	vector<LinkedList*> graph;
	

};

#endif // !WEIGHTEDGRAPH_H
