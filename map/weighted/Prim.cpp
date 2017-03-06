#include "Edge.h"
#include "WeightedGraph.h"
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
class Prim {
public:
	Prim(WeightedGraph& G);
	double GetWeight() const { return weight; }
	const vector<Edge>& GetEdges() const { return edges; } 
private:
	double weight;
	vector<Edge> edges;
	priority_queue<Edge> pq;
	vector<bool> onTree;
	void AddInTree(WeightedGraph& G, int v);
};

Prim::Prim(WeightedGraph& G) {
	weight = 0;
	onTree.resize(G.V());
	AddInTree(G, 0);
	
	while (!pq.empty()) {
		Edge edge = pq.top();
		pq.pop();
		int x = edge.either(), y = edge.other(x);
		if (onTree[x] && onTree[y]) continue;
		weight += edge.GetWeight();
		edges.push_back(edge);
		if (!onTree[x]) AddInTree(G, x);
		else AddInTree(G, y);
	}
}

void Prim::AddInTree(WeightedGraph& G, int v) {
	onTree[v] = true;
	for (auto e : G.adj(v)) {
		if (!onTree[e.other(v)]) {
			pq.push(e);
		}
	}
}

int main() {
	freopen("input", "r", stdin);
	WeightedGraph G(cin);
	Prim mst(G);
	printf("%lf\n", mst.GetWeight());
	for (auto e : mst.GetEdges()) {
		int x = e.either(), y = e.other(x);
		printf("(%d %d) ", x, y);
	}	
	printf("\n");
	return 0;
}
