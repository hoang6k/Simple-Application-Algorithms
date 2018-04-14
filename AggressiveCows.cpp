#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001
int t, N, C, x[MAXN] = { }, _min = MAXN, _max;
queue<int> result;
int main() {
	scanf("%d", &t);
	int i = -1;
	while (++i < t) {
		scanf("%d %d", &N, &C);
		int j = -1, temp = x[0];
		while (++j < N)
			scanf("%d", &x[j]);
		sort(x, x + N, std::less<int>());
//		for (int k = 0; k < N; k++)
//			printf("sort %d\n", x[k]);
		_max = (x[N - 1] - x[0]) / (C - 1);
		j = 0;
		while (++j < N) {
			_min = min(_min, x[j] - temp);
			temp = x[j];
		}
//		printf("min=%d, max=%d\n", _min, _max);
		int count, xlast, avg;
		while (_max - _min > 2) {
			count = 1;
			xlast = x[0];
			avg = (_min + _max) / 2;
//			printf("min=%d, max=%d, avg=%d", _min, _max, avg);
			for (int i = 1; i < N; i++) {
				int temp = x[i];
				if (temp - xlast >= avg) {
					count++;
					xlast = temp;
				}
			}
			if (count < C)
				_max = avg;
			else
				_min = avg;
		}
		int k;
		for (k = _max; k >= _min; k--) {
			count = 1;
			xlast = x[0];
			for (int i = 1; i < N; i++) {
				int temp = x[i];
				if (temp - xlast >= k) {
					count++;
					xlast = temp;
				}
			}
			if (count >= C)
				break;
		}
		result.push(k);
	}
	while (!result.empty()) {
		printf("%d\n", result.front());
		result.pop();
	}
	return 0;
}
