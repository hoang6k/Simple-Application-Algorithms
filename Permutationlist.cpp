#include <bits/stdc++.h>
using namespace std;
int n, k;
int *a;
int factorial(int x) {
	if (x == 0)
		return 1;
	int i;
	int f = 1;
	for (i = 1; i < x + 1; i++) {
		f *= i;
	}
	return f;
}
int check(int x) {
	if (x == 1)
		return 0;
	int i = 1;
	while (!((factorial(i) < x) && (x < factorial(i + 1) + 1))) {
		i++;
	}
	return i + 1;
}
void permutation() {
	if (n < 13 && factorial(n) < k) {
		cout << -1;
		return;
	}
	int i, num, temp, limit;
	int a[n];
	for (i = 1; i < n + 1; i++)
		a[i] = i;
	while (k > 1) {
		limit = check(k);
		num = (k - 1) / factorial(limit - 1);
		k -= num * factorial(limit - 1);
		temp = a[n - limit + 1 + num];
		for (i = n - limit + 1 + num; i > n - limit + 1; i--)
			a[i] = a[i - 1];
		a[n - limit + 1] = temp;
	}
	for (i = 1; i < n; i++)
		printf("%d ", a[i]);
	cout << a[n];
	return;
}
int main() {
	cin >> n >> k;
	permutation();
	return 0;
}
