#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001
#define INF INT_MAX
int n, m, u, v, c, d[MAXN] = { }, near[MAXN] = { }, _count = 1;
long cost = 0;
bool visited[MAXN] = { };
typedef pair<int, int> ipair;
vector<ipair> adj[MAXN];
ipair result[MAXN];
struct myless: public binary_function<ipair, ipair, bool> {
	bool operator()(const ipair& __x, const ipair& __y) const {
		if (__x.first < __y.first)
			return 1;
		else if (__x.first == __y.first)
			if (__x.second < __y.second)
				return 1;
			else
				return 0;
		else
			return 0;
	}
};
void initialize() {
	cin >> n >> m;
	while (m--) {
		scanf("%d %d %d", &u, &v, &c);
		adj[u].push_back(make_pair(v, c));
		adj[v].push_back(make_pair(u, c));
	}
	visited[1] = 1;
	for (int i = 0; i < (int) adj[1].size(); i++)
		d[adj[1][i].first] = adj[1][i].second;
	for (int i = 2; i <= n; i++) {
		near[i] = 1;
		if (!d[i])
			d[i] = INF;
	}
}
void MST() {
	while (_count < n) {
		int _min = INF;
		for (int i = 1; i <= n; i++)
			if (!visited[i] && d[i] < _min) {
				v = i;
				_min = d[i];
			}
		visited[v] = 1;
		cost += d[v];
		result[_count++] = make_pair(min(v, near[v]), max(v, near[v]));
		for (int i = 0; i < (int) adj[v].size(); i++) {
			u = adj[v][i].first;
			if (!visited[u] && d[u] >= adj[v][i].second) {
				if (d[u] > adj[v][i].second) {
					d[u] = adj[v][i].second;
					near[u] = v;
				} else {
					near[u] = min(near[u], v);
				}
			}
		}
	}
}
int main() {
	initialize();
	MST();
	sort(result + 1, result + n, myless());
	printf("%li\n", cost);
	for (int i = 1; i < n; i++)
		printf("%d %d ", result[i].first, result[i].second);
	return 0;
}
/*
 4 6
 2 1 3
 2 3 1
 3 1 10
 4 1 5
 3 4 5
 4 2 6
 */
