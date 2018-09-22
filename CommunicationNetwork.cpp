#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX
short A[10001][10001] = { };
int n, k, m, u, v, w, _min = INF;
void networks() {
	int sp[n + 1][n + 1][k + 1 + 1] = { };
	for (int e = 1; e <= k; e++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				sp[i][j][e] = INF;
				if (e == 1 && A[i][j]) {
					sp[i][j][e] = A[i][j];
//					printf("\nsp[%d][%d][%d]=%d", i, j, e, sp[i][j][e]);
					if (e == k)
						_min = min(_min, sp[i][j][e]);
				} else if (e > 1) {
					for (int a = 0; a < n; a++) {
						if ((i - a) && (j - a) && (i - j) && A[i][a]
								&& sp[a][j][e - 1] != INF) {
							sp[i][j][e] = min(sp[i][j][e],
									A[i][a] + sp[a][j][e - 1]);
//							printf("\nsp[%d][%d][%d]=%d", i, j, e, sp[i][j][e]);
							if (e == k)
								_min = min(_min, sp[i][j][e]);
						}
					}
				}
			}
		}
	}
}
void initialize() {
	scanf("%d %d %d", &n, &k, &m);
	while (m--) {
		scanf("%d %d %d", &u, &v, &w);
		A[u - 1][v - 1] = w;
		A[v - 1][u - 1] = w;
	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++)
//			printf("%d ", A[i][j]);
//		printf("\n");
//	}
}
int main() {
	initialize();
	networks();
	printf("%d", _min);
	return 0;
}
