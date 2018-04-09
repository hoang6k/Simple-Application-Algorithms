#include <iostream>
#include <cstdio>
using namespace std;
int n;
double *a;
void merge(int first, int mid, int last) {
	float s[last - first + 1];
	int k, i = first, j = mid + 1;
	for (k = 0; k <= last - first + 1; k++) {
		if (i > mid) {
			s[k] = a[j];
			j++;
		} else if (j > last) {
			s[k] = a[i];
			i++;
		} else {
			if (a[i] < a[j]) {
				s[k] = a[i];
				i++;
			} else {
				s[k] = a[j];
				j++;
			}
		}
	}
	for (k = first, i = 0; k <= last; k++, i++) {
		a[k] = s[i];
	}
}
void mergesort(int first, int last) {
	if (first < last) {
		int mid = (first + last) / 2;
		mergesort(first, mid);
		mergesort(mid + 1, last);
		merge(first, mid, last);
	}
}
int main() {
	cin >> n;
	a = new double[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	mergesort(0, n - 1);
	for (int i = 0; i < n - 1; i++) {
		printf("%2.2f ", a[i]);
	}
	printf("%2.2f", a[n - 1]);
	delete[] a;
	return 0;
}
