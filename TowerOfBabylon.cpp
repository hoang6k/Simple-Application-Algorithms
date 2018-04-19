#include <bits/stdc++.h>
#define MAXN 30
using namespace std;
int N, u, v, t, w, l, _max;
queue<int> result;
struct Block {
	int h, w, l;
	Block() :
			h(0), w(0), l(0) {
	}
	Block(int _h, int _w, int _l) :
			h(_h), w(_w), l(_l) {
	}
} block[3 * MAXN];
bool areaCompare(Block x, Block y) {
	return x.w * x.l > y.w * y.l;
}
int main() {
	while (1) {
		scanf("%d", &N);
		if (!N)
			break;
		for (int i = 0; i < N; i++) {
			scanf("%d %d %d", &u, &v, &t);
			block[3 * i] = Block(u, min(v, t), max(v, t));
			block[3 * i + 1] = Block(v, min(t, u), max(t, u));
			block[3 * i + 2] = Block(t, min(u, v), max(u, v));
		}
		sort(block, block + 3 * N, areaCompare);
		int mh[3 * N];
		_max = -1;
		for (int i = 0; i < 3 * N; i++) {
			mh[i] = block[i].h;
			w = block[i].w;
			l = block[i].l;
			for (int j = 0; j < i; j++) {
				if (block[j].w > w && block[j].l > l)
					mh[i] = max(mh[i], mh[j] + block[i].h);
			}
			_max = max(_max, mh[i]);
		}
		result.push(_max);
	}
	int count = 0;
	while (!result.empty()) {
		printf("Case %d: maximum height = %d\n", ++count, result.front());
		result.pop();
	}
	return 0;
}
