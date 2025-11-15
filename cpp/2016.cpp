#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

const int INF = 1e9 + 7;
const int P = 5;
const int TAEHYEON = 0;

int solve(vector<vector<int>>& man, vector<vector<int>>& woman) {
	int refus[P] = { 0, };
	int mpart[P];
	memset(mpart, -1, sizeof mpart);

	queue<int> q;
	for (int i = 0; i < P; i++) q.push(i);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		int midx = woman[cur][refus[cur]];

		// success
		if (mpart[midx] == -1) {
			mpart[midx] = cur;
		}
		// refusal
		else {
			// if man prefers current partner than current woman
			if (man[midx][cur] < man[midx][mpart[midx]]) {
				q.push(mpart[midx]);
				mpart[midx] = cur;
			}
			else {
				refus[cur]++;
				q.push(cur);
			}
		}
	}

	return mpart[TAEHYEON];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		vector<vector<int>> man(P, vector<int>(P));
		vector<vector<int>> woman(P, vector<int>(P));

		// man[][] = ranks
		for (int i = 0; i < P; i++) man[TAEHYEON][i] = i;
		for (int i = 1; i < P; i++) {
			for (int j = 0; j < P; j++) {
				int x;
				cin >> x;

				man[i][x - 6] = j;
			}
		}

		for (int i = 0; i < P; i++) {
			for (int j = 0; j < P; j++) {
				int x;
				cin >> x;

				woman[i][j] = x - 1;
			}
		}

		int ret = solve(man, woman);
		bool flag = false;

		for (int i = 0; i < ret; i++) {
			vector<int> ranks(P);
			ranks[i] = 0;
			int currentRank = 1;
			for (int j = 0; j < P; j++) {
				if (j == i) continue;
				ranks[j] = currentRank++;
			}

			man[TAEHYEON] = ranks;
			int newPartner = solve(man, woman);
			if (newPartner == i) {
				flag = true;
				break;
			}
		}

		cout << (flag ? "YES\n" : "NO\n");
	}

	return 0;
}