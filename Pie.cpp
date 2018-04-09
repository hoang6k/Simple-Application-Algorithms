#include <bits/stdc++.h>
using namespace std;
#define MAXT 10000
#define MAXN 10001
#define pi 3.141592653589793238
int T, N, F, r[MAXN] = { };
double result[MAXT] = { };
int main() {
	scanf("%d", &T);
	int i = -1;
	while (++i < T) {
		scanf("%d %d", &N, &F);
		int j = -1;
		double sum = 0;
		while (++j < N) {
			scanf("%d", &r[j]);
			sum += r[j] * r[j];
		}
		sum *= pi;
//		printf("%.7f\n", sum);
		double high = sum / (double) (F + 1);
//		printf("%.7f\n", high);
		double low = 0;
//		printf("%.7f\n", low);
		double V, epsilon = 10e-8;
		while (high - low > epsilon) {
			V = (low + high) / 2;
//			printf("%.7f\n", V);
			j = -1;
			sum = 0;
			while (++j < N) {
				sum += (int) (pi * r[j] * r[j] / V);
			}
//			cout << " sum=" << sum << endl;
			if (sum < F + 1) {
				high = V;
//				printf(" high = %.7f\n", high);
				continue;
			} else {
				low = V;
//				printf(" low = %.7f\n", low);
				continue;
			}
		}
		result[i] = (low + high) / 2;
	}
	i = -1;
	while (++i < T) {
//		printf("%.10f\n", result[i]);
		printf("%.6f\n", result[i]);
	}
	return 0;
}
