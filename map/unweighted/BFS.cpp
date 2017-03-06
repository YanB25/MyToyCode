#include <vector>
#include <iostream>
#include <queue>
#include <string>
#include "Graph.h"
class BreadthFirstSearch {
public:
	BreadthFirstSearch(Graph& G, int s);
	void bfs(Graph& G, int s);
	bool hasPath(int s)const;
	const vector<int> path(int s) const;
	const string toString(int s) const;
	const int dis(int s) const {return distance[s];}
private:
	vector<bool> hasVisit;
	int s;
	vector<int> prev;
	vector<int> distance;
};

BreadthFirstSearch::BreadthFirstSearch(Graph& G, int s) {
	hasVisit.resize(G.vec());
	this->s = s;
	prev.resize(G.vec());
	distance.resize(G.vec());
	
	bfs(G, s);
}

void BreadthFirstSearch::bfs(Graph& G, int s) {
	hasVisit[s] = true;
	prev[s] = s;
	distance[s] = 0;
	queue<int> que;
	que.push(s);
	while (!que.empty()) {
		int e = que.front();
		que.pop();
		for (int j : G.adj(e)) {
			if (!hasVisit[j]) {
				prev[j] = e;
				hasVisit[j] = true;
				distance[j] = distance[e] + 1;
				que.push(j);
			}
		}
	}
}

bool BreadthFirstSearch::hasPath(int s) const{ return hasVisit[s];}
const vector<int> BreadthFirstSearch::path(int v) const {
	if (!hasPath(v)) {
		return vector<int> ();
	}
	vector<int> res;
	for (int i = v; i != s; i = prev[i]) {
		res.push_back(i);
	}
	res.push_back(s);
	return res;
}

int main() {
	freopen("input", "r", stdin);
	Graph G(cin);
	BreadthFirstSearch search(G, 0);
	for (int i = 0; i < G.vec(); ++i) {
		printf("%d:", i);
		printf(" dis: %d path: ", search.dis(i));
		for (int j : search.path(i)) {
			printf("%d ", j);
		}
		printf("\n");
	}
	return 0;
}
	
	
	
	
	
