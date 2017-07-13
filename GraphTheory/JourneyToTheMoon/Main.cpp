#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector> 
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <cassert>

using namespace std; // }}}

class Graph
{
	long long V; // # of vertices
	list<long long> *adj; // pointer to an array containing adjacency list;

public:
	
	long long count; // count the connected component(nodes) in one adjacency list
	Graph(long long V); // constructor
	void DFSUtil(long long v, bool visited[]);
	void initialDFS(bool visited[]);
	void addEdge(long long a, long long b);
	bool notVisit(long long i, bool visited[]);
	//void connectComponents();
};

Graph::Graph(long long V)
{
	this->V = V;
	adj = new list<long long>[V];

}

bool Graph::notVisit(long long i, bool visited[])
{
	if (visited[i] == false)
	{
		return true;
	}
	return false;
}

void Graph::addEdge(long long a, long long b)
{
	adj[a].push_back(b);
    adj[b].push_back(a);
}

void Graph::DFSUtil(long long v, bool visited[])
{
	// now the node is visited
	visited[v] = true;
	count++;

	// iterate through the linkedlist of its node to track its following neighbour
	list<long long>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
	{
		// if it is not visited, call DFSUtil again to 1: mark it is visited 
		//2: follow its neighbour.
		if (!visited[*i])
		{
			DFSUtil(*i, visited);
		}
	}
}

void Graph::initialDFS(bool visited[])
{

	// initialize that every node is false for tracking whether it would be 
	//visited later.
	for (long long i = 0; i < V; i++)
	{
		visited[i] = false;
	}

	// call DFSUtil to start build connected component map. 

}

int main()
{ 
    long long N, I;
    cin >> N >> I;
    Graph g(N);
    
    for (long long i = 0; i < I; ++i) {
        long long a, b;
        cin >> a >> b;
        g.addEdge(a, b);
    }
    bool *visited = new bool[N];
    
    int *cc = new int[N];
    long long result = N * (N - 1) / 2;
            //cout << "Now the result is " << result << endl;

    g.initialDFS(visited);    
    /** Write code to compute the result using N,I,pairs **/
    for (long long i = 0; i < N; i++)
	{	
		g.count = 0;
		if (g.notVisit(i, visited))
        {
            g.DFSUtil(i, visited);
            //cout << "Currently the node " << i << " has " << g.count << " size" << endl;

			result = result - g.count*(g.count - 1) / 2;
	        //cout << "Now the result is " << result << endl;
        }
			


	}
    
    cout << result << endl;
    return 0;
}
