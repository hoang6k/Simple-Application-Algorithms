#include<bits/stdc++.h>
using namespace std;
int T, r = 0, s = 0, flag = 0;
int A[9][9];
queue<int> result;
bool checkrow(int i) {
	for (int j = 2; j < 9; j++)
		for (int k = j - 1; k > 0; k--) {
			if (A[i][k] == 0)
				continue;
			else if (A[i][k] == A[i][j])
				return false;
		}
	return true;
}
bool checkcol(int j) {
	for (int i = 2; i < 9; i++)
		for (int k = i - 1; k > 0; k--) {
			if (A[k][j] == 0)
				continue;
			else if (A[k][j] == A[i][j])
				return false;
		}
	return true;
}
bool checkgrid(int grid) {
	int x, y, count[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	switch (grid) {
	case 1:
		x = y = 0;
		break;
	case 2:
		x = 0;
		y = 4;
		break;
	case 3:
		x = 4;
		y = 0;
		break;
	case 4:
		x = y = 4;
		break;
	}
	for (int i = 1 + x; i < 5 + x; i++)
		for (int j = 1 + y; j < 5 + y; j++) {
			if (A[i][j] == 0)
				continue;
			if (++count[A[i][j]] > 2)
				return false;
		}
	return true;
}
bool checkgrid(int u, int v) {
	int x = 0, y = 0, count[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	if (u > 4)
		x = 4;
	if (v > 5)
		y = 4;
	for (int i = 1 + x; i < 5 + x; i++)
		for (int j = 1 + y; j < 5 + y; j++) {
			if (A[i][j] == 0)
				continue;
			if (++count[A[i][j]] > 2)
				return false;
		}
	return true;
}
bool checkrows() {
	for (int i = 1; i < 9; i++)
		if (!checkrow(i))
			return false;
	return true;
}
bool checkcols() {
	for (int j = 1; j < 9; j++)
		if (!checkcol(j))
			return false;
	return true;
}
bool checkgrids() {
	for (int x = 1; x < 5; x++) {
		if (!checkgrid(x))
			return false;
	}
	return true;
}
bool valid() {
	if (!checkrows() || !checkcols() || !checkgrids())
		return false;
	return true;
}
bool checkempty() {
	for (int i = 1; i < 9; i++)
		for (int j = 1; j < 9; j++) {
			if (A[i][j] == 0) {
				r = i;
				s = j;
				return 1;
			}
		}
	r = 0;
	s = 0;
	return 0;
}
void fill(int x, int y) {
	for (int i = 1; i < 9; i++) {
		A[x][y] = i;
		if (!checkrow(x) || !checkcol(y) || !checkgrid(x, y)) {
			A[x][y] = 0;
			continue;
		} else {
			if (checkempty()) {
				fill(r, s);
				if (flag == 1)
					return;
				else
					A[x][y] = 0;
			} else {
				flag = 1;
				return;
			}
		}

	}
}
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		for (int j = 1; j < 9; j++) {
			for (int k = 1; k < 9; k++)
				scanf("%d", &A[j][k]);
		}
		if (!valid())
			result.push(-1);
		else {
			if (checkempty())
				fill(r, s);
			if (!valid() || checkempty())
				result.push(-1);
			else
				for (int u = 1; u < 9; u++)
					for (int v = 1; v < 9; v++)
						result.push(A[u][v]);
		}
		flag = 0;
	}
	int count = 0;
	while (!result.empty()) {
		printf("Test case #%d: ", ++count);
		if (result.front() == -1) {
			printf("NO");
			result.pop();
		} else {
			printf("YES\n");
			for (int i = 1; i < 9; i++) {
				for (int j = 1; j < 8; j++) {
					printf("%d ", result.front());
					result.pop();
				}
				if (i < 8)
					printf("%d\n", result.front());
				else
					printf("%d", result.front());
				result.pop();
			}
		}
		if (!result.empty())
			printf("\n");
	}
	return 0;
}
