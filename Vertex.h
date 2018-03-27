#ifndef VERTEX_H_
#define VERTEX_H_

// includes
#include <iostream>
#include <vector>
//

class Vertex {

public:
	// constructors
	Vertex() : val(0) {		// default constructor
		if (lastid == 99999) {
			lastid = 0;
		}
		id = lastid;
		lastid++;
	}
	Vertex(int value) : val(value) {	// constructor with vertex value
		if (lastid == 99999) {
			lastid = 0;
		}
		id = lastid;
		lastid++;
	}
	Vertex(const Vertex& v) : id(v.id), val(v.val), out(v.out), in(v.in) {}
	//

	// get functions
	int getID() const;
	int getVal() const;
	int getIn(int pos) const;
	int getOut(int pos) const;
	int getInSize() const;
	int getOutSize() const;
	//

	// set functions
	void setVal(int value);
	//

	// misc.
	void addIn(int newin);
	void addOut(int newout);
	void removeIn(int removein);
	void removeOut(int removeout);
	//

	// operators
	bool operator==(const Vertex& right) const;
	bool operator!=(const Vertex& right) const;
	//



private:
	static int lastid;	// used to create unique vertex ids
	int id;		// a vertexes unique id
	int val;	// a vertexes value

	std::vector<int> out;		// array of id numbers of outgoing edges
	std::vector<int> in;		// array of id numbers of incoming edges

};

#endif /* VERTEX_H_ */
