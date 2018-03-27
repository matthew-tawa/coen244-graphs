#include "DirectionalCyclicalGraph.h"
using namespace std;

bool DirectionalCyclicalGraph::addVertex(Vertex& v) {
	if (searchVertex(v)) {	// if this vertex already exists on the graph, doesn't make sense to re-add it
		cout << "This vertex already exists on the graph." << endl;
		return false;
	}
	vertices.push_back(v);

	cout << "Vertex successfully added." << endl;

	return true;
}

bool DirectionalCyclicalGraph::removeVertex(Vertex& v) {

	//checks if the vertex is in the graph
	if (!searchVertex(v)) {
		cout << "The input vertex cannot be found in the graph!" << endl;
		return false;
	}

	//removes vertex from  graph vector "vertices"
	for (size_t i = 0; i < vertices.size(); i++) {
		if (v == vertices[i]) {
			for (size_t j = i; j < vertices.size() - 1; j++)
				vertices[j] = vertices[j + 1];
		}
	}

	//filters through the edge classes to delete all edges connected to vertex v
	for (size_t k = 0; k < edges.size(); k++) {
		if (v == *edges[k].getStart() || v == *edges[k].getEnd()) {
			removeEdge(edges[k]);
		}
	}

	//checks to see if vertex still in graph
	if (!searchVertex(v)) {
		cout << "The vertex was succesfully removed!" << endl;
		return true;
	}


	//returns false and outputs to console that vertex was not removed
	cout << "The vertex was not succesfully removed." << endl;
	return false;

}


bool DirectionalCyclicalGraph::addEdge(Edge& e) {
	if (!searchVertex(*e.getStart()) || !searchVertex(*e.getEnd())) {	// making sure that the edge's vertices are on the graph
		cout << "At least one of the edge's vertices was not on the graph." << endl;
		return false;
	}
	if (searchEdge(e)) {	// if this edge already exists on the graph, doesn't make sense to re-add it
		cout << "This edge already exists on the graph." << endl;
		return false;
	}
	edges.push_back(e);	// adding the edge to the graph

	cout << "Edge successfully added." << endl;
	e.getStart()->addOut(e.getID());	// adding the edge id to the arrays in its vertices
	e.getEnd()->addIn(e.getID());

	return true;
}

bool DirectionalCyclicalGraph::removeEdge(Edge& e) {

	//checks if the edge is in the graph
	if (!searchEdge(e)) {
		cout << "The input edge cannot be found in the graph!" << endl;
		return false;
	}


	//removes edge from graph vector "edges"
	for (size_t i = 0; i < edges.size(); i++) {
		if (e == edges[i]) {
			for (size_t j = i; j < edges.size() - 1; j++)
				edges[j] = edges[j + 1];
		}
	}


	//goes to the node at the end of the edge and removes the edge from node's incoming edges
	e.getEnd()->removeIn(e.getID());

	//goes to the node at the start of the edge and removes the edge from node's outgoing edges
	e.getStart()->removeOut(e.getID());


	//checks if edge was succesfully removed
	if (!searchEdge(e)) {
		return true;
	}

	return false;

}

// return true if a given vertex is in the graph, false otherwise
bool DirectionalCyclicalGraph::searchVertex(const Vertex& v) const {
	for (size_t i = 0; i < vertices.size(); i++) {		// iterating through all vertices in the graph
		if (vertices[i] == v) {
			return true;
		}
	}
	return false;
}

// return true if a given edge is in the graph, false otherwise
bool DirectionalCyclicalGraph::searchEdge(const Edge& e) const {
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
	vector<int> queue; // queue for outgoing nodes
	printPath(1,queue);
	return "hello";

}

void DirectionalCyclicalGraph::printPath(int vertexid, vector<int>& queue) const {
	queue.push_back(vertexid);
	const Vertex& vtest = vertices[getVertexPos(vertexid)];
	cout << vtest.getID() << vtest.getOut(0) << endl;
	cout <<"92";	// error in the line above **************************************
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
int DirectionalCyclicalGraph::getVertexPos(int vertexid) const {
	for (size_t i = 0; i < vertices.size(); i++) {
		if (vertices[i].getID() == vertexid) {
			return i;
		}
	}
	return -1;
}

// returns position of an edge in edges array, -1 if not on graph
int DirectionalCyclicalGraph::getEdgePos(int edgeid) const {
	for (size_t i = 0; i < edges.size(); i++) {
		if (edges[i].getID() == edgeid) {
			return i;
		}
	}
	return -1;
}

bool DirectionalCyclicalGraph::clean() {
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


















