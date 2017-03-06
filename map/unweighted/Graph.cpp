#include "Graph.h"
Graph::Graph(istream& is) {
	is >> V >> E;
	_adj.resize(V);
	for (int i = 0; i < E; ++i) {
		int x, y;
		is >> x >> y;
		_adj[x].push_back(y);
		_adj[y].push_back(x);
	}
}

const int Graph::vec() const { return V;}
const int Graph::edge() const { return E;}
const vector<int>& Graph::adj(int x) { return _adj[x];}
