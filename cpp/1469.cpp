#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_X = 16;
const int MAX_N = 8;

vector<int> S;
vector<bool> used(MAX_X + 1, false);
int cache[MAX_N + 1];
int N, x;

void solve(int idx) {
	if (idx == N * 2) {
		for (int i = 0; i < N * 2; i++) {
			cout << S[i] << " ";
		}

		exit(0);		
	}
	if (idx > N * 2) return;
	if (S[idx] != -1) {
		solve(idx + 1);
		return;
	}
	
	for (int i = 0; i < N; i++) {
		if (idx + cache[i] + 1 >= N * 2) continue;
		if (S[idx + cache[i] + 1] != -1) continue;
		if (used[cache[i]]) continue;

		S[idx] = S[idx + cache[i] + 1] = cache[i];
		used[cache[i]] = true;

		solve(idx + 1);

		S[idx] = S[idx + cache[i] + 1] = -1;
		used[cache[i]] = false;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	S.assign(N * 2, -1);
	for (int i = 0; i < N; i++) cin >> cache[i];

	sort(cache, cache + N);
	solve(0);

	cout << "-1";

	return 0;
}