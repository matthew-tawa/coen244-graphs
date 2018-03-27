#include "Vertex.h"
using namespace std;

int Vertex::lastid = 0;

int Vertex::getID() const {
	return id;
}

int Vertex::getVal() const {
	return val;
}

int Vertex::getIn(int pos) const {
	return in[pos];
}

int Vertex::getOut(int pos) const {
	return out[pos];
}

int Vertex::getInSize() const {
	return in.size();
}

int Vertex::getOutSize() const {
	return out.size();
}

void Vertex::setVal(int value) {
	val = value;
}

void Vertex::addIn(int newin) {
	bool inserted = false;

	for (size_t i = 0; i < in.size(); i++) {
		if (newin <= in[i]) {	// checking for the correct place to put the new id so that they remain in increasing order
			vector<int>::iterator it;
			it = in.begin() + i;	// creating a vector iterator at the correct location
			in.insert(it,newin,1);	// inserting the new id
			inserted = true;
			break;
		}
	}

	if (!inserted) {
		in.push_back(newin);
	}
}

void Vertex::addOut(int newout) {
	bool inserted = false;

	for (size_t i = 0; i < out.size(); i++) {	// iterating through the outgoing edges
		if (newout <= out[i]) {	// checking for the correct place to put the new id so that they remain in increasing order
			vector<int>::iterator it;
			it = out.begin() + i;	// creating a vector iterator at the correct location
			out.insert(it,newout,1);	// inserting the new id
			inserted = true;
			break;
		}
	}

	if (!inserted) {
		out.push_back(newout);
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

bool Vertex::operator==(const Vertex& right) const {
	return id == right.id;
}

bool Vertex::operator!=(const Vertex& right) const {
	return !(*this == right);
}




