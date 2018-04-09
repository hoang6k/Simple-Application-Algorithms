#include <bits/stdc++.h>
using namespace std;
int n, L1, L2, sum = 0, _max = -100000, a[1000001] = { };
int main() {
	scanf("%d %d %d", &n, &L1, &L2);
	int k = -1;
	while (++k < n)
		scanf("%d", &a[k + 1]);
	for (int i = 1; i <= n - L1 + 1; i++) {
		sum = 0;
		int j = 0;
		while (j++ < L1)
			sum += a[i + j - 1];
		do {
			_max = _max > sum ? _max : sum;
			if (i + j - 1 > n)
				break;
			sum += a[i + j - 1];
		} while (j++ <= L2);
	}
	printf("%d", _max);
	return 0;
}
