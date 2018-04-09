#include <bits/stdc++.h>
using namespace std;
#define unsigned long MAX=1000000007;
int N, *a;
unsigned
long long S = 0;
void initialize() {
	scanf("%d", &N);
	a = new int[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		S += a[i];
	}
}
int main() {
	initialize();
	printf("%i", S % MAX);
	return 0;
}
