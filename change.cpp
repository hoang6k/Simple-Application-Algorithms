#include <bits/stdc++.h>
using namespace std;
int N, result = 0;
int main() {
	scanf("%d", &N);
	N = 1000 - N;
	while (N > 0) {
		if (N >= 500) {
			N -= 500;
			result;
		} else if (N >= 100) {
			N -= 100;
			result;
		} else if (N >= 50) {
			N -= 50;
			result;
		} else if (N >= 10) {
			N -= 10;
			result;
		} else if (N >= 5) {
			N -= 5;
			result;
		} else if (N >= 1) {
			N -= 1;
			result;
		}
	}
	printf("%d", result);
	return 0;
}
