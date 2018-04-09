#include <bits/stdc++.h>
using namespace std;
#define MAXN 35
typedef long long LL;
int n, b, bk;
int c[MAXN] = { }, a[MAXN] = { }, x[MAXN] = { };
LL fopt = -1, fk = 0;

void branch(int k) {
	for (int y = min(1, bk / a[k]); y >= 0; y--) {
		x[k] = y;
		bk -= y * a[k];
		fk += y * c[k];
		if (k == n)
			fopt = max(fk, fopt);
		else if (fk + bk * c[k + 1] * 1. / a[k + 1] > fopt)
			branch(k + 1);
		bk += y * a[k];
		fk -= y * c[k];
	}
}
void swap(int i, int j) {
	int temp = c[i];
	c[i] = c[j];
	c[j] = temp;
	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
void initialize() {
	cin >> n >> b;
	bk = b;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> c[i];
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if (c[i] * 1. / a[i] < c[j] * 1. / a[j])
				swap(i, j);
}
int main() {
	initialize();
	branch(1);
	cout << fopt;
	return 0;
}
