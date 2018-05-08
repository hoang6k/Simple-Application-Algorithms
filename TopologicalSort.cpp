#include <bits/stdc++.h>
using namespace std;
#define MAXN 100
int n, m, u, v, bbv[MAXN] = { }, mark[MAXN];
vector<int> out[MAXN];
queue<int> vertex;
void topo_sort() {
	for (int i = 1; i <= n; i++)
		if (bbv[i] == 0)
			vertex.push(i);
	int next = 0;
	while (!vertex.empty()) {
		int v = vertex.front();
		mark[++next] = v;
		vertex.pop();
		for (int j = 0; j < (int) out[v].size(); j++) {
			bbv[out[v][j]]--;
			if (bbv[out[v][j]] == 0)
				vertex.push(out[v][j]);
		}
	}
}
int main() {
	cin >> n >> m;
	while (m--) {
		cin >> u >> v;
		out[u].push_back(v);
		bbv[v]++;
	}
	topo_sort();
	for (int i = 1; i <= n; i++)
		printf("%d ", i);
	printf("\n");
	for (int i = 1; i <= n; i++)
		printf("%d ", mark[i]);
	return 0;
}
/*
8 13
5 7
5 8
7 3
7 6
3 8
3 1
3 6
8 6
8 2
1 6
1 4
6 4
2 4
 */
