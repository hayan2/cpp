#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll N, K;
	cin >> N >> K;

	string str = to_string(N);
	int d = str.length();

	ll sft = 1;
	for (int i = 0; i < d; i++) sft = (sft * 10) % K;

	ll n = N % K;
	vector<bool> visited(K, false);
	int cnt = 1;
	ll cur = n;
	//
	while (cnt <= K) {
		if (!cur) {
			cout << cnt;
			return 0;
		}
		if (visited[cur]) {
			cout << -1;
			return 0;
		}
		visited[cur] = true;
		cur = (cur * sft + n) % K;
		cnt++;
	}

	return 0;
}