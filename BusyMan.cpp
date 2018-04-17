#include<bits/stdc++.h>
using namespace std;
#define MAXT 10
#define MAXN 100000
int T;
int N, start[MAXN] = { }, _end[MAXN] = { }, result[MAXT] = { }, _max, _count;
int partition(int low, int high) {
	int pivot = _end[high];
	int i = low - 1;
	int temp;
	for (int j = low; j <= high - 1; j++) {
		if (_end[j] <= pivot) {
			i++;
			temp = _end[i];
			_end[i] = _end[j];
			_end[j] = temp;
			temp = start[i];
			start[i] = start[j];
			start[j] = temp;
		}
	}
	temp = _end[i + 1];
	_end[i + 1] = _end[high];
	_end[high] = temp;
	temp = start[i + 1];
	start[i + 1] = start[high];
	start[high] = temp;
	return (i + 1);
}
void quickSort(int low, int high) {
	if (low < high) {
		int pi = partition(low, high);
		quickSort(low, pi - 1);
		quickSort(pi + 1, high);
	}
}
void busyman(int k) {
	for (int i = k + 1; i <= N; i++)
		if (start[i] >= _end[k]) {
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
		_count = _max = 0;
		scanf("%d", &N);
		for (int j = 1; j <= N; j++)
			scanf("%d %d", &start[j], &_end[j]);
		quickSort(1, N);
		busyman(0);
		result[i] = _max;
	}
	i = -1;
	while (++i < T)
		printf("%d\n", result[i]);
	return 0;
}
