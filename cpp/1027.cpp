#include <iostream>
#include <algorithm>

using namespace std;
const int MAX_SIZE = 51;

int cache[MAX_SIZE] = { 0, };
int N, cnt = 0;

void solved(int s, int prev, int idx, int cd) {
	if (idx < 0 || idx >= N) return;
	if (prev >= cache[idx]) return;
	if (s != idx) cnt++;
	solved(s, cache[idx], idx + cd, cd);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) cin >> cache[i];

	int res = 0;
	for (int i = 0; i < N; i++) {
		solved(i, 0, i, 1);
		solved(i, 0, i, -1);
		res = max(res, cnt);
		cnt = 0;
	}

	cout << res;

	return 0;
}