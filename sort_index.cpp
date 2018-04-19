#include <bits/stdc++.h>
using namespace std;
int a[7];
int ix[7];

template<typename _Tp>
struct indexless: public binary_function<_Tp, _Tp, bool> {
	bool operator()(const _Tp& __x, const _Tp& __y) const {
		return a[__x] < a[__y];
	}
};

void sort_index() {

	sort(ix, ix + 7, indexless<int>());

}
int main() {
	for (int i = 0; i < 7; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < 7; i++)
		ix[i] = i;
	for (int i = 0; i < 7; i++)
		printf("%d ", a[i]);
	cout << endl;
	sort_index();
	for (int i = 0; i < 7; i++)
		printf("%d ", ix[i]);
	return 0;
}
