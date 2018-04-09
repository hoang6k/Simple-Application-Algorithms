#include <bits/stdc++.h>
using namespace std;
int N, M, cost = 0, _count = 1, dem = 0, _min = 1000000, **A;
bool *cols;
void tsp(int i) {
	for (int j = 1; j < N; j++) {
		if (cols[j] && i != j) {
			if (cost + A[i][j] + _min * (N - _count) > M)
				continue;
			cols[j] = 0;
			_count++;
			cost += A[i][j];
			if (_count < N)
				tsp(j);
			else {
				cost += A[j][0];
				if (cost <= M)
					dem++;
				cost -= A[j][0];
			}
			cols[j] = 1;
			_count--;
			cost -= A[i][j];
		}
	}
}
void initialize() {
	scanf("%d %d", &N, &M);
	cols = new bool[N];
	cols[0] = 0;
	for (int i = 1; i < N; i++)
		cols[i] = 1;
	A = new int*[N];
	for (int i = 0; i < N; i++) {
		A[i] = new int[N];
		for (int j = 0; j < N; j++) {
			scanf("%d", &A[i][j]);
			if ((i != j) && (A[i][j] < _min))
				_min = A[i][j];
		}
	}
}
int main() {
	initialize();
	tsp(0);
	printf("%d", dem);
	return 0;
}
