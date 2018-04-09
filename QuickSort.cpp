#include<cstdio>
int n;
float *a;
int partition(int low, int high) {
	float pivot = a[high];
	int i = low - 1;
	float temp;
	for (int j = low; j <= high - 1; j++) {
		if (a[j] <= pivot) {
			i++;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	temp = a[i + 1];
	a[i + 1] = a[high];
	a[high] = temp;
	return (i + 1);
}
void quickSort(int low, int high) {
	if (low < high) {
		int pi = partition(low, high);
		quickSort(low, pi - 1);
		quickSort(pi + 1, high);
	}
}
int main() {
	scanf("%d", &n);
	a = new float[n];
	for (int i = 0; i < n; i++) {
		scanf("%f", &a[i]);
	}
	quickSort(0, n - 1);
	for (int i = 0; i < n - 1; i++) {
		printf("%2.2f ", a[i]);
	}
	printf("%2.2f", a[n - 1]);
	return 0;
}
