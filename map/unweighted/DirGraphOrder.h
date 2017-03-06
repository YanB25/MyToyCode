#ifndef TOPOLOGICAL_SORT_H_
#define TOPOLOGICAL_SORT_H_

#include "DirGraph.h"
#include <vector>
#include <deque>
#include <iostream>
using namespace std;

class DirGraphOrder {
public:
	const vector<int>& GetPrev() const {return prev;}
	const vector<int>& GetPost() const {return post;}
	const deque<int> & GetPostRev() const {return postRev;}
	DirGraphOrder(DirGraph& G);
private:
	vector<bool> hasVisit;
	vector<int> EdgeTo;
	vector<int> prev;
	vector<int> post;
	deque<int> postRev;
	void dfs(DirGraph& G, int s);
};

#endif

//int main() {
//	freopen("input", "r", stdin);
//	DirGraph G(cin);
//	DirGraphOrder order(G);
//	for (int i : order.GetPrev()) {
//		printf("%d ", i);
//	}
//	printf("\n");
//	for (int i : order.GetPost()) {
//		printf("%d ", i);
//	}
//	printf("\n");
//	for (int i : order.GetPostRev()) {
//		printf("%d ", i);
//	}
//	printf("\n");
//	return 0;
//}

	
