#include <bits/stdc++.h>
using namespace std;
int T, t, N, *result, i = -1;
int main() {
	scanf("%d", &T);
	t = T;
	result = new int[T];
	while (T-- > 0) {
		result[++i] = 0;
		scanf("%d", &N);
		N = 1000 - N;
		while (N > 0) {
			if (N >= 500) {
				N -= 500;
				result[i]++;
			} else if (N >= 100) {
				N -= 100;
				result[i]++;
			} else if (N >= 50) {
				N -= 50;
				result[i]++;
			} else if (N >= 10) {
				N -= 10;
				result[i]++;
			} else if (N >= 5) {
				N -= 5;
				result[i]++;
			} else if (N >= 1) {
				N -= 1;
				result[i]++;
			}
		}
	}
	for (int j = 0; j < t; j++)
		printf("%d\n", result[j]);
	return 0;
}
