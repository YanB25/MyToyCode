#include <iostream>
#include <vector>
using namespace std;
#include "Graph.h"

class Cycle {
public:
	Cycle(Graph& G);
	bool hasCycle() { return _hasCycle;}
private:
	bool _hasCycle;
	vector<bool> hasVisit;
	void dfs(Graph& G, int s, int prev);
};

Cycle::Cycle(Graph& G) {
	_hasCycle = false;
	hasVisit.resize(G.vec());
	for (int i = 0; i < G.vec(); ++i) {
		if (!hasVisit[i]) {
			dfs(G, i, i);
		}
	}
}

void Cycle::dfs(Graph& G, int s, int prev) {
	hasVisit[s] = true;
	for (int i : G.adj(s)) {
		if (!hasVisit[i]) {
			dfs(G, i, s);
		}
		else if (i != prev) {
				_hasCycle = true;
		}
	}
}

int main (int argc, char const* argv[])
{
	freopen("input", "r", stdin);
	Graph G(cin);
	Cycle cycle(G);
	printf("%d\n", cycle.hasCycle());
	return 0;
}
