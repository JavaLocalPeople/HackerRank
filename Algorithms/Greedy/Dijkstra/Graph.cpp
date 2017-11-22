#include "Graph.h"
#include <vector>
#include <queue>
#include <functional>
#define INF 0x3f3f3f3f

// overload constructor
Graph::Graph(int V)
{
	this->m_V = V;
	this->m_adjList = new std::list<Node>[V];
	//this->m_visited = new bool[V];

	// Mark all the vertices as not visited
	/*for (int i = 0; i <= V; ++i) {
		this->m_visited[i] = false;
	}*/
}

// destructor
Graph::~Graph() {
	delete[] this->m_adjList;
	delete[] this->m_visited;
}

void Graph::addEdge(int v, int w, int weight) {
	Node inV = v;
	inV.setWeight(weight);
	Node inW = w;
	inW.setWeight(weight);

	this->m_adjList[v].push_back(inW); // Add w to v’s list.
	this->m_adjList[w].push_back(inV);
}

struct compare
{
	bool operator()(Node* l, Node* r)
	{
		return l->getWeight() > r->getWeight();
	}
};

void Graph::Dijkstra(int source) {

	// set the priority queue
	std::priority_queue<Node*, std::vector<Node*>, compare > distancePQ;

	// set the vector of distance from source to INF
	std::vector<int> distanceList(this->m_V, INF);

	Node s = source;
	s.setWeight(0);
	distancePQ.push(&s);

	distanceList[source] = 0;

	while (!distancePQ.empty()) {
		int topIndex = distancePQ.top()->getIndex();
		distancePQ.pop();

		std::list<Node>::iterator i;
		for (i = this->m_adjList[topIndex].begin(); i != this->m_adjList[topIndex].end(); ++i) {
			int localVertex = (*i).getIndex();
			int localWeight = (*i).getWeight();

			if (distanceList[localVertex] > distanceList[topIndex] + localWeight) {
				distanceList[localVertex] = distanceList[topIndex] + localWeight;
				(*i).setWeight(distanceList[localVertex]);
				distancePQ.push(&(*i));
			}
		}
	}

	printf("Vertex Distance from Source\n");
	for (int i = 0; i < this->m_V; ++i)
		printf("%d \t\t %d\n", i, distanceList[i]);
}
