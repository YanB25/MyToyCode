#include "DirGraph.h"
#include <iostream>
#include <vector>
using namespace std;

class DirCycle {
public:
	DirCycle(DirGraph& G);
	bool HasCycle() { return hasCycle;}
	const vector<int>& GetCycle() const { return cycle;}
private:
	bool hasCycle;
	vector<int> cycle;
	vector<bool> onStack;
	vector<bool> hasVisit;
	vector<int> prev;
	void dfs(DirGraph& G, int s);
};

DirCycle::DirCycle(DirGraph& G) {
	hasCycle = false;
	hasVisit.resize(G.V());
	onStack.resize(G.V());
	prev.resize(G.V());
	for (int i = 0; i < G.V(); ++i) {
		if (!hasVisit[i]){
			dfs(G, i);
		}
	}
}

void DirCycle::dfs(DirGraph& G, int s) {
	hasVisit[s] = true;
	onStack[s] = true;
	for (int i : G.adj(s)) {
		if (!hasVisit[i]) {
			prev[i] = s;
			dfs(G, i);
		}else if (onStack[i] && !hasCycle) {
			hasCycle = true;
			cycle.push_back(i);
			for (int v = s; v != i; v = prev[v]) {
				cycle.push_back(v);
			}
			cycle.push_back(i);
		}
	}
	onStack[s] = false;
}
			
int main() {
	freopen("input", "r", stdin);
	DirGraph G(cin);
	G = G.reverse();
//	for (int i = 0; i < G.V(); ++i) {
//		printf("%d:", i);
//		for (int j : G.adj(i)) {
//			printf("%d ", j);
//		}
//		printf("\n");
//	}
	DirCycle search(G);
	if (search.HasCycle()) {
		for (int i : search.GetCycle()) {
			printf("%d ",i);
		}
	}else {
		printf("no cycle");
	}
	printf("\n");
	return 0;
}	
			
			
			
