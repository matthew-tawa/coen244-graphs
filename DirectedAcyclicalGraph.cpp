#include "DirectedAcyclicalGraph.h"
using namespace std;

bool DirectedAcyclicalGraph::addVertex(Vertex& v) {
	if (searchVertex(v)) {	// if this vertex already exists on the graph, doesn't make sense to re-add it
		cout << "This vertex already exists on the graph." << endl;
		return false;
	}
	vertices.push_back(v);

	bool added = searchVertex(v);	// determining whether the vertex was successfully added or not

	cout << ( (added) ? "Vertex successfully added." : "An error occurred, vertex was not added.") << endl;

	return added;
}

bool DirectedAcyclicalGraph::removeVertex(Vertex& v) {
	return false;	// *******************
}

// NEEDS CHANGE: CANT MAKE AN EDGE IS A PATH IS CONTAINING THE START OR END ALREADY **********************
bool DirectedAcyclicalGraph::addEdge(Edge& e) {
	if (!searchVertex(*e.getStart()) || !searchVertex(*e.getEnd())) {	// making sure that the edge's vertices are on the graph
		cout << "At least one of the edge's vertices was not on the graph." << endl;
		return false;
	}

	if (searchEdge(e)) {	// if this edge already exists on the graph, doesn't make sense to re-add it
		cout << "This edge already exists on the graph." << endl;
		return false;
	}



	edges.push_back(e);	// adding the edge to the graph

	bool added = searchEdge(e);	// determining whether the edge was successfully added or not

	if (added) {
		cout << "Edge successfully added." << endl;
		e.getStart()->addOut(e.getID());	// adding the edge id to the arrays in its vertices
		e.getEnd()->addIn(e.getID());
	} else {
		cout << "An error occurred, edge was not added." << endl;
	}

	return searchEdge(e);
}

bool DirectedAcyclicalGraph::removeEdge(Edge& e) {
	return false; // ********************************
}

// return true if a given vertex is in the graph, false otherwise
bool DirectedAcyclicalGraph::searchVertex(const Vertex& v) const {
	for (size_t i = 0; i < vertices.size(); i++) {		// iterating through all vertices in the graph
		if (vertices[i] == v) {
			return true;
		}
	}
	return false;
}

// return true if a given edge is in the graph, false otherwise
bool DirectedAcyclicalGraph::searchEdge(const Edge& e) const {
	for (size_t i = 0; i < edges.size(); i++) {
		if (edges[i] == e) {
			return true;
		}
	}
	return false;
}

void DirectedAcyclicalGraph::display(const Vertex& v) const {

}

void DirectedAcyclicalGraph::display(const Edge& e) const {

}

void DirectedAcyclicalGraph::display() const {

}

string DirectedAcyclicalGraph::toString() const {
	vector<int> queue = {};
	printPath(1,queue);
	return "test";
}

bool DirectedAcyclicalGraph::clean() {
	for (size_t i = 0; i < vertices.size(); i++) {	// loop removes every vertex
		removeVertex(vertices[i]);
	}
	// since removing a vertex removes all edges associated with that vertex,
	// there is no need to remove edges, since they will be automatically re-
	// moved when one of its vertices is removed.

	if (vertices.size() != 0 || edges.size() != 0) {	// if there is at least one edge or vertex, graph was not properly cleaned
		cout << "Unsuccessful in cleaning graph." << endl;
		return false;
	}

	cout << "Graph was cleaned successfully." << endl;
	return true;
}

void DirectedAcyclicalGraph::printPath(int vertexid, vector<int> queue) const {
	queue.push_back(vertexid);
	cout << vertices[getVertexPos(vertexid)].getOutSize() << endl;

	if (vertices[getVertexPos(vertexid)].getOutSize() > 0) {	// if a node has an outgoing edge
		for (int i = 0; i < vertices[getVertexPos(vertexid)].getOutSize(); i++) {
			// if a vertex has outgoing edges, push into the queue its neighboring node
			queue.push_back(edges[getEdgePos(vertices[getVertexPos(vertexid)].getOut(i))].getEnd()->getID());
			printPath(queue.back(),queue);	// recursively calling this function with the outgoing node
		}
	} else  {	// if a node has no outgoing edges, we have reached a dead end, and we can print
		for (size_t i = 0; i < queue.size() - 1; i++) {
			cout << queue[i] << "-";
		}
		cout << queue.back() << "; ";
	}
}

// returns position of a vertex in vertices array, -1 if not on graph
int DirectedAcyclicalGraph::getVertexPos(int vertexid) const {
	for (size_t i = 0; i < vertices.size(); i++) {
		if (vertices[i].getID() == vertexid) {
			return i;
		}
	}
	return -1;
}

// returns position of an edge in edges array, -1 if not on graph
int DirectedAcyclicalGraph::getEdgePos(int edgeid) const {
	for (size_t i = 0; i < edges.size(); i++) {
		if (edges[i].getID() == edgeid) {
			return i;
		}
	}
	return -1;
}
























