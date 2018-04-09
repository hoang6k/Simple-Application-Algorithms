#include <bits/stdc++.h>
using namespace std;
int n, _count0, _count1, *a, *N, *H;
void hamdist(int x, int k) {
	for (int i = 0 + _count0 / (N[x] - H[x]); i <= 1 - _count1 / H[x]; i++) {
		if (i)
			_count1++;
		else
			_count0++;
		a[k] = i;
//		printf("\n  a[%d] = %d", k, i);
		if (k < N[x] - 1) {
			hamdist(x, k + 1);
			if (i)
				_count1--;
			else
				_count0--;
		} else {
			for (int j = 0; j < N[x]; j++)
				printf("%d", a[j]);
			printf("\n");
			if (i)
				_count1--;
			else
				_count0--;
		}
	}
}
void initialize() {
	scanf("%d", &n);
	N = new int[n];
	H = new int[n];
	for (int i = 0; i < n; i++)
		scanf("%d %d", &N[i], &H[i]);
//	for (int i = 0; i < n; i++)
//		printf("\n%d %d", N[i], H[i]);
}
int main() {
	initialize();
	for (int x = 0; x < n; x++) {
		_count0 = 0;
		_count1 = 0;
		a = new int[N[x]];
		if (N[x] == H[x]) {
			for (int i = 0; i < N[x]; i++)
				printf("1");
			printf("\n");
		} else if (H[x] == 0) {
			for (int i = 0; i < N[x]; i++)
				printf("0");
			printf("\n");
		}
		else hamdist(x, 0);
		printf("\n");
	}
	return 0;
}
