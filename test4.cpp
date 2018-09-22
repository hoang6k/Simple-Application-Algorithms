#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX
int n, k, m, u, v, w, _min = INF, ***sp, temp;
vector<vector<short> > A, B;
void networks() {
	sp = new int**[n + 1];
	for (int i = 0; i < n + 1; i++) {
		sp[i] = new int*[n + 1];
		for (int j = 0; j < n + 1; j++) {
			sp[i][j] = new int[k + 1];
			for (int l = 0; l < k + 1; l++)
				sp[i][j][l] = INF;
		}
	}
//	for (int e = 1; e <= k; e++) {
//		for (int i = 1; i < n + 1; i++) {
//			for (int j = 1; j < n + 1; j++)
//				printf("%d ", sp[i][j][e]);
//			printf("\n");
//		}
//		printf("\n\n");
//	}
	for (int e = 1; e <= k; e++) {
		if (e == 1) {
			for (int i = 1; i < n + 1; i++)
				for (unsigned int j = 0; j < A[i].size(); j++) {
					sp[i][A[i][j]][e] = B[i][j];
					printf("\nsp[%d][%d][%d]=%d", i, A[i][j], e,
							sp[i][A[i][j]][e]);
				}
		} else
			for (int i = 1; i < n + 1; i++) {
				for (int j = 1; j < n + 1; j++) {
					for (unsigned int x = 0; x < A[i].size(); x++) {
						temp = A[i][x];
						if ((temp - j) && (i - j) && sp[temp][j][e - 1] != INF) {
							sp[i][j][e] = min(sp[i][j][e],
									B[i][x] + sp[temp][j][e - 1]);
							printf("\nsp[%d][%d][%d]=%d", i, j, e, sp[i][j][e]);
							if (e == k)
								_min = min(_min, sp[i][j][e]);
						}
					}
				}
			}
	}
}
void initialize() {
	scanf("%d %d %d", &n, &k, &m);
	for (int i = 0; i < n + 1; i++) {
		A.push_back(vector<short>());
		B.push_back(vector<short>());
	}
	while (m--) {
		scanf("%d %d %d", &u, &v, &w);
		A[u].push_back(v);
		B[u].push_back(w);
		A[v].push_back(u);
		B[v].push_back(w);
	}
//	for (int i = 1; i < n + 1; i++) {
//		for (unsigned int j = 0; j < A[i].size(); j++)
//			printf("%d ", A[i][j]);
//		printf("\n");
//	}
//	for (int i = 1; i < n + 1; i++) {
//		for (unsigned int j = 0; j < A[i].size(); j++)
//			printf("%d ", B[i][j]);
//		printf("\n");
//	}
}
int main() {
	initialize();
	networks();
	printf("%d", _min);
	return 0;
}
