#ifndef DIRECTIONALCYCLICALGRAPH_H_
#define DIRECTIONALCYCLICALGRAPH_H_

// includes
#include "Graph.h"
//

class DirectionalCyclicalGraph : public Graph {
public:
	// constructors
	DirectionalCyclicalGraph() {}
	~DirectionalCyclicalGraph() {}
	//

	// add a vertex
	bool addVertex(Vertex& v);

	// remove a vertex, any connected edges are removed
	bool removeVertex(Vertex& v);

	// add an edge
	bool addEdge(Edge& e);

	// remove an edge
	bool removeEdge(Edge& e);

	// returns true if the vertex exists on the graph, false otherwise
	bool searchVertex(const Vertex& v) const;

	// returns true if the edge exists on the graph, false otherwise
	bool searchEdge(const Edge& e) const;

	// displays the path that contains the vertex
	void display(const Vertex& v) const;

	// displays the path that contains the edge
	void display(const Edge& e) const;

	// displays the whole graph
	void display() const;

	// converts the graph to a string interpretation
	std::string toString() const;

	// remove all vertices and edges
	bool clean();

private:
	void printPath(int vertexid, std::vector<int>& queue) const;
	int getVertexPos(int vertexid) const;
	int getEdgePos(int edgeid) const;

};



#endif /* DIRECTIONALCYCLICALGRAPH_H_ */
