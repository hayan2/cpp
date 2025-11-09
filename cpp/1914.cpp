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

int length = 1;

void hanoi(int n, int from, int sub, int to) {	
	if (n == 1) {
		cout << from << " " << to << "\n";
		return;
	}	

	hanoi(n - 1, from, to, sub);	

	cout << from << " " << to << "\n";
	
	hanoi(n - 1, sub, from, to);
}

void minusCount(vector<int>& cnt, int idx) {
	if (idx == CNT_LEN) return;
	if (!cnt[idx]) {
		cnt[idx] = 9;
		minusCount(cnt, idx + 1);
	}

	cnt[idx]--;
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	
	vector<int> cnt(CNT_LEN);
	cnt[1] = 1;
	int idx = 1;
	for (int i = 0; i < N; i++) {
		int carry = 0;
		for (int j = 1; j <= idx; j++) {
			int x = cnt[j] * 2 + carry;
			cnt[j] = x % 10;
			if (x >= 10) {
				carry = 1;
				if (j == idx) idx++;
			}
			else {
				carry = 0;
			}
		}
	}
	minusCount(cnt, 1);

	bool flag = false;
	for (int i = CNT_LEN - 1; i > 0; i--) {
		if (!flag && !cnt[i]) continue;
		else flag = true;
		cout << cnt[i];
	}
	cout << endl;
	
	if (N <= 20) hanoi(N, 1, 2, 3);

	return 0;
}