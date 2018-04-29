#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX
int n, k, m, u, v, w, _min = INF, vertex, value;
struct vnv {
	short vt;
	int vl;
	vnv() :
			vt(0), vl(0) {
	}
	vnv(short _vt, int _vl) :
			vt(_vt), vl(_vl) {
	}
};
vector<vector<short> > A, B;
vector<vector<vector<vnv> > > sp;
int check(int vertex, int j, int e) {
	for (unsigned int i = 0; i < sp[e][vertex].size(); i++)
		if (sp[e][vertex][i].vt == j)
			return sp[e][vertex][i].vl;
	return 0;
}
void networks() {
	for (int e = 1; e <= k; e++) {
		if (e == 1) {
			for (int i = 1; i < n + 1; i++)
				for (unsigned int j = 0; j < A[i].size(); j++) {
					sp[e][i].push_back(vnv(A[i][j], B[i][j]));
//					printf("\nsp[%d][%d][%d]=%lu", e, i, sp[e][i].size() - 1,
//							B[i][j]);
					if (e == k)
						_min = min(_min, sp[e][i][j].vl);
				}
		} else {
			for (int i = 1; i < n + 1; i++)
				for (int j = 1; j < n + 1; j++)
					for (unsigned int x = 0; x < A[i].size(); x++) {
						vertex = A[i][x];
						value = check(vertex, j, e - 1);
						if (value && (vertex - j) && (i - j)) {
							sp[e][i].push_back(vnv(j, B[i][x] + value));
//							printf("\nsp[%d][%d][%d]=%lu", e, i,
//									sp[e][i].size() - 1, B[i][x] + value);
							if (e == k)
								_min = min(_min, B[i][x] + value);
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
	for (int e = 0; e < k + 1; e++) {
		sp.push_back(vector<vector<vnv> >());
		for (int i = 0; i < n + 1; i++)
			sp[e].push_back(vector<vnv>());
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
