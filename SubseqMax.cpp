#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000001
int a[MAXN], s[MAXN], n;
void subsequence() {
	int i = 0;
	s[0] = a[0];
	int _max = s[0];
	for (i = 1; i < n; i++) {
		if (s[i - 1] > 0)
			s[i] = s[i - 1] + a[i];
		else
			s[i] = a[i];
		_max = max(_max, s[i]);
	}
	printf("%d", _max);
}
int main() {
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	subsequence();
	return 0;
}
