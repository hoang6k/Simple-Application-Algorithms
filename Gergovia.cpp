#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001
int n, a[MAXN] = { };
queue<int> neg, pos, result;
int main() {
	do {
		scanf("%d", &n);
		if (!n)
			break;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			if (a[i] < 0)
				neg.push(i);
			else if (a[i] > 0)
				pos.push(i);
		}
		int cost = 0;
		while (!neg.empty()) {
			int subt = neg.front(), plus = pos.front();
			if (a[subt] + a[plus] == 0) {
				cost += a[plus] * abs(plus - subt);
				neg.pop();
				pos.pop();
			} else if (a[subt] + a[plus] > 0) {
				cost -= a[subt] * abs(plus - subt);
				a[plus] += a[subt];
				neg.pop();
			} else {
				cost += a[plus] * abs(plus - subt);
				a[subt] += a[plus];
				pos.pop();
			}
		}
		result.push(cost);
	} while (1);
	while (!result.empty()) {
		printf("%d\n", result.front());
		result.pop();
	}
	return 0;
}
