#include<bits/stdc++.h>
using namespace std;
#define MAXT 10
#define MAXN 100000
int T;
int N, start[MAXN], _end[MAXN], ix[MAXN], result[MAXT], _count;
//template<typename _Tp>
struct indexless: public binary_function<int, int, bool> {
	bool operator()(const int& _x, const int& _y) const {
		return _end[_x] < _end[_y];
	}
};
void busyman(int k) {
	for (int i = k + 1; i < N; i++)
		if (start[ix[i]] >= _end[ix[k]]) {
			_count++;
			if (i < N - 1)
				busyman(i);
			return;
		}
}
int main() {
	scanf("%d", &T);
	int i = -1;
	while (++i < T) {
		_count = 1;
		scanf("%d", &N);
		for (int j = 0; j < N; j++)
			ix[j] = j;
		for (int j = 0; j < N; j++)
			scanf("%d %d", &start[j], &_end[j]);
		sort(ix, ix + N, indexless());
		busyman(0);
		result[i] = _count;
	}
	i = -1;
	while (++i < T)
		printf("%d\n", result[i]);
	return 0;
}
