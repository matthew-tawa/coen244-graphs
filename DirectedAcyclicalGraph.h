#ifndef DIRECTEDACYCLICALGRAPH_H_
#define DIRECTEDACYCLICALGRAPH_H_

// includes
#include <iostream>
#include "Graph.h"
//

class DirectedAcyclicalGraph : public Graph {

public:
	// constructors
	DirectedAcyclicalGraph() {}
	~DirectedAcyclicalGraph() {}
	//

	// adding/removing elements
	bool addVertex(Vertex& v);
	bool removeVertex(Vertex& v);
	bool addEdge(Edge& e);
	bool removeEdge(Edge& e);
	//

	// searching
	bool searchVertex(const Vertex& v) const;
	bool searchEdge(const Edge& e) const;
	//

	// display
	void display(const Vertex& v) const;
	void display(const Edge& e) const;
	void display() const;
	std::string toString() const;
	bool clean();
	//

private:
	void printPath(int vertexid, std::vector<int> queue) const;
	int getVertexPos(int vertexid) const;
	int getEdgePos(int edgeid) const;
};



#endif /* DIRECTEDACYCLICALGRAPH_H_ */
