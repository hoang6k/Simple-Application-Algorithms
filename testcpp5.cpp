#include<bits/stdc++.h>
using namespace std;
int c, T;
typedef long long LL;
LL w;
LL way_num[] = { 1, 1, 1, 1, 2, 1, 2, 1, 1, 3 };
LL coin_num[] = { 0, 1, 1, 1, 2, 1, 2, 2, 2, 3 };
LL total_way_num, total_coin_num;
int x[19] = { };
int main() {
	cin >> T;
	while (T--) {
		total_way_num = 1;
		total_coin_num = 0;
		memset(x, 0, sizeof(int));
		cin >> w >> c;
		if (w % 1000 != 0) {
			cout << 0 << endl;
			continue;
		}
		w /= 1000;
		int i = 0;
		while (!w) {
			x[i] = w % 10;
			w /= 10;
			i++;
		}
		for (int i = 0; i <= c; i++) {
			total_way_num *= way_num[x[i]];
			total_coin_num += coin_num[x[i]];
		}
		LL sum = 0;
		for (int i = c + 1; i <= 18; i++)
			sum += x[i] * pow(10, i);
		LL big_coin_num = sum / (5 * pow(10, c));
		if (big_coin_num > 0 && (x[c] >= 0 && x[c] < 5)) {
			big_coin_num--;
			x[c] += 5;
		}
		total_way_num *= way_num[x[c]];
		total_coin_num += coin_num[x[c]] + big_coin_num;
		cout >> total_coin_num << " " << total_way_num << endl;
	}
	return 0;
}
