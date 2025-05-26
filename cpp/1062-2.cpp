#include <iostream>
#include <algorithm>

using namespace std;
const int MAX_SIZE = 51;

string str;
int c[MAX_SIZE] = { 0, };
int N, K, res = 0;

void solved(int x, int s, int state) {
	if (!x) {
		int cnt = 0;
		for (int i = 0; i < N; i++) 
			((c[i] & state) == c[i]) ? cnt++ : cnt;
		res = max(res, cnt);
	}

	for (int i = s; i < 26; i++) {
		if (!(state & (1 << i))) {
			state |= (1 << i);
			solved(x - 1, i, state);
			state &= ~(1 << i);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> str;
		int n = 0;
		for (int l = 0; l < str.length(); l++) 
			n |= (1 << str[l] - 'a');
		c[i] = n;
	}

	if (K < 5) cout << "0";
	else if (K == 26) cout << N;
	else {
		solved(K - 5, 0, 
			(1 << 'a' - 'a') + (1 << 'c' - 'a') + (1 << 'n' - 'a') +
			(1 << 't' - 'a') + (1 << 'i' - 'a')
		);
		cout << res;
	}

	return 0;
}