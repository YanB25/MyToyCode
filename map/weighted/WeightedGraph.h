#include "Edge.h"
#include <vector>
#include <iostream>
using namespace std;
class WeightedGraph {
public:
	const int V() const { return v;}
	const int E() const { return e;}
	WeightedGraph(istream& is);
	WeightedGraph(int x):v(x), e(0) { _adj.resize(x); }
	const vector<Edge>& adj(int x) const { return _adj[x];}
private:
	int v;
	int e;
	void InsertEdge(Edge e);
	vector<vector<Edge>> _adj;
};

WeightedGraph::WeightedGraph(istream& is) {
	is >> v >> e;
	_adj.resize(v);
	for (int i = 0; i < e; ++i) {
		//printf("%d %d ok\n", e, i);
		int x, y;
		double w;
		is >> x >> y >> w;
		_adj[x].push_back(Edge(x, y, w));
		_adj[y].push_back(Edge(x, y, w));
	}
}

void WeightedGraph::InsertEdge(Edge E) {
	e++;
	int x = E.either();
	int y = E.other(x);
	_adj[x].push_back(E);
	_adj[y].push_back(E);
}





