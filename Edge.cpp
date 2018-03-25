#include "Edge.h"
using namespace std;

int Edge::lastid = 0;

int Edge::getID() const {
	return id;
}

int Edge::getWeight() const {
	return weight;
}

Vertex* Edge::getStart() const {
	return start;
}

Vertex* Edge::getEnd() const {
	return end;
}

void Edge::setWeight(int newweight) {
	weight = newweight;
}

void Edge::setStart(Vertex* newstart) {
	start = newstart;
}

void Edge::setEnd(Vertex* newend) {
	end = newend;
}

bool Edge::operator==(const Edge& right) {
	if (weight == right.weight) {
		if (start == right.start) {
			if (end == right.end) {
				return true;
			}
		}
	}
	return false;
}

bool Edge::operator!=(const Edge& right) {
	return !(*this == right);
}
