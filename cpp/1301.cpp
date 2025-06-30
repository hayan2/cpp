#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <tuple>
#include <numeric>
#include <functional>

using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> cache(N);
	for (int i = 0; i < N; i++) cin >> cache[i];

	map<tuple<int, int, vector<int>>, long long> dp;
	function<long long(int, int, vector<int>&)> solved =
		[&](int prev1, int prev2, vector<int>& cnt) -> long long {

		tuple<int, int, vector<int>> state = { prev1, prev2, cnt };

		if (dp.count(state)) return dp[state];
		if (!accumulate(cnt.begin(), cnt.end(), 0)) return 1;

		long long ret = 0;
		for (int i = 0; i < N; i++) {
			int c = i + 1;
			if (cnt[i] > 0 && c != prev1 && c != prev2) {
				cnt[i]--;
				ret += solved(c, prev1, cnt);
				cnt[i]++;
			}
		}
		return dp[state] = ret;
		};

	cout << solved(0, 0, cache);

	return 0;
}