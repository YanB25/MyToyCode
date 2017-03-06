#include "DirGraph.h"
#include "DirGraphOrder.h"
#include <vector>
#include <iostream>

class TopologicalSort {
public:
	TopologicalSort(DirGraph& G);
	const vector<int>& GetSorted() const { return hasSort;}
private:
	void dfs(DirGraph& G, int s);
	vector<int> hasSort;
};

TopologicalSort::TopologicalSort(DirGraph& G) {
	DirGraphOrder order(G);
	for (int i : order.GetPostRev()) {
		hasSort.push_back(i);
	}
}

int main() {
	freopen("input", "r", stdin);
	DirGraph G(cin);
	TopologicalSort tps(G);
	for (int i : tps.GetSorted()) {
		printf("%d ", i);
	}
	printf("\n");
}
