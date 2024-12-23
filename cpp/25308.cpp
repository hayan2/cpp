#define LEN_STAT 8
#define VISITED 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

vector<double> dist(LEN_STAT);
vector<double> cache(LEN_STAT);
vector<bool> visited(LEN_STAT, 0);
int res = 0;

int isConvex() {
	for (int i = 0; i < LEN_STAT; i++) {
		int p1 = i;
		int p2 = (i + 1) % LEN_STAT;
		int p3 = (i + 2) % LEN_STAT;
		if (cache[p1] * cache[p3] * sqrt(2) > cache[p2] * (cache[p1] + cache[p3])) return 0;
	}
	return 1;
}

int solved(int cnt) {
	if (cnt == LEN_STAT) {
		res += isConvex();
		return res;
	}

	for (int i = 0; i < LEN_STAT; i++) {
		if (visited[i]) continue;
		visited[i] = VISITED;
		cache[cnt] = dist[i];
		solved(cnt + 1);
		visited[i] = 0;
	}

	return res;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < LEN_STAT; i++) {
		cin >> dist[i];
	}

	cout << solved(0);

	return 0;
}