#include<bits/stdc++.h>
using namespace std;
#define MAXT 10
#define MAXN 100000
int T;
int N, start[MAXN] = { }, _end[MAXN] = { }, ix[MAXN] = { }, result[MAXT] = { },
		_max, _count;
template<typename _Tp>
struct indexless: public binary_function<_Tp, _Tp, bool> {
	bool operator()(const _Tp& _x, const _Tp& _y) const {
		return _end[_x] < _end[_y];
	}
};
void busyman(int k) {
	for (int i = k + 1; i <= N; i++)
		if (start[ix[i]] >= _end[ix[k]]) {
			_count++;
			_max = max(_max, _count);
			if (i < N)
				busyman(i);
			_count--;
		}
}
int main() {
	scanf("%d", &T);
	int i = -1;
	while (++i < T) {
		_count = 0;
		_max = 0;
		scanf("%d", &N);
		for (int j = 1; j <= N; j++)
			ix[j] = j;
		for (int j = 1; j <= N; j++)
			scanf("%d %d", &start[j], &_end[j]);
		sort(ix + 1, ix + N + 1, indexless<int>());
		busyman(0);
		result[i] = _max;
	}
	i = -1;
	while (++i < T)
		printf("%d\n", result[i]);
	return 0;
}
