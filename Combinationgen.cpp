#include<bits/stdc++.h>
using namespace std;
int m, n, check = 0;
int *a;
void combinationgen() {
	int i = m;
	while (a[i] == n - m + i) {
		i--;
		if (i == 0)
			return;
	}
	check++;
	a[i]++;
	for (int j = i + 1; j < m + 1; j++)
		a[j] = a[j - 1] + 1;
}
int main() {
	cin >> n >> m;
	a = new int[m + 1];
	for (int i = 1; i < m + 1; i++)
		scanf("%d", &a[i]);
	combinationgen();
	if (check) {
		for (int i = 1; i < m; i++)
			printf("%d ", a[i]);
		cout << a[m];
	} else
		cout << -1;
	return 0;
}
