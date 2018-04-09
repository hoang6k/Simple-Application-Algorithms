#include<bits/stdc++.h>
int main() {
	int n;
	scanf("%d", &n);
	char *s = new char[n];
	scanf("%s", s);
	int i = n - 1;
	while (s[i] == '1') {
		s[i] = '0';
		if (i-- == -1)
			break;
	}
	if (i != -1) {
		s[i] = '1';
		for (int j = 0; j < n; j++)
			printf("%c", s[j]);
	} else
		printf("-1");
	return 0;
}
