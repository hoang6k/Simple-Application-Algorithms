#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001
int T, n, L1, L2, a[MAXN] = { }, S[MAXN] = { }/*, result[MAXN] = { }*/;
void gold(int k) {
	int _max = 0;
	for (int i = max(1, k - L2); i <= k - L1; i++) {
		_max = max(S[i], _max);
	}
	S[k] = _max + a[k];
	if (k < n)
		gold(k + 1);
	return;
}
int main() {
//	int i = -1;
//	scanf("%d", &T);
//	while (++i < T) {
		scanf("%d %d %d", &n, &L1, &L2);
		int j = 0;
		while (j++ < n) {
			scanf("%d", &a[j]);
			if (j <= L1)
				S[j] = a[j];
		}
		gold(L1 + 1);
		int _max = 0;
		j = 0;
		while (j++ < n)
			_max = max(S[j], _max);
		printf("%d",_max);
//		result[i] = _max;
//	}
//	i = -1;
//	while (++i < T)
//		printf("%d\n", result[i]);
	return 0;
}
