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

		if (refus[cur] >= P) continue;

		int midx = woman[cur][refus[cur]];
		refus[cur]++;
		
		if (mpart[midx] == -1) mpart[midx] = cur;
		else {			
			if (man[midx][cur] < man[midx][mpart[midx]]) {
				q.push(mpart[midx]);
				mpart[midx] = cur;
			}
			else {				
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

		vector<int> p(P);
		for (int i = 0; i < P; i++) p[i] = i;

		do {
			vector<int> ranks(P);
			for (int i = 0; i < P; i++) ranks[p[i]] = i;

			man[TAEHYEON] = ranks;

			int newPartner = solve(man, woman);

			if (newPartner < ret) {
				flag = true;
				break;
			}
		} while (next_permutation(p.begin(), p.end()));

		cout << (flag ? "YES\n" : "NO\n");
	}

	return 0;
}