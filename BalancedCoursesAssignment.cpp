#include <bits/stdc++.h>
using namespace std;
int m, n, amount, flag = 0, check_opt = 0, _min = 100;
int **A, *a, *b;
vector<int> sorted;
vector<vector<int> > cols;
vector<vector<int> > rows;
bool conflict(int k) {
	int i = 1, r = 1;
	while (i++ <= amount)
		if (b[i] == rows[k].back())
			for (unsigned int j = 0; j < rows[k].size(); j++)
				if (rows[k][j] == a[i])
					return true;
	while (r++ <= amount)
		if (a[r] == rows[k].back())
			for (unsigned int s = 0; s < rows[k].size(); s++)
				if (rows[k][s] == b[r])
					return true;
	return false;
}
int conclude() {
	unsigned int max = 0;
	for (int i = 1; i < m + 1; i++)
		if (rows[i].size() > max)
			max = rows[i].size();
	return max;
}
void BCA(int k) {
	for (unsigned int i = 0; i < cols[sorted[k]].size(); i++) {
		rows[cols[sorted[k]][i]].push_back(sorted[k]);
		if (conclude() > _min || conflict(cols[sorted[k]][i]))
			rows[cols[sorted[k]][i]].pop_back();
		else {
			if (k < n - 1) {
				BCA(k + 1);
				if (check_opt)
					return;
				rows[cols[sorted[k]][i]].pop_back();
			} else {
//				printf("\nket qua moi:");
//				for (int u = 1; u < m + 1; u++) {
//					printf("\n");
//					for (unsigned int v = 0; v < rows[u].size(); v++)
//						printf(" %d", rows[u][v]);
//				}
//				printf("\n");
				flag = 1;
				_min = _min < conclude() ? _min : conclude();
				if (_min == (n + m - 1) / m)
					check_opt = 1;
				rows[cols[sorted[k]][i]].pop_back();
			}
		}
	}
}
bool check_exist(int i, int k) {
	for (int j = 1; j < A[i][0] + 1; j++)
		if (A[i][j] == k)
			return true;
	return false;
}
void capacity(int k) {
	for (int i = 1; i < m + 1; i++)
		if (check_exist(i, k))
			cols[k].push_back(i);
}
void initialize() {
	int temp;
	scanf("%d %d", &m, &n);
	A = new int*[m + 1];
	for (int i = 0; i < n + 1; i++)
		cols.push_back(vector<int>());
	for (int i = 0; i < m + 1; i++)
		rows.push_back(vector<int>());
	for (int i = 1; i < m + 1; i++) {
		scanf("%d", &temp);
		A[i] = new int[temp + 1];
		A[i][0] = temp;
		for (int j = 1; j < A[i][0] + 1; j++)
			scanf("%d", &A[i][j]);
	}
	for (int k = 1; k < n + 1; k++)
		capacity(k);
	for (int i = 1; i < m + 1; i++)
		for (int j = 1; j < n + 1; j++)
			if (cols[j].size() == (unsigned) i)
				sorted.push_back(j);
	scanf("%d", &amount);
	a = new int[amount + 1];
	b = new int[amount + 1];
	for (int i = 1; i < amount + 1; i++) {
		scanf("%d", &a[i]);
		scanf("%d", &b[i]);
	}
}
int main() {
	initialize();
	BCA(0);
	if (flag)
		printf("%d", _min);
	else
		printf("-1");
	return 0;
}
