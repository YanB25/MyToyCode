#include "DirGraphOrder.h"

DirGraphOrder::DirGraphOrder(DirGraph& G) {
	hasVisit.resize(G.V());
	EdgeTo.resize(G.V());
	
	for (int i = 0; i < G.V(); ++i) {
		if (!hasVisit[i]) {
			dfs(G, i);
		}
	}
}

void DirGraphOrder::dfs(DirGraph& G, int s) {
	hasVisit[s] = true;
	prev.push_back(s);
	for (int i : G.adj(s)) {
		if (!hasVisit[i]) {
			EdgeTo[i] = s;
			dfs(G, i);
		}
	}
	post.push_back(s);
	postRev.push_front(s);
}

