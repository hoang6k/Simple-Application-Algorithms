#include <iostream>
using namespace std;
bool bloper(int n, long k) {
	long s = n * (n + 1) / 2;
	if ((k + s) % 2) {
		return 0;
	} else if ((k > s) || (k < 2 - s) || (k == s - 2) || (k == 4 - s)) {
		return 0;
	}
	return 1;
}
int main() {
	int m, n;
	long k;
	cin >> m;
	bool b[m];
	for (int j = 0; j < m; j++) {
		cin >> n >> k;
		b[j] = bloper(n, k);
	}
	for (int i = 0; i < m; i++)
		cout << b[i] << endl;
	return 0;
}
