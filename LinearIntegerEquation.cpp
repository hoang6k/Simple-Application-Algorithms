#include<bits/stdc++.h>
using namespace std;
int n, M;
int *a;
void print_sol() {
	for (int i = 1; i < n; i++)
		cout << a[i] + 1 << " ";
	cout << a[n] + 1 << endl;
}
void Try(int k) {
	int res = M;
	for (int i = 1; i < k; i++)
		res -= a[i];
	if (k == n) {
		a[k] = res;
		print_sol();
		return;
	} else
		for (int y = 0; y <= res; y++) {
			a[k] = y;
			Try(k + 1);
		}
}
int main() {
	cin >> n >> M;
	M -= n;
	a = new int[n + 1];
	Try(1);
	return 0;
}
