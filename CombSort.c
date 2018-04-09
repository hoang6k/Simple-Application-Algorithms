#include <stdio.h>
int n;
float *a;
int sorted = 0;
void combsort() {
	int gap = n - 1;
	while (sorted == 0) {
		if (gap == 1)
			sorted = 1;
		for (int k = 0; k + gap < n; k++) {
			if (a[k] > a[k + gap]) {
				float temp = a[k];
				a[k] = a[k + gap];
				a[k + gap] = temp;
				sorted = 0;
			}
		}
		if (gap > 1)
			gap /= 1.3;
		if (gap == 9 || gap == 10)
			gap = 11;
	}
}
int main() {
	scanf("%d", &n);
	a = (float *) calloc(n, sizeof(float));
	for (int i = 0; i < n; i++) {
		scanf("%f", &a[i]);
	}
	combsort();
	for (int k = 0; k < n - 1; k++) {
		printf("%2.2f ", a[k]);
	}
	printf("%2.2f", a[n - 1]);
	free(a);
	return 0;
}
