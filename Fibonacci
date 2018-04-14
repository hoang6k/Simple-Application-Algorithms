#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long x_1, x_2;
string sn;
struct matrix {
	long long a;
	long long b;
};
matrix result = { 1, 0 };
matrix multi(matrix x, matrix y) {
	matrix z = { (x.a * y.a + x.b * y.b) % MOD, (x.a * y.b + x.b * y.a
			- x.b * y.b) % MOD };
	return z;
}
matrix powx(matrix x, int k) {
	if (!k) {
		matrix unit = { 1, 0 };
		return unit;
	} else if (k == 1)
		return x;
	else {
		int i = 1;
		matrix y = x;
		while (i++ < k)
			y = multi(x, y);
		return y;
	}
}
int main() {
	cin >> sn >> x_1 >> x_2;
	matrix unit = { 1, 1 };
	for (int i = sn.size() - 1; i >= 0; i--) {
		int temp = sn[i] - '0';
		if (i == (int) sn.size() - 1) {
			matrix z = powx(unit, temp);
			result = multi(result, z);
		} else {
			unit = powx(unit, 10);
			matrix z = powx(unit, temp);
			result = multi(result, z);
		}
	}
	matrix dec = { 1, -1 };
	matrix temp = multi(result, dec);
	while (temp.a < 0)
		temp.a += 1000000007;
	while (temp.b < 0)
		temp.b += 1000000007;
	cout << (x2 * temp.a + x1 * temp.b) % MOD;
	return 0;
}
