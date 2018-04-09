#include <bits/stdc++.h>
using namespace std;
int n, k, m, _count = 0, u, v, temp[31] = { }, A[31][31] = { };
bool visited[31] = { };
void KPath(int x) {
	for (int i = 1; i <= temp[x]; i++) {
		int _next = A[x][i];
		if (visited[_next])
			continue;
		else {
			visited[_next] = true;
			if (k--)
				KPath(_next);
			else
				_count++;
			k++;
			visited[_next] = false;
		}
	}
}
void initialize() {
	scanf("%d %d %d", &n, &k, &m);
	temp[0] = n;
	for (int i = 1; i <= n; i++)
		A[0][i] = i;
	while (m--) {
		scanf("%d %d", &u, &v);
		A[u][++temp[u]] = v;
		A[v][++temp[v]] = u;
	}
//	for (int i = 0; i < n + 1; i++) {
//		for (int j = 1; j < n + 1; j++)
//			printf(" %d ", A[i][j]);
//		printf("\n");
//	}
}
int main() {
	initialize();
	KPath(0);
	printf("%d", _count / 2);
	return 0;
}
