#include "DirGraph.h"
#include "DirGraphOrder.h"
#include <vector>
class CC {
public:
	CC(DirGraph& G);
private:
	vector<bool> hasVisit;
	vector<int> id;
	int cnt;
	void dfs(DirGraph& G, int);
};

CC::CC(DirGraph& G) {
	hasVisit.resize(G.V());
	id.resize(G.V());
	cnt = 0;
	
	DirGraph Rev = G.reverse();
	DirGraphOrder order(Rev);
	for (int i : order.GetPostRev()) {
		if (!hasVisit[i]) {
			dfs(G, i);
			cnt++;
			printf("\n");
		}
	}
}

void CC::dfs(DirGraph& G, int s) {
	printf("%d ", s);//
	hasVisit[s] = true;
	id[s] = cnt;
	for (int i : G.adj(s)) {
		if (!hasVisit[i]) {
			dfs(G, i);
		}
	}
}

int main() {
	freopen("input", "r", stdin);
	DirGraph G(cin);
	CC cc(G);
	return 0;
}
