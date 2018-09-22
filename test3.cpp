#include <bits/stdc++.h>
#define MAXN 100
using namespace std;
int n, m/*, a[MAXN][MAXN]*/;
bool visited[MAXN] = { };
queue<int> q;
list<int> adj[MAXN];
void bfs(int s) {
	q.push(s);
	visited[s] = 1;
	while (!q.empty()) {
		int u = q.front();
		cout << u + 1 << endl;
//		for (int i = 0; i < m; i++) {
		for (list<int>::iterator i = adj[u].begin(); i != adj[u].end(); i++) {
			int v = *i;
//			if (a[u][i] && !visited[i]) {
			if (!visited[v]) {
				q.push(v);
				visited[v] = 1;
			}
		}
		q.pop();
	}
}
int main() {
	scanf("%d %d", &n, &m);
	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
//		a[u - 1][v - 1] = a[v - 1][u - 1] = 1;
		adj[u - 1].push_back(v - 1);
		adj[v - 1].push_back(u - 1);
	}
	for (int i = 0; i < n; i++)
		if (!visited[i])
			bfs(i);
	return 0;
}
