#include <bits/stdc++.h>
using namespace std;
//int n, k, a[10005] = { };
//long result = -1;
int main() {
	int n, k, temp, a[10000005] = { };
	long result = -1, sum = 0;
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		cin >> temp;
		a[i] = temp;
	}
	a[0] = 0;
	for (int i = 1; i < k; i++)
		sum += a[i];
//	result = result > sum ? result : sum;
//	printf("\nsum = %li\n", sum);
	for (int i = k; i <= n; i++) {
//		printf("sum + %d - %d", a[i], a[i - k]);
		sum = sum - a[i - k] + a[i];
//		printf(" = %li\n", sum);
		if (sum > result)
			result = sum;
	}
	cout << result;
	return 0;
}
