#include "DirectionalCyclicalGraph.h"
using namespace std;

bool DirectionalCyclicalGraph::addVertex(const Vertex& v) {
	if (searchVertex(v))
	vertices.push_back(v);
	return searchVertex(v);
}

bool DirectionalCyclicalGraph::addVertices(const Vertex* vArray) {

}

bool DirectionalCyclicalGraph::removeVertex(Vertex& v) {

}

bool DirectionalCyclicalGraph::addEdge(const Edge& e) {
	if (!searchVertex(*e.getStart()) || !searchVertex(*e.getEnd())) {	// making sure that the edge's vertices are on the graph
		cout << "At least one of the edge's vertices was not on the graph." << endl;
		return false;
	}
	edges.push_back(e);	// adding the edge to the graph
	e.getStart()->addOut(e.getID());	// adding the edge id to the arrays in its vertices
	e.getEnd()->addIn(e.getID());

	return searchEdge(e);
}

bool DirectionalCyclicalGraph::removeEdge(Edge& e) {

}

// return true if a given vertex is in the graph, false otherwise
bool DirectionalCyclicalGraph::searchVertex(const Vertex& v) {
	for (size_t i = 0; i < vertices.size(); i++) {		// iterating through all vertices in the graph
		if (vertices[i] == v) {
			return true;
		}
	}
	return false;
}

// return true if a given edge is in the graph, false otherwise
bool DirectionalCyclicalGraph::searchEdge(const Edge& e) {
	for (size_t i = 0; i < edges.size(); i++) {
		if (edges[i] == e) {
			return true;
		}
	}
	return false;
}

void DirectionalCyclicalGraph::display(const Vertex& v) const {

}

void DirectionalCyclicalGraph::display(const Edge& e) const {

}

void DirectionalCyclicalGraph::display() const {

}

string DirectionalCyclicalGraph::toString() const {

}

bool DirectionalCyclicalGraph::clean() {

}


















