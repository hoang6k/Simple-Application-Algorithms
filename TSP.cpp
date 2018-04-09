#include<bits/stdc++.h>
using namespace std;
int n, m, cost = 0, minCost = 1000000;
int **A;
bool *a, *b;
stack<int> route;
bool checkinf(int i, int j) {
	if (A[i][j] == 1000000)
		return 0;
	else
		return 1;
}
void TSP(int i) {
	for (int j = 2; j < n + 1; j++) {
		if ((i != j) && (b[j] && checkinf(i, j))) {
			if (minCost < cost + A[i][j])
				continue;
			b[j] = 0;
			route.push(j);
			cost += A[i][j];
			if (route.size() < n)
				TSP(j);
			else {
				cost += A[j][1];
				if (cost < minCost) {
					minCost = cost;
				}
				cost -= A[j][1];
			}
			b[j] = 1;
			route.pop();
			cost -= A[i][j];
		}
	}
}
int main() {
	scanf("%d %d", &n, &m);
	A = new int*[n + 1];
	for (int i = 1; i < n + 1; i++) {
		A[i] = new int[n + 1];
		for (int j = 1; j < n + 1; j++)
			A[i][j] = 1000000;
	}
	for (int i = 0; i < m; i++) {
		int from, to;
		scanf("%d", &from);
		scanf("%d", &to);
		scanf("%d", &A[from][to]);
	}
	a = new bool[n + 1];
	b = new bool[n + 1];
	for (int i = 1; i < n + 1; i++) {
		a[i] = 1;
		b[i] = 1;
	}
	route.push(1);
	TSP(1);
	printf("%d", minCost);
//	for (int i = 0; i < n + 1; i++)
//		delete[] A[i];
//	delete[] A;
//	delete[] a,b;
	return 0;
}
