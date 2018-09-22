#include <bits/stdc++.h>
using namespace std;
#define MAXN 5001
#define INF INT_MAX
int N, M, s, u, v, d[MAXN][MAXN] = { }, pred[MAXN][MAXN] = { }, e[MAXN],
		result = INF;
typedef pair<int, int> ipair;
list<int> nonfixed;
//list<int> adjorg[MAXN];
list<int> adj[MAXN];
void initialize() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= N; j++)
			d[i][j] = INF;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &u, &v);
//		adj[u].push_back(v);
//		adj[v].push_back(u);
		d[u][v] = 1;
		d[v][u] = 1;
	}
	for (int u = 1; u <= N; u++)
		for (int v = 1; v <= N; v++) {
			pred[u][v] = u;
		}
	for (int u = 1; u <= N; u++) {
		for (int v = 1; v <= N; v++) {
			printf("%d ", d[u][v]);
		}
		printf("\n\n");
	}
//	for (int i = 1; i <= N; i++) {
//		for (list<int>::iterator j = adjorg[i].begin(); j != adjorg[i].end();
//				j++) {
//			printf("\n%d", *j);
//		}
//		printf("\n");
//	}
}
int main() {
	initialize();
	for (int z = 1; z <= N; z++)
		for (int u = 1; u <= N; u++) {
			for (int v = 1; v <= N; v++) {
				if (u == v)
					continue;
				if (d[u][v] > d[u][z] + d[z][v]) {
					d[u][v] = d[u][z] + d[z][v];
					pred[u][v] = pred[z][v];
				}
			}
		}
	for (int s = 1; s <= N; s++) {
		int temp = 0;
		for (int i = 1; i <= N; i++) {
			temp = max(temp, d[s][i]);
			printf("d[%d] = %d, pred[%d] = %d\n", i, d[s][i], i, pred[s][i]);
		}
		e[s] = temp;
		printf("mind[%d] = %d\n\n", s, e[s]);
	}
	for (int i = 1; i <= N; i++)
		result = min(result, e[i]);
	printf("%d", result);
	return 0;
}
/*
 5 6
 1 2
 1 3
 1 5
 2 4
 2 5
 3 5
 */
