#include <bits/stdc++.h>
#define MAXN 100001
#define MOD 1000000007
using namespace std;
long long n, a[MAXN], b[MAXN];
vector<long long> newa, newb;
void initialize() {
	scanf("%lli", &n);
	for (long i = 0; i < n; i++)
		scanf("%lli", &a[i]);
	for (long i = 1; i < n; i++)
		scanf("%lli", &b[i]);
}
int main() {
	initialize();
	for (long i = 0; i < n;) {
//		printf("\n i = %d", i);
		long j = i + 1;
		if (b[j] == 0 || b[j] == 1) {
//			printf("\n day vao a[%d]=%d", i, a[i]);
			newa.push_back(a[i]);
			if (i == n - 1)
				break;
//			printf(", b[%d]=%d\n", j, b[j]);
			newb.push_back(b[j]);
			i++;
		} else {
			long count = 1;
			while (b[j] == 2) {
				a[i] *= a[j];
//				a[i] = a[i] % MOD;
				j++;
				count++;
			}
//			printf("\n day vao a[%d] %d, b[%d] %d\n", i, a[i], j, b[j]);
			newa.push_back(a[i]);
			newb.push_back(b[j]);
			i += count;
		}
	}
//	printf("\n");
//	for (long i = 0; i < (long) newa.size(); i++)
//		printf("%lli ", newa[i]);
//	printf("\n");
//	for (long i = 0; i < (long) newb.size(); i++)
//		printf("%lli ", newb[i]);
//	printf("\n");
//	for (int i = 0; i < (int) newa.size(); i++)
//		newa[i] = newa[i] % MOD;
	long long sum = newa[0];
	for (long i = 0; i < (long) newa.size() - 1; i++) {
		if (newb[i] == 0) {
			sum -= newa[i + 1];
//			printf("\nsum - %d =%d", newa[i + 1], sum);
		} else {
			sum += newa[i + 1];
//			printf("\nsum + %d =%d", newa[i + 1], sum);
		}
	}
	while (sum < 0)
		sum += MOD;
	printf("%lli", sum % MOD);
	return 0;
}
