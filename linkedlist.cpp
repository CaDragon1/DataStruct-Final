/*********************
* Author: Caleb Drake
* Class: COSC 2436 Data Structures
* Program: Weighted Graph
* File: linkedlist.cpp
* Purpose: This program creates a full weighted graph with all the necessary getters, setters, and other methods.
*          This is the "linkedlist.cpp" file, which contains all of the code required to utilize and manipulate a linked list.
*		   The idea is to create a linked list specially tailored to the weighted graph's needs.
*			The first "Vertex" variable is the head, which is a vertex in the weighted graph. The attached vertex variables represent edges for vertices the head is connected to.
**********************/

#include "linkedlist.h"

LinkedList::LinkedList() {
	head = nullptr;
}

LinkedList::~LinkedList() {
	clearList();
}

bool LinkedList::addVertex(int id) {
	bool added = false;
	Vertex* current = head;
	if (!head) {
		head = new Vertex;
		head->id = id;
		head->attached = NULL;
		added = true;
	}
	return added;
}

bool LinkedList::addVertex(int id, int weight) {
	bool added = false;
	Vertex* current = head;
	if (!head) {		// This should never occur; the head vertex should always be created at the same time the vertex is added to the graph and never with a weight.
		added = addVertex(id);	
	}
	else if (id != head->id) {
		while (current->id != id && current->attached) {		// If current's id is ever the same as the id we try to input, the loop will end. The duplicate won't be added.
			current = current->attached;
		}
		if (current->id != id) {								// If the added id isn't a duplicate, add a new vertex as a new edge.
			current->attached = new Vertex;
			current = current->attached;
			current->id = id;
			current->weight = weight;
			current->attached = NULL;
			added = true;
		}
	}
	return added;
}

bool LinkedList::deleteEdge(int id) {		// This function will remove an edge vertex item from the list. It cannot remove the head.
	bool deleted = false;
	Vertex* current = head;
	Vertex* previous;

	if (head && head->id != id) {
		while (current->id != id && current->attached) {		
			previous = current;
			current = current->attached;
		}
		if (current->id == id) {								
			previous->attached = current->attached;
			delete current;
			deleted = true;
		}
	}
	return deleted;
}

int LinkedList::getWeight(int id) {
	int weight = -1;	// -1 means that a weight doesn't exist.
	Vertex* current = head;

	if (head) {
		while (current->id != id && current->attached) {		// If we find the given id in current,
			current = current->attached;
		}
		if (current->id == id) {								// set weight to the weight of the id in relation to the root.
			weight = current->weight;
		}
	}
	return weight;
}

void LinkedList::printList() {
	if (head) {					
		Vertex* current = head->attached;
		std::cout << "  Vertex - id: " << head->id;
		while (current) {
			std::cout << " -> Edge from " << head->id << " to " << current->id << " (weight = " << current->weight << ")";
			current = current->attached;
		}
	}
	else {
		std::cout << "List empty";
	}
	std::cout << std::endl;
}

int LinkedList::getEdgeCount() {
	int edges = 0;
	Vertex* current;
	if (head) {
		current = head->attached;
		while (current) {
			edges++;
			current = current->attached;
		}
	}
	return edges;
}

int LinkedList::getGraphEdgeCount() {
	int edges = 0;
	Vertex* current;
	if (head) {
		current = head->attached;
		while (current) {
			if (current->id > head->id) {	// This ensures that there will be no repeat edges in the overall graph edge count.
				edges++;
			}
			current = current->attached;
		}
	}
	return edges;
}

bool LinkedList::clearList() {
	bool cleared = false;

	if (head) {
		while (head->attached) {
			deleteEdge(head->attached->id);
		}
		cleared = true;
	}
	return cleared;
}

bool LinkedList::fullClearList() {
	bool cleared = false;

	clearList();
	cleared = deleteHeadVertex();
	return cleared;
}

bool LinkedList::exists(int id) {
	bool exists = false;
	Vertex* current = head;
	if (head) {
		while (current && current->id != id) {
			current = current->attached;
		}
		if (current) {
			exists = true;
		}
	}
	return exists;
}

int LinkedList::getHeadID() {
	return head->id;
}

// Private function

bool LinkedList::deleteHeadVertex() {
	bool deleted = false;
	delete head;
	head = NULL;
	deleted = true;
	return deleted;
}