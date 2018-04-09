#include<bits/stdc++.h>
using namespace std;
int N, M, _count;
int *x, *y;
bool *a, *b, *c;
bool checkhole(int i, int j) {
	for (int k = 0; k < M; k++) {
		if (x[k] == i + 1 && y[k] == j + 1)
			return false;
	}
	return true;
}
int holeyqueens(int i) {
	for (int j = 0; j < N; j++) {
		if (a[j] && b[i + j] && c[i - j + N - 1] && checkhole(i, j)) {
			a[j] = false;
			b[i + j] = false;
			c[i - j + N - 1] = false;
			if (i < N - 1)
				holeyqueens(i + 1);
			else
				_count++;
			a[j] = true;
			b[i + j] = true;
			c[i - j + N - 1] = true;
		}
	}
	return _count;
}
int main() {
	queue<int> result;
	do {
		_count = 0;
		scanf("%d", &N);
		scanf("%d", &M);
		if (N == 0 && M == 0)
			break;
		x = new int[M];
		y = new int[M];
		a = new bool[N];
		b = new bool[2 * N - 1];
		c = new bool[2 * N - 1];
		for (int i = 0; i < M; i++) {
			scanf("%d", &x[i]);
			scanf("%d", &y[i]);
		}
		for (int i = 0; i < N; i++)
			a[i] = true;
		for (int i = 0; i < 2 * N - 1; i++) {
			b[i] = true;
			c[i] = true;
		}
		result.push(holeyqueens(0));
	} while (true);
	while (!result.empty()){
		printf("%d\n",result.front());
		result.pop();
	}
	return 0;
}
