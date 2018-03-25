#ifndef GRAPH_H_
#define GRAPH_H_

// includes
#include <iostream>
#include <vector>
#include "Vertex.h"
#include "Edge.h"
//

class Graph {
public:

	Graph() {}
	virtual ~Graph();

	// add a vertex
	virtual bool addVertex(Vertex& v) = 0;

	// BONUS: ADD AN ARRAY OF VERTECIES
	virtual bool addVertices(Vertex* vArray) = 0;

	// remove a vertex, any connected edges are removed
	virtual bool removeVertex(Vertex& v) = 0;

	// add an edge
	virtual bool addEdge(Edge& e) = 0;

	// remove an edge
	virtual bool remove(Edge& e) = 0;

	// returns true if the vertex exists on the graph, false otherwise
	virtual bool searchVertex(const Vertex& v) = 0;

	// returns true if the edge exists on the graph, false otherwise
	virtual bool searchEdge(const Edge& e) = 0;

	// displays the path that contains the vertex
	virtual void display(Vertex& v) const = 0;

	// displays the path that contains the edge
	virtual void display(Edge& e) const = 0;

	// displays the whole graph
	virtual void display() const = 0;

	// converts the graph to a string interpretation
	virtual std::string toString() const = 0;

	// remove all vertices and edges
	virtual bool clean() = 0;


protected:
	std::vector<Vertex> vertices;
	std::vector<Edge> edges;

};



#endif /* GRAPH_H_ */
