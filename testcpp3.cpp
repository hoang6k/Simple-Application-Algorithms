#include <bits/stdc++.h>
using namespace std;
#define MAXM 10005
#define MAXN 10005
#define INF 1e10
int n, k, m, cmin = -1;
int c[MAXM][MAXM] = { };
int x[MAXM] = { }, visited[MAXN] = { };
long long fcur = 0, fopt = (long long) INF;
void branch_and_bound(int i) {
	for (int y = 1; y <= n; y++) {
		if ((!visited[y] && c[x[i - 1]][y] > 0) || i == 1) {
			x[i] = y;
			visited[y] = 1;
			fcur += c[x[i - 1]][y];
			if (i == k + 1) {
				if (fcur < fopt)
					fopt = fcur;
			} else if (fcur + (k + 1 - i) * cmin < fopt)
				branch_and_bound(i + 1);
			visited[y] = 0;
			fcur -= c[x[i - 1]][y];
		}
	}
}
void initialize() {
	scanf("%d %d\n%d", &n, &k, &m);
//	cin >> n >> k >> m;
	int u, v, w;
	while (m--) {
		scanf("%d %d %d", &u, &v, &w);
//		cin >> u >> v >> w;
		c[u][v] = w;
		c[v][u] = w;
		if (cmin == -1)
			cmin = w;
		else
			cmin = cmin < w ? cmin : w;
	}
}
int main() {
//	ios_base::sync_with_stdio(0);
	initialize();
	branch_and_bound(1);
//	cout << fopt << endl;
	printf("%ld", fopt);
	return 0;
}
