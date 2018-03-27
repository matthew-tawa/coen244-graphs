#include "main.h"
using namespace std;

int main() {

	Vertex v1;
	Vertex v2(1);
	Vertex v3(2);
	Vertex v4(3);
	//Vertex v5(4);
	Edge e1(1,&v1,&v2);
	Edge e2(2,&v2,&v3);
	Edge e3(3,&v3,&v4);
	//Edge e4(4,&v1,&v5);
	//Edge e5(5,&v5,&v2);

	DirectionalCyclicalGraph dag;

	dag.addVertex(v1);
	dag.addVertex(v2);
	dag.addVertex(v3);
	dag.addVertex(v4);
	//dag.addVertex(v5);
	dag.addEdge(e1);
	dag.addEdge(e2);
	dag.addEdge(e3);
	//dag.addEdge(e3);
	//dag.addEdge(e4);
	//dag.addEdge(e5);

	dag.toString();


	return 0;
}


