#include <bits/stdc++.h>
using namespace std;
int a[10000], b[10000], c[10000], ix[10000], _max = 0;
short _temp, temp[10001] = { }, A[10001][5000] = { }, B[10001][5000] = { };
int n, k, m, u, v, w, cost = 0, _count = 0, pathmin, _min = 1000000;
bool visited[10001] = { };
template<typename _Tp>
struct indexless: public binary_function<_Tp, _Tp, bool> {
	bool operator()(const _Tp& __x, const _Tp& __y) const {
		return c[__x] < c[__y];
	}
};
void networks(int x) {
	for (short i = 1; i <= temp[x]; i++) {
		short _next = A[x][i];
		int _cost = B[x][i];
		if (!visited[_next] && _min > cost + _cost + (k - _count) * pathmin) {
//			cout << "Tu dinh " << x << " di den dinh " << _next << endl;
			cost += _cost;
//			cout << " Cost= " << cost << endl;
			visited[_next] = true;
			if (_count++ < k)
				networks(_next);
			else {
				_min = cost;
				if (++_max > 2) {
					printf("%d", _min);
					exit(0);
				}
//				cout << "  _min = " << _min << endl;
			}
			_count--;
			cost -= _cost;
			visited[_next] = false;
		}
	}
}
void initialize() {
	scanf("%d %d %d", &n, &k, &m);
	temp[0] = n;
	short i;
	for (i = 1; i <= n; i++)
		A[0][i] = i;
	for (i = 0; i < m; i++)
		ix[i] = i;
	i = -1;
	while (++i < m)
		scanf("%d %d %d", &a[i], &b[i], &c[i]);
	sort(ix, ix + m, indexless<int>());
	pathmin = c[0];
	i = -1;
	while (++i < m) {
		u = a[ix[i]];
		v = b[ix[i]];
		w = c[ix[i]];
		_temp = ++temp[u];
		A[u][_temp] = v;
		B[u][_temp] = w;
		_temp = ++temp[v];
		A[v][_temp] = u;
		B[v][_temp] = w;
	}
//	cout << "pathmin=" << pathmin << endl;
//	for (int i = 1; i < n + 1; i++) {
//		for (int j = 0; j <= temp[i]; j++)
//			printf("%d ", A[i][j]);
//		cout << "\n";
//	}
//	cout << "\n";
//	for (int i = 1; i < n + 1; i++) {
//		for (int j = 0; j <= temp[i]; j++)
//			printf("%d ", B[i][j]);
//		cout << "\n";
//	}
}
int main() {
	initialize();
	networks(0);
	printf("%d", _min);
	return 0;
}
