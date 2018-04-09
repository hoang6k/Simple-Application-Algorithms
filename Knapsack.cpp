#include <bits/stdc++.h>
using namespace std;
int n, b, g, bk, a[35] = { }, c[35] = { };
long fcur = 0, fopt = 0;
void knapsack(int k) {
	for (int i = min(1, bk / a[k]); i >= 0; i--) {
		fcur += i * c[k];
		bk -= i * a[k];
		if (k == n - 1)
			fopt = max(fopt, fcur);
		else if (fcur + bk * (float) c[k + 1] / a[k + 1] > fopt)
			knapsack(k + 1);
		fcur -= i * c[k];
		bk += i * a[k];
	}
}
void swap(int i, int j) {
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
	temp = c[i];
	c[i] = c[j];
	c[j] = temp;
}
void initialize() {
	cin >> n >> b;
	bk = b;
	for (int i = 0; i < n; i++)
		cin >> a[i] >> c[i];
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if ((float) c[i] / a[i] < (float) c[j] / a[j])
				swap(i, j);
//	for (int i = 0; i < n; i++)
//		cout << (float) c[i] / a[i] << " ";
//	cout << endl;
}
int main() {
	initialize();
	knapsack(0);
	cout << fopt;
	return 0;
}
