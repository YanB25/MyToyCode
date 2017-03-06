#include "DirGraph.h"
#include <vector>
#include <iostream>
using namespace std;
DirGraph::DirGraph(istream& is) {
	is >> _v >> _e;
	_adj.resize(_v);
	for (int i = 0; i < _e; ++i) {
		int from, to;
		is >> from >> to;
		_adj[from].push_back(to);
	}
}

DirGraph::DirGraph(int v) {
	_v = v;
	_e = 0;
	_adj.resize(v);
}

void DirGraph::InsertEdge(int from, int to) {
	_adj[from].push_back(to);
	_e++;
}

DirGraph DirGraph::reverse() const {
	DirGraph rev(V());
	for (int i = 0; i < V(); ++i) {
		for (int j : adj(i)) {
			rev.InsertEdge(j ,i);
		}
	}
	return rev;
}
	
