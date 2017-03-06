#include "Edge.h"
#include "WeightedGraph.h"
#include <vector>
#include <iostream>
#include <map>
#include <cfloat>
using namespace std;
class InTimePrim {
public:
	InTimePrim(WeightedGraph& G);
	double GetWeight() const;
	const vector<Edge>& GetEdges() const { return prev; }
private:
	vector<bool> visited;
	vector<double> distToTree;
	map<double, int> mpDistToV;
	vector<Edge> prev;
	void AddToTree(WeightedGraph& G, int v);
};
double InTimePrim::GetWeight() const {
	double w = 0;
	for (auto e : prev) {
		w += e.GetWeight();
	}
	return w;
}

InTimePrim::InTimePrim(WeightedGraph& G) {
	visited.resize(G.V());
	distToTree.resize(G.V());
	prev.resize(G.V());
	for (auto& i : distToTree) {
		i = DBL_MAX;
	}
	distToTree[0] = 0;
	mpDistToV[0] = 0;
	
	while (!mpDistToV.empty()) {
		auto it = mpDistToV.begin();
		AddToTree(G, it->second);
		mpDistToV.erase(it);
	}
}

void InTimePrim::AddToTree(WeightedGraph& G, int v) {
	visited[v] = true;
	for (auto e : G.adj(v)) {
		int x = e.other(v);
		if (visited[x]) continue;
		if (e.GetWeight() < distToTree[x]) {
			distToTree[x] = e.GetWeight();
			prev[x] = e;
			mpDistToV[distToTree[x]] = x;
		}
	}
}


int main() {
	freopen("input", "r", stdin);
	WeightedGraph G(cin);
	InTimePrim mst(G);
	printf("%lf\n", mst.GetWeight());
	for (auto e : mst.GetEdges()) {
		int x = e.either(), y = e.other(x);
		printf("(%d %d) ", x, y);
	}	
	printf("\n");
	return 0;
}


