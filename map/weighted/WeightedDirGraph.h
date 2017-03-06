#ifndef WEIGHTED_DIR_GRAPH_H_
#define WEIGHTED_DIR_GRAPH_H_

#include "DirEdge.h"
#include <vector>
#include <iostream>
using std::vector;
using std::istream;

class WeightedDirGraph {
public:
	WeightedDirGraph(istream& is);
	WeightedDirGraph(int _v): v(_v), e(0) {}
	const vector<DirEdge>& adj(int x) const { return _adj[x];}
	const int V() const { return v;}
	const int E() const { return e;}
	void InsertDirEdge(DirEdge E);
	WeightedDirGraph reverse();
private:
	int v;
	int e;
	vector<vector<DirEdge>> _adj;
};

WeightedDirGraph::WeightedDirGraph(istream& is) {
	is >> v >> e;
	_adj.resize(v);
	for (int i = 0; i < e; ++i) {
		int from, to;
		double w;
		is >> from >> to >> w;
		DirEdge tmp(from, to, w);
		//printf("(%d %d %lf)", tmp.From(), tmp.To(), tmp.GetWeight());
		_adj[from].push_back(tmp);
	}
}

void WeightedDirGraph::InsertDirEdge(DirEdge E) {
	e++;
	_adj[E.From()].push_back(E);
}

WeightedDirGraph WeightedDirGraph::reverse() {
	WeightedDirGraph rev(V());
	for (int i = 0; i < V(); ++i) {
		for (auto e : adj(i)) {
			rev.InsertDirEdge(DirEdge(e.To(), e.From(), e.GetWeight()));
		}
	}
	return rev;
}
#endif
