#include<bits/stdc++.h>
using namespace std;
int n, check = 0;
int *a;
void permutationgen() {
	int j = n;
	while (a[j] > a[j + 1])
		j = j - 1;
	if (j == 0)
		return;
	check = 1;
	int k = n;
	while (a[j] > a[k])
		k--;
	a[0] = a[j];
	a[j] = a[k];
	a[k] = a[0];
	for (int r = j + 1, s = n; r < s; r++, s--) {
		a[0] = a[r];
		a[r] = a[s];
		a[s] = a[0];
	}
}
int main() {
	cin >> n;
	a = new int[n + 1];
	a[0] = 0;
	for (int i = 1; i < n + 1; i++) {
		scanf("%d", &a[i]);
	}
	permutationgen();
	if (!check)
		cout << -1;
	else {
		for (int i = 1; i < n; i++)
			printf("%d ", a[i]);
		printf("%d", a[n]);
	}
	return 0;
}
