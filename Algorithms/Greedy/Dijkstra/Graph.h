#pragma once
#include <list>
#include "Node.h"


class Graph {
public:
	// big4
	Graph(int V);

	~Graph();

	Graph(const Graph &graph) = default;
	Graph& operator=(const Graph &graph) = default;

	// function to add an edge to graph
	void addEdge(int v, int w, int weight);

	int getVertex() const {
		return this->m_V;
	}
	void Dijkstra(int v);

	// total type of fishes
	int m_totalType;

private:

	// adjacent list for tracking connection
	std::list<Node> *m_adjList;
	// list for tracking the node been visited
	bool *m_visited;
	// list for tracking the node not been visited
	bool *m_unvisited;
	// total number of vertex(nodes)
	int m_V;

	
};
