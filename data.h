/*********************
* Author: Caleb Drake
* Class: COSC 2436 Data Structures
* Program: Weighted Graph
* File: data.h
* Purpose: This program creates a full weighted graph with all the necessary getters, setters, and other methods.
*          This is the "data.h" file, which defines the nodes that will go into the linked list.
**********************/

#ifndef WEIGHTEDGRAPH_DATA_H
#define WEIGHTEDGRAPH_DATA_H


struct Vertex {
	int id;
	int weight;	
	Vertex* attached;			// attached points to the next vertex attached to the head node. We only need to traverse the list forward.
};

#endif /* WEIGHTEDGRAPH_DATA_H */