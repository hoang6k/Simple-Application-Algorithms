#include <bits/stdc++.h>
#define MAXN 31
using namespace std;
int n, h[MAXN] = { }, a[MAXN] = { }, _count = 0;
void initialize() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &h[i], &a[i]);
}
int main() {
	initialize();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i == j)
				continue;
			else if (h[i] == a[j])
				_count++;
		}
	printf("%d", _count);
	return 0;
}
