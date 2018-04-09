#include<bits/stdc++.h>
using namespace std;
int n, k1, k2/*, _count = 0*/;
int *a;
bool checkover(int x) {
	int _count_ = 0;
	for (int j = x; j > 0; j--) {
		if (a[j] == 1) {
			if (_count_++ > k2)
				return true;
		} else
			break;
	}
	if (_count_ > k2)
		return true;
	else
		return false;
}
bool check(int x) {
	int _count_ = 0;
	for (int j = x; j > 0; j--) {
		if (a[j] == 1) {
			if (_count_++ > k2)
				return true;
		} else
			break;
	}
	if ((_count_ < k1) || (_count_ > k2))
		return true;
	else
		return false;
}
void nurseschedule(int x) {
	for (int i = 0; i < 2; i++) {
		a[x] = i;
		if (a[x] == 0) {
			if (a[x - 1] == 0)
				continue;
			else {
				if (x > 1)
					if (check(x - 1))
						continue;
				if (x < n) {
					if (n - x + 1 < k1)
						continue;
					nurseschedule(x + 1);
				} else {
//					_count++;
					for (int j = 1; j < n + 1; j++)
						printf("%d", a[j]);
					printf("\n");
				}
			}
		} else {
			if (checkover(x) && (x != 1))
				continue;
			if (x < n)
				nurseschedule(x + 1);
			else {
				if (!check(x)) {
//					_count++;
					for (int j = 1; j < n + 1; j++)
						printf("%d", a[j]);
					printf("\n");
				}
			}
		}
	}
}
int main() {
	scanf("%d %d %d", &n, &k1, &k2);
	a = new int[n + 1];
	a[0] = 1;
	nurseschedule(1);
//	printf("%d",_count);
	delete[] a;
	return 0;
}
