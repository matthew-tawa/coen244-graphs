#include "Vertex.h"
using namespace std;

int Vertex::lastid = 0;

int Vertex::getID() const {
	return id;
}

int Vertex::getVal() const {
	return val;
}

void Vertex::setVal(int value) {
	val = value;
}

void Vertex::addIn(int newin) {
	for (size_t i = 0; i < in.size(); i++) {
		if (newin < in[i]) {	// checking for the correct place to put the new id so that they remain in increasing order
			vector<int>::iterator it;
			it = in.begin() + i;	// creating a vector iterator at the correct location
			in.insert(it,newin,1);	// inserting the new id
			return;
		}
	}
}

void Vertex::addOut(int newout) {
	for (size_t i = 0; i < out.size(); i++) {	// iterating through the outogin edges
		if (newout < out[i]) {	// checking for the correct place to put the new id so that they remain in increasing order
			vector<int>::iterator it;
			it = out.begin() + i;	// creating a vector iterator at the correct location
			out.insert(it,newout,1);	// inserting the new id
			return;
		}
	}
}

void Vertex::removeIn(int removein) {
	for (size_t i = 0; i < in.size(); i++) {	// iterating through the incoming edges
		if (in[i] == removein) {	// if an incoming edge has the same id, we remove it by shifting everything after to the left, keeping increasing order
			for (size_t j = i; i < in.size(); j++) {
				in[j] = in[j+1];
			}
		return;
		}
	}
}

void Vertex::removeOut(int removeout) {
	for (size_t i = 0; i < out.size(); i++) {	// iterating through the outgoing edges
		if (out[i] == removeout) {	// if an outgoing edge has the same id, we remove it by shifting everything after to the left, keeping increasing order
			for (size_t j = i; i < out.size(); j++) {
				out[j] = out[j+1];
			}
		return;
		}
	}
}

bool Vertex::operator==(const Vertex& v) {
	if (val == v.val) {	// if they have the same value, continue
		if (out.size() == v.out.size()) {	// if they have the same number of outgoing edges, continue
			if (in.size() == v.in.size()) {	// if they have the same number of incoming edges, continue

				for (size_t i = 0; i < out.size(); i++) {
					if (out[i] != v.out[i]) {	// since the 'out' array is ordered, if two positions are not the same, the vertices are not the same
						return false;
					}
				}

				for (size_t i = 0; i < in.size(); i++) {
					if (in[i] != v.in[i]) {	// since the 'in' array is ordered, if the positions are not the same, the vertices are not the same
						return false;
					}
				}

				return true;
			}
		}
	}
	return false;
}

bool Vertex::operator!=(const Vertex& v) {
	return !(*this == v);
}




