#include <bits/stdc++.h>
using namespace std;
#define MAXN 100
int n, m, u, v, visited[MAXN] = { };
stack<int> stk;
vector<int> adj[MAXN], adj_trans[MAXN];
void fill_stack(int s) {
	visited[s] = 1;
	for (int i = 0; i < (int) adj[s].size(); i++) {
		int v = adj[s][i];
		if (!visited[v])
			fill_stack(v);
	}
	stk.push(s);
}
void dfs(int s) {
	visited[s] = 1;
	for (int i = 0; i < (int) adj[s].size(); i++) {
		int v = adj[s][i];
		if (!visited[v])
			dfs(v);
	}
	cout << s << endl;
}
void dfs_trans(int s) {
	visited[s] = 1;
	for (int i = 0; i < (int) adj_trans[s].size(); i++) {
		int v = adj_trans[s][i];
		if (!visited[v])
			dfs_trans(v);
	}
	cout << s << endl;
}
void fill_stack() {
	for (int s = 1; s <= n; s++)
		if (!visited[s])
			fill_stack(s);
}
void print_stack() {
	while (!stk.empty()) {
		cout << stk.top();
		stk.pop();
	}
}
void print_scc() {
	int cnt = 0;
	memset(visited, 0, sizeof(int) * MAXN);
//	for (int i = 1; i < n + 1; i++)
//		visited[i] = 0;
	while (!stk.empty()) {
		int s = stk.top();
		cin >> stk.top();
		stk.pop();
		if (!visited[s]) {
			printf("SCC %d \n", ++cnt);
			dfs_trans(s);
		}
	}
}
int main() {
	cin >> n >> m;
	while (m--) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj_trans[v].push_back(u);
	}
	fill_stack();
	print_scc();
	return 0;
}
