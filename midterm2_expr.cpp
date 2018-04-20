#include <bits/stdc++.h>
using namespace std;
int n, b, a[31] = { }, s = 0, _count = 0, sum = 0;
void bloper(int k) {
	if (k < n) {
		if (!k) {
			s += a[k];
			sum -= a[k];
//			printf("\n s + %d = %d", a[k], s);
			bloper(k + 1);
		} else {
			if (k < n - 1 && (s + a[k] - (sum - a[k])) > b) {
//				printf("\n k = %d < %d & s+a[%d]=%d ~=%d", k, n - 1, k,
//						s + a[k], s + a[k] - a[k + 1] * (n - k - 1));
				if (k < n - 1 && (s - a[k] + (sum - a[k])) < b) {
//					printf("\n k = %d < %d & s-a[%d]=%d ~=%d", k, n - 1, k,
//							s - a[k], s - a[k] + a[k + 1] * (n - k - 1));
					return;
				}
				s -= a[k];
				sum -= a[k];
//				printf("\n s - %d = %d", a[k], s);
				bloper(k + 1);
				s += a[k];
				sum += a[k];
			} else {
				s += a[k];
				sum -= a[k];
//				printf("\n s + %d = %d", a[k], s);
				bloper(k + 1);
				s -= 2 * a[k];
//				printf("\n s - %d = %d", a[k], s);
				bloper(k + 1);
				s += a[k];
				sum += a[k];
			}
		}
	} else if (k == n) {
		if (s == b)
			_count++;
	}

//	long s = n * (n + 1) / 2;
//	if ((b + s) % 2) {
//		return 0;
//	} else if ((b > s) || (b < 2 - s) || (b == s - 2) || (b == 4 - s)) {
//		return 0;
//	}
//	return 1;
}
void initialize() {
	scanf("%d %d", &n, &b);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	sort(a + 1, a + n, greater<int>());
//	for (int i = 0; i < n; i++)
//		printf("%d ", a[i]);
//	printf("\n");
}
int main() {
	initialize();
	bloper(0);
	printf("%d", _count);
	return 0;
}
