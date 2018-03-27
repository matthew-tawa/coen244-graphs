#ifndef EDGE_H_
#define EDGE_H_

// includes
#include <iostream>
#include "Vertex.h"
//

class Edge {

public:
	// constructors
	Edge() : weight(0), start(nullptr), end(nullptr) {
		if (lastid == 99999) {
			lastid = 0;
		}
		id = lastid;
		lastid++;
	}
	Edge(int eweight, Vertex* estart, Vertex* eend) : weight(eweight), start(estart), end(eend) {
		if (lastid == 99999) {
			lastid = 0;
		}
		id = lastid;
		lastid++;
	}
	//

	// get functions
	int getID() const;
	int getWeight() const;
	Vertex* getStart() const;
	Vertex* getEnd() const;
	//

	// set functions
	void setWeight(int newweight);
	void setStart(Vertex* newstart);
	void setEnd(Vertex* newend);
	//

	// operators
	bool operator==(const Edge& right) const;
	bool operator!=(const Edge& right) const;
	//

private:
	int id;
	int weight;
	Vertex* start;
	Vertex* end;

	static int lastid;
};




#endif /* EDGE_H_ */
