#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}
int pour(int cap_from, int cap_to, int c) {
	int from = 0, to = 0;
	int steps = 0;
	while (from != c && to != c) {
		int maxpour = min(from, cap_to - to);
		from -= maxpour;
		to += maxpour;
		if (maxpour != 0)
			steps++;
		if (from == c || to == c)
			break;
		if (from == 0) {
			from = cap_from;
			steps++;
		}
		if (to == cap_to) {
			to = 0;
			steps++;
		}
	}
	return steps;
}
int waterjug(int a, int b, int c) {
	if (a < b) {
		int temp = a;
		a = b;
		b = temp;
	}
	if (a < c)
		return -1;
	if (c % gcd(a, b) != 0)
		return -1;
	return min(pour(a, b, c), pour(b, a, c));
}
int main() {
	int n, a, b, c;
	cin >> n;
	int d[n];
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		d[i] = waterjug(a, b, c);
	}
	for (int i = 0; i < n; i++)
		cout << d[i] << endl;
	return 0;
}
