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
const int CNT_LEN = 33;

void hanoi(int N, int from, int sub, int to) {
	if (!N) return;

	hanoi(N - 1, from, to, sub);
	cout << from << " " << to << "\n";
	hanoi(N - 1, sub, from, to);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> cnt(CNT_LEN);
	int N;
	cin >> N;
	
	cnt[0] = 1;

	int digits = 1;
	for (int i = 0; i < N - 1; i++) {
		int carry = 0;
		for (int j = 0; j < digits; j++) {
			int x = cnt[j] * 2 + carry;
			cnt[j] = x % 10;
			carry = x / 10;
		}
		if (carry) cnt[digits++] = carry;

		cnt[0]++;
		carry = 0;
		for (int j = 0; j < digits; j++) {
			int x = cnt[j] + carry;
			cnt[j] = x % 10;
			carry = x / 10;
			if (!carry) break;
		}
		if (carry) cnt[digits++] = carry;
	}
	//
	for (int i = digits - 1; i > -1; i--) cout << cnt[i];
	cout << "\n";

	if (N <= 20) hanoi(N, 1, 2, 3);

	return 0;
}