#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001
#define INF INT_MAX
int n, m, s, u, v, c, d[MAXN], pred[MAXN], _count = 1;
typedef pair<int, int> ipair;
list<int> nonfixed;
list<ipair> adj[MAXN];
ipair result[MAXN];
void Dijkstra() {
	while (!nonfixed.empty()) {
		int _min = INF;
		for (list<int>::iterator i = nonfixed.begin(); i != nonfixed.end();
				i++) {
			if (d[*i] < _min) {
				v = *i;
				_min = d[*i];
			}
		}
		nonfixed.remove(v);
		for (list<ipair>::iterator i = adj[v].begin(); i != adj[v].end(); i++) {
			ipair p = *i;
			u = p.first;
			adj[u].remove(make_pair(v, p.second));
			if (d[u] > d[v] + p.second) {
				d[u] = d[v] + p.second;
				pred[u] = v;
			}
		}
	}
	for (int i = 1; i <= n; i++)
		printf("d[%d] = %d, pred[%d] = %d\n", i, d[i], i, pred[i]);
}
void initialize() {
	cin >> n >> m >> s;
	while (m--) {
		scanf("%d %d %d", &u, &v, &c);
		adj[u].push_back(make_pair(v, c));
//		adj[v].push_back(make_pair(u, c));
	}
	for (list<ipair>::iterator i = adj[s].begin(); i != adj[s].end(); i++) {
		ipair p = *i;
		d[p.first] = p.second;
	}
	for (int i = 1; i <= n; i++) {
		pred[i] = s;
		if (!d[i])
			d[i] = INF;
		nonfixed.push_back(i);
	}
	d[s] = 0;
	nonfixed.remove(s);
}
int main() {
	initialize();
	Dijkstra();
	return 0;
}
/*
 5 10 1
 1 2 7
 1 3 6
 2 5 3
 2 4 9
 3 5 5
 3 2 8
 3 4 1
 4 1 2
 4 5 5
 5 3 2
 */
