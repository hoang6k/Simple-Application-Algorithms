#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int N, K1, K2, s0[1001] = { }, s1[1001] = { };
int nurse() {
	s0[0] = s0[1] = 1;
	for (int i = K1; i <= N; i++) {
		s0[i] = s1[i - 1];
		for (int j = K1; j <= max(0, min(N, K2)); j++)
			s1[i] = (s1[i] + s0[i - j]) % MOD;
	}
	return (s0[N] + s1[N]) % MOD;
}
int main() {
	scanf("%d %d %d", &N, &K1, &K2);
//	for (int i = 1; i < 10; i++)
//		printf("%d ", s0[-i]);
	printf("%d", nurse());
	return 0;
}
