#include <bits/stdc++.h>
#define MAXN 1000001
using namespace std;
int N, M, a[MAXN] = { }, _min, _max, avg;
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	sort(a, a + N, less<int>());
	_min = 0;
	_max = N - 1;
//	cout << "min = " << _min << ", max = " << _max << endl;
	while (_max - _min > 1) {
		avg = (_min + _max) / 2;
//		cout << "min = " << _min << ", max = " << _max << ", avg=" << avg
//				<< endl;
		long long _M = 0;
		for (int i = N - 1; i > avg; i--) {
			int temp = a[avg];
			if (a[i] > temp)
				_M += a[i] - temp;
			if (_M > M)
				break;
		}
		if (_M > M) {
			_min = avg;
		} else if (_M < M)
			_max = avg;
		else {
			printf("%d", a[avg]);
			return 0;
		}
	}
	int temp = _min;
	_min = a[_min];
	_max = a[_max];
//	cout << "min = " << _min << ", max = " << _max << endl;
	while (_max - _min > 1) {
		avg = (_min + _max) / 2;
//		cout << "min = " << _min << ", max = " << _max << ", avg=" << avg
//				<< endl;
		long long _M = 0;
		for (int i = N - 1; i >= temp; i--) {
			if (a[i] > avg)
				_M += a[i] - avg;
			if (_M > M)
				break;
		}
//		cout << "_M=" << _M << ", M=" << M << endl;
		if (_M > M) {
			_min = avg;
		} else if (_M < M)
			_max = avg;
		else {
			printf("%d", avg);
			return 0;
		}
	}
	if (_max - _min)
		avg = _min;
	printf("%d", avg);
	return 0;
}
