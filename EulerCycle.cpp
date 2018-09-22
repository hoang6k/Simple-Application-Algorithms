#include <bits/stdc++.h>
using namespace std;
#define MAXN 100
int n, m, u, v, A[MAXN][MAXN];
stack<int> S, CE;
vector<int> adj[MAXN];
void initialize() {
	cin >> n >> m;
	while (m--) {
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}
void euler_cycle() {
	S.push(1);
	while (!S.empty()) {
		int x = S.top();
		if (adj[x].size() != 0) {
			int y = adj[x][0];
			S.push(y);
			adj[x].erase(adj[x].begin());
			for (int j = 0; j < (int) adj[y].size(); j++)
				if (adj[y][j] == x) {
					adj[y].erase(adj[y].begin() + j);
				}
		} else {
			x = S.top();
			S.pop();
			CE.push(x);
		}
	}
}
int main() {
	initialize();
	euler_cycle();
	while (!CE.empty()) {
		cout << CE.top() << " ";
		CE.pop();
	}
	return 0;
}
/*
7 12
1 2
1 3
1 5
1 7
2 4
2 6
2 7
3 4
3 5
3 7
4 6
4 7
*/
