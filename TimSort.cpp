#include <iostream>
#include <cstdio>
using namespace std;
int n,RUN=16;
double *a;
void insertionsort(int left, int right){
	for (int i = left + 1; i <= right; i++)
	{
		double temp = a[i];
		int j = i - 1;
		while (a[j] > temp && j >= left)
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = temp;
	}
}
void merge(int left, int mid, int right) {
	float s[right - left + 1];
	int k, i = left, j = mid + 1;
	for (k = 0; k <= right - left + 1; k++) {
		if (i > mid) {
			s[k] = a[j];
			j++;
		} else if (j > right) {
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
	for (k = left, i = 0; k <= right; k++, i++) {
		a[k] = s[i];
	}
}
void mergesort(int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergesort(left, mid);
		mergesort(mid + 1, right);
		merge(left, mid, right);
	}
}
void timsort(){
	for (int i = 0; i < n; i+=RUN)
		insertionsort(i, min((i+31), (n-1)));
	for (int size = RUN; size < n; size = 2*size)
	{
		// pick starting point of left sub array. We
		// are going to merge arr[left..left+size-1]
		// and arr[left+size, left+2*size-1]
		// After every merge, we increase left by 2*size
		for (int left = 0; left < n; left += 2*size)
		{
			// find ending point of left sub array
			// mid+1 is starting point of right sub array
			int mid = left + size - 1;
			int right = min((left + 2*size - 1), (n-1));

			// merge sub array arr[left.....mid] &
			// arr[mid+1....right]
			merge(left, mid, right);
		}
	}
}
int main() {
	cin >> n;
	a = new double[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	timsort();
	for (int i = 0; i < n - 1; i++) {
		printf("%2.2f ", a[i]);
	}
	printf("%2.2f", a[n - 1]);
	delete[] a;
	return 0;
}
