#include "WeightedGraph.h"
#include "Edge.h"
#include "UnionFind.h"
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
class Kruskal {
public:
	Kruskal(WeightedGraph& G);
	const double GetWeight() const { return weight;}
	const vector<Edge>& GetEdges() const { return edges;}
private:
	double weight;
	vector<Edge> edges;
	priority_queue<Edge> pq;
};

Kruskal::Kruskal(WeightedGraph& G) {
	weight = 0;
	for (int i = 0; i < G.V(); ++i) {
		for (auto e : G.adj(i)) {
			pq.push(e);
		}
	}
	
	UnionFind uf(G.V());
	while (!pq.empty()) {
		Edge e = pq.top();
		pq.pop();
		int x = e.either(), y = e.other(x);
		if (uf.isLinked(x, y)) continue;
		uf.link(x, y);
		weight += e.GetWeight();
		edges.push_back(e);
	}
}
	
int main() {
	freopen("input", "r", stdin);
	WeightedGraph G(cin);
	Kruskal mst(G);
	printf("\n%lf\n", mst.GetWeight());
	
	for (auto e : mst.GetEdges()) {
		int x = e.either(), y = e.other(x);
		printf("(%d %d) ", x, y);
	}	
	printf("\n");
	return 0;
}
