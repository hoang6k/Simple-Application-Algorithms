#include <bits/stdc++.h>
#define MAXV 601
using namespace std;
int W, H, N, w, h, S[MAXV][MAXV] = { };
void initialize() {
	scanf("%d %d %d", &W, &H, &N);
	for (h = 1; h <= H; h++)
		for (w = 1; w <= W; w++)
			S[h][w] = h * w;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &w, &h);
		S[h][w] = 0;
	}
}
int main() {
	initialize();
	for (h = 1; h <= H; h++)
		for (w = 1; w <= W; w++) {
			for (int i = 1; i <= h / 2; i++)
				S[h][w] = min(S[h][w], S[i][w] + S[h - i][w]);
			for (int j = 1; j <= w / 2; j++)
				S[h][w] = min(S[h][w], S[h][j] + S[h][w - j]);
		}
	printf("%d", S[H][W]);
	return 0;
}
