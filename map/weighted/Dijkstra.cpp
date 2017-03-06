#include "DirEdge.h"
#include "WeightedDirGraph.h"
#include <vector>
#include <iostream>
#include <map>
#include <cfloat>
using namespace std;
class Dijkstra {
public:
	Dijkstra(WeightedDirGraph& G, int s);
	bool hasPath(int x) const { return hasVisit[x];}
	vector<DirEdge> GetPath(int x);
	double GetDist(int x) const { return distToRoot[x];}
private:
	vector<double> distToRoot;
	int s;
	vector<DirEdge> prev;
	vector<bool> hasVisit;
	map<double, int> mpDistToV;
	void relax(WeightedDirGraph& G, int v);
};

Dijkstra::Dijkstra(WeightedDirGraph& G, int s) {
	distToRoot.resize(G.V());
	for (auto& i : distToRoot) {
		i = DBL_MAX;
	}
	this->s = s;
	prev.resize(G.V());
	hasVisit.resize(G.V());
	distToRoot[s] = 0;
	mpDistToV[0] = s;
	
	while (!mpDistToV.empty()) {
		//for (auto it = mpDistToV.begin(); it != mpDistToV.end(); ++it) printf("%.2lf %d / ", it->first, it->second);
		//printf("\n");
		auto it = mpDistToV.begin();
		relax(G, it->second);
		mpDistToV.erase(it);
	}
}

void Dijkstra::relax(WeightedDirGraph& G, int s) {
	hasVisit[s] = true;
	for (auto e : G.adj(s)) {
		int f = e.From(), t = e.To();
		//printf("%d %d %d \n",s , f, t);
		if (distToRoot[t] > distToRoot[f] + e.GetWeight()) {
			prev[t] = e;
			distToRoot[t] = distToRoot[f] + e.GetWeight();
			mpDistToV[distToRoot[t]] = t;
		}
	}
}
	
vector<DirEdge> Dijkstra::GetPath(int v) {
	vector<DirEdge> ret;
	if (!hasPath(v) || v == s) return ret;
	DirEdge e; 
	for (e = prev[v]; e.From() != s; e = prev[e.From()]) {
		ret.push_back(e);
	}
	ret.push_back(e);
	return ret;
}
	

int main() {
	freopen("input", "r", stdin);
	WeightedDirGraph G(cin);
	Dijkstra sp(G, 0);
	for (int i = 0; i < G.V(); ++i) {
		printf("%d: ", i);
		if (sp.hasPath(i)) printf("%.2lf ", sp.GetDist(i));
		for (auto e : sp.GetPath(i)) {
			printf("(%d %d) ", e.From(), e.To());
		}
		printf("\n");
	}
	printf("\n");
	
	return 0;
}
