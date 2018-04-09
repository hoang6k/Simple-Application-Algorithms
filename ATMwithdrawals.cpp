#include <bits/stdc++.h>
using namespace std;
int n, j = -1, c, *S;
unsigned long long int *N;
string s;
int main() {
	scanf("%d", &n);
	N = new unsigned long long int[n];
	S = new int[n];
	while (++j < n) {
		cin >> s >> c;
		if (s[s.length() - 1] != '0' || s[s.length() - 2] != '0'
				|| s[s.length() - 3] != '0')
			N[j] = 0;
		else {
			N[j] = 0;
			S[j] = 1;
			int k = -1;
			string num = "";
			while (int(s.length() - c - 4 - ++k) > 0)
				num += s[k];
			N[j] += 2 * strtoull(num.c_str(), NULL, 10);
			k--;
			while (++k < int(s.length() - 3)) {
				if (k > 0 && k == int(s.length() - c - 4) && s[k] >= '0'
						&& s[k] < '5') {
					s[k] += 5;
					N[j]--;
				}
				if (s[k] == '1' || s[k] == '2' || s[k] == '3' || s[k] == '5')
					N[j]++;
				else if (s[k] == '4' || s[k] == '6') {
					N[j] += 2;
					S[j] *= 2;
				} else if (s[k] == '7' || s[k] == '8')
					N[j] += 2;
				else if (s[k] == '9') {
					N[j] += 3;
					S[j] *= 3;
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
		if (N[i])
			printf("%llu %d\n", N[i], S[i]);
		else
			printf("0\n");
	return 0;
}
