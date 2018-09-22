#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001
#define INF INT_MAX
int n, m, u, v, c, d[MAXN] = { }, near[MAXN] = { }, _count = 1;
long cost = 0;
typedef pair<int, int> ipair;
list<ipair> adj[MAXN];
list<int> S;
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
	for (int i = 1; i < n; i++)
		S.push_back(i + 1);
//	for (list<int>::iterator i = S.begin(); i != S.end(); i++) {
//		int v = *i;
//		cout << "visited[] = " << v << endl;
//	}
	for (list<ipair>::iterator i = adj[1].begin(); i != adj[1].end(); i++) {
		ipair p = *i;
		d[p.first] = p.second;
	}
	for (int i = 2; i <= n; i++) {
		near[i] = 1;
		if (!d[i])
			d[i] = INF;
	}
}
void MST() {
	while (_count < n) {
		int _min = INF;
		for (list<int>::iterator i = S.begin(); i != S.end(); i++) {
			if (d[*i] < _min) {
				v = *i;
				_min = d[*i];
			}
		}
		S.remove(v);
		cost += d[v];
		result[_count++] = make_pair(min(v, near[v]), max(v, near[v]));
		for (list<ipair>::iterator i = adj[v].begin(); i != adj[v].end(); i++) {
			ipair p = *i;
			u = p.first;
			adj[u].remove(make_pair(v, p.second));
			if (d[u] > p.second) {
				d[u] = p.second;
				near[u] = v;
			} else if (d[u] == p.second)
				near[u] = min(near[u], v);
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
