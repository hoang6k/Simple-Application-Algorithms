#include <bits/stdc++.h>
#include<limits.h>
using namespace std;
#define INF INT_MAX
#define MAXN 105
int c[MAXN][MAXN] = { };
int x[MAXN] = { };
int visited[MAXN] = { };
int n, cmin, fopt = INF, fcur;
void input() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> c[i][j];
			if (i != j) {
				if (!cmin)
					cmin = c[i][j];
				else
					cmin = min(cmin, c[i][j]);
			}
		}
}
void branch(int k) {
	for (int y = 1; y <= n; y++) {
		if (!visited[y]) {
			x[k] = y;
			visited[y] = 1;
			fcur += c[x[k - 1]][y];
			if (k == n) {
				if (fcur + c[y][1] < fopt)
					fopt = fcur + c[y][1];
			} else if (fcur + (n - k + 1) * cmin < fopt)
				branch(k + 1);
			visited[y] = 0;
			fcur -= c[x[k - 1]][y];
		}
	}
}
int main() {
	freopen("data.inp", "r", stdin);
	input();
	x[1] = 1;
	visited[1] = 1;
	branch(2);
	cout << fopt << endl;
	return 0;
}
