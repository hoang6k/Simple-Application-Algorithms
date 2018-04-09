#include <bits/stdc++.h>
using namespace std;
long long N, *t;
long long PTrees() {
	long long i = -1, max = 0;
	while (++i < N) {
		t[i] += i + 1;
		max = max > t[i] ? max : t[i];
	}
	return max;
}
void initialize() {
	scanf("%lli", &N);
	t = new long long[N];
	long long i = -1;
	while (++i < N)
		scanf("%lli", &t[i]);
	sort(t, t + N, std::greater<long long>());
}
int main() {
	initialize();
	printf("%lli", PTrees() + 1);
	return 0;
}
