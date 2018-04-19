#include <bits/stdc++.h>
#define MAXN 1000001
using namespace std;
int n, __min = 1e7, __max = 0, s, t;
struct Period {
	int start, finish, proc;
	Period() :
			start(0), finish(0), proc(0) {
	}
	Period(int x, int y, int z) :
			start(x), finish(y), proc(z) {
	}
} p[MAXN];
bool finishCompare(Period p1, Period p2) {
	return (p1.proc > p2.proc);
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &s, &t);
		p[i] = Period(s, t, t - s);
		__min = min(__min, t);
		__max = max(__max, s);
	}
	if (__min >= __max) {
		printf("-1");
		return 0;
	}
	sort(p, p + n, finishCompare);
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (p[j].start > p[i].finish || p[i].start > p[j].finish) {
				printf("%d", p[i].proc + p[j].proc);
				return 0;
			}
		}
	}
}
