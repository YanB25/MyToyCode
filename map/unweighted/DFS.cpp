#include <vector>
#include <iostream>
#include <stdio.h>
#include "Graph.h"
class DepthFirstSearch {
public:
	DepthFirstSearch(Graph& G, int s);
	const int count() const ;
	bool hasPath(int) const;
	const vector<int> path(int s)const;
private:
	vector<bool> marked;
	int s;
	int cnt;
	void dfs(Graph&, int);
	vector<int> prev;
};

DepthFirstSearch::DepthFirstSearch(Graph& G, int s) {
	this->s = s;
	marked.resize(G.vec());
	cnt = -1;
	
	dfs(G, s);
}

const int DepthFirstSearch::count() const { return cnt;}
bool DepthFirstSearch::hasPath(int x) const { return marked[x];}
void DepthFirstSearch::dfs(Graph& G, int s) {
	prev.resize(G.vec());
	marked[s] = true;
	cnt++;
	for (int i : G.adj(s)) 
		if (!marked[i]) {
			prev[i] = s;
			dfs(G, i);
		}
			
}
const vector<int> DepthFirstSearch::path(int v)const {
	if (!hasPath(v)) {
		return vector<int>();
	}
	vector<int> res;
	for (int i = v; i != s; i = prev[i]) {
		res.push_back(i);
	}
	res.push_back(s);
	//res.reverse();
	return res;
}
	
//
int main() {
	freopen("input", "r", stdin);
	Graph G(cin);
	DepthFirstSearch search(G, 0);
	for (int i = 0; i < G.vec(); ++i) {
		printf("%d: ", search.hasPath(i));
		for (int j : search.path(i)){
			printf("%d ", j);
		}
		printf("\n");
	}
	printf("\n%d\n", search.count());
	return 0;
}
