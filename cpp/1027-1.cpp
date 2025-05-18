#include <iostream>
#include <algorithm>

using namespace std;
const int MAX_SIZE = 51;
const int INF = 1e9 + 7;

int cache[MAX_SIZE] = { 0, }, cnt[MAX_SIZE] = { 0, };
int N, res = 0;

double getSlope(int x1, int y1, int x2, int y2) { 
	return (double)(y2 - y1) / (x2 - x1);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	
	for (int i = 0; i < N; i++) cin >> cache[i];
	for (int i = 0; i < N; i++) {
		double ms = -INF;
		for (int j = i + 1; j < N; j++) {
			double slope = getSlope(i, cache[i], j, cache[j]);
			if (ms < slope) {
				cnt[i]++, cnt[j]++;
				res = max(res, max(cnt[i], cnt[j]));
				ms = slope;
			}
		}
	}

	cout << res;

	return 0;
}