#include <bits/stdc++.h>
using namespace std;
int H, W, N, res = 0, h[13] = { }, w[13] = { }, busy[31][31] = { };
int check(int i, int j, int k) {
	for (int u = i; u < i + w[k]; u++)
		for (int v = j; v < j + h[k]; v++)
			if (busy[u][v])
				return 0;
	return 1;
}
void mark(int i, int j, int k, int val) {
	for (int u = i; u < i + w[k]; u++)
		for (int v = j; v < j + h[k]; v++)
			busy[u][v] = val;
}
void TRY(int k) {
	if (res)
		return;
	for (int i = 0; i <= W - w[k]; i++)
		for (int j = 0; j <= H - h[k]; j++) {
			if (check(i, j, k)) {
				//neu co the dat hcn thu k tai vi tri i,j
				mark(i, j, k, 1); //danh dau tat ca vung nay bang 1
				if (k == N)
					res = 1;
				else
					TRY(k + 1);
				mark(i, j, k, 0);
			}
		}
}
void initialize() {
	scanf("%d %d %d", &H, &W, &N);
	for (int i = 1; i < N + 1; i++)
		scanf("%d %d", &h[i], &w[i]);
}
int main() {
	initialize();
	TRY(1);
	cout << res << endl;
	return 0;
}
