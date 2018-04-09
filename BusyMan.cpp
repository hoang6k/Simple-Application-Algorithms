#include<bits/stdc++.h>
using namespace std;
#define MAXT 10
#define MAXN 100000
int T;
unsigned long N, start[MAXN] = { }, end[MAXN] = { }, ix[MAXN] = { },
		result[MAXT] = { }, _max, _count;
template<typename _Tp>
struct indexless: public binary_function<_Tp, _Tp, bool> {
	bool operator()(const _Tp& _x, const _Tp& _y) const {
		return end[_x] < end[_y];
	}
};
void busyman(unsigned long k) {
	for (unsigned long i = k + 1; i <= N; i++)
		if (start[ix[i]] >= end[ix[k]]) {
			_count++;
			_max = _max > _count ? _max : _count;
			if (i < N)
				busyman(i);
			_count--;
		}
}
int main() {
	scanf("%d", &T);
	int i = -1;
	while (++i < T) {
		_count = _max = 0;
		scanf("%lu", &N);
		for (unsigned long j = 1; j <= N; j++)
			ix[j] = j;
		for (unsigned long j = 1; j <= N; j++)
			scanf("%lu%lu", &start[j], &end[j]);
		sort(ix + 1, ix + N + 1, indexless<unsigned long>());
		busyman(0);
		result[i] = _max;
	}
	i = -1;
	while (++i < T)
		printf("%lu\n", result[i]);
	return 0;
}
