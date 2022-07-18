/*********************
* Author: Caleb Drake
* Class: COSC 2436 Data Structures
* Program: Weighted Graph
* File: linkedlist.h
* Purpose:  This program creates a full weighted graph with all the necessary getters, setters, and other methods.
*           This is the "linkedlist.h" file, which contains all of the linkedlist headers and prototypes.
*		    The idea is to create a linked list specially tailored to the weighted graph's needs.
*			The first "Vertex" variable is the head, which is a vertex in the weighted graph. The attached vertex variables represent edges for vertices the head is connected to.
**********************/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Includes data.h
#include "data.h"
#include <iostream>

class LinkedList {

public:
	// Constructor
	LinkedList();
	// Destructor
	~LinkedList();

	bool addVertex(int);		// This addVertex is used to add a head vertex to the list. If there is already a head, it fails. This should only run once.
	bool addVertex(int, int);	// OVERRIDDEN ADDVERTEX: int 1 - id    int 2 - weight		Adds a vertex representing an edge between the head vertex and a given vertex.
	bool deleteEdge(int);		// int - id		Removes a vertex representing an edge.
	int getWeight(int);			// Returns the weight of the vertex with the given id int if it exists.
	void printList();			// Display function: prints out the list
	int getEdgeCount();			// This method returns the amount of elements in the list minus the head vertex. Each vertex in the list beyond the head
								// represents an edge between the two vertices.
	int getGraphEdgeCount();	// This method returns how many edges with an id greater than the head's id connect to the head vertex. 
								// Used when calculating how many total edges there are in the graph.
	bool clearList();			// Clears the list
	bool fullClearList();		// Clears the list, including the head node
	bool exists(int);			// Checks to see if the given id is found attached to the head node.
	int getHeadID();			// Returns the id of the vertex

private:
	Vertex* head;	// The head of the entire list, a pointer to a Vertex object. The other vertex objects in the list just show the relationship
					// between the head node and each other vertex with an edge connecting the two.
	bool deleteHeadVertex();	// This deletes the head vertex privately
};

#endif // !LINKEDLIST_H