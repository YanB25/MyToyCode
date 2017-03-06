#include "DirGraph.h"
#include <iostream>
#include <vector>
using namespace std;
class hasPath {
public:
	hasPath(DirGraph& G);
	bool reachable(int, int) const;
private:
	vector<bool> hasVisit;
	vector<int> beg;
	vector<int> end;
	void dfs(DirGraph& G, int s);
	int step;
};

hasPath::hasPath(DirGraph& G) {
	hasVisit.resize(G.V());
	beg.resize(G.V());
	end.resize(G.V());
	step = 0;
	
	for (int i = 0; i < G.V(); ++i) {
		if (!hasVisit[i]) {
			dfs(G, i);
		}
	}
}

void hasPath::dfs(DirGraph& G, int s) {
	hasVisit[s] = true;
	beg[s] = ++step;
	for (int i : G.adj(s)) {
		if (!hasVisit[i]) {
			dfs(G, i);
		}
	}
	end[s] = ++step;
}

bool hasPath::reachable(int from, int to) const {
	if (beg[from] <= beg[to] && end[from] >= end[to])
		return true;
	return false;
}

int main() {
	freopen("input", "r", stdin);
	DirGraph G(cin);
	hasPath hp(G);
	printf("%4s","");
	for (int i = 0; i < G.V(); ++i) {
		printf("%3d", i);
	}
	printf("\n");
	for (int i = 0; i < G.V(); ++i) {
		printf("%3d:", i);
		for (int j = 0; j < G.V(); ++j) {
			printf("%3d", hp.reachable(i, j)?1:0);
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}

