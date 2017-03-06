#include "DirGraph.h"
#include "DirGraphOrder.h"
#include <vector>
#include <deque>
using namespace std;
int main() {
	freopen("input", "r", stdin);
	DirGraph G(cin);
	DirGraphOrder order(G);
	for (int i : order.GetPrev()) {
		printf("%d ", i);
	}
	return 0;
}
