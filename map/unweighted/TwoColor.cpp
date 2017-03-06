#include <vector>
#include <iostream>
#include "Graph.h"
class TwoColor {
public:
	TwoColor(Graph& G);
	bool isTwoColor() { return _isTwoColor;}
private:
	vector<bool> hasVisit;
	bool _isTwoColor;
	vector<bool> color;
	void dfs(Graph& G, int s);
};

TwoColor::TwoColor(Graph& G) {
	hasVisit.resize(G.vec());
	_isTwoColor = true;
	color.resize(G.vec());
	color[0] = true;
	for (int i = 0; i < G.vec(); ++i)
		dfs(G, i);
}

void TwoColor::dfs(Graph& G, int s) {
	hasVisit[s] = true;
	for (int i : G.adj(s)) {
		if (!hasVisit[i]) {
			color[i] = !color[s];
			dfs(G, i);
		}
		else if (color[i] == color[s]) {
			_isTwoColor = false;
			return;
		}
	}
}

int main() {
	freopen("input", "r", stdin);
	Graph G(cin);
	TwoColor test(G);
	printf("%d\n", test.isTwoColor());
	return 0;
}
