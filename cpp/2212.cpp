#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

const int INF = 1e9 + 7;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	vector<int> sensors(N);
	for (int i = 0; i < N; i++) {
		cin >> sensors[i];
	}

	if (K >= N) {
		cout << 0 << "\n";
		return 0;
	}

	sort(sensors.begin(), sensors.end());

	vector<int> diffs;
	for (int i = 0; i < N - 1; i++) {
		diffs.push_back(sensors[i + 1] - sensors[i]);
	}

	sort(diffs.begin(), diffs.end(), greater<int>());

	int sum = 0;
	for (int i = K - 1; i < diffs.size(); i++) {
		sum += diffs[i];
	}

	cout << sum << "\n";

	return 0;
}