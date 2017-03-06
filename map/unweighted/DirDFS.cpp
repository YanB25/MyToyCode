#include "DirGraph.h"
#include <iostream>
#include <vector>
using namespace std;
class DirDFS {
public:
	DirDFS(DirGraph& G, int s);
	bool hasPath(int s) const { return hasVisit[s]; }
	const vector<int> path(int) const;
private:
	int s;
	vector<bool> hasVisit;
	vector<int> prev;
	void dfs(DirGraph& G, int s);
};

DirDFS::DirDFS(DirGraph& G, int s) {
	this->s = s;
	hasVisit.resize(G.V());
	prev.resize(G.V());
	for (int i = 0; i < G.V(); ++i) {
		if (!hasVisit[i]) {
			dfs(G, i);
		}
	}
}

void DirDFS::dfs(DirGraph& G, int s) {
	printf("%d ", s);
	hasVisit[s] = true;
	for (int i : G.adj(s)) {
		if (!hasVisit[i]) {
			prev[i] = s;
			dfs(G, i);
		}
	}
}

const vector<int> DirDFS::path(int v) const {
	vector<int> res;
	if (!hasPath(v)) {
		return res;
	}
	for (int i = v; i != s; i = prev[i]) {
		res.push_back(i);
	}
	res.push_back(s);
	return res;
}

int main() {
	freopen("input", "r", stdin);
	DirGraph G(cin);
	DirDFS search(G, 0);
	for (int i = 0; i < G.V(); ++i) {
		printf("%d: ", i);
		for (int j : search.path(i)) {
			printf("%d ", j);
		}
		printf("\n");
	}
}
