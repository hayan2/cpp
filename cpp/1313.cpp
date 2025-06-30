#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
vector<bool> cache;
vector<int> res;
const int MAX_SIZE = 10000001;

void seive() {
	cache.assign(MAX_SIZE + 1, true);
	cache[0] = cache[1] = false;
	for (int i = 2; i * i < MAX_SIZE; i++) {
		if (cache[i]) {
			for (int j = i * i; j <= MAX_SIZE; j += i) cache[j] = false;
		}
	}
}

void solved() {	
	seive();
	res.assign(MAX_SIZE + 1, -1);
	for (int i = 1; i < MAX_SIZE; i++) {
		if (i > 0) res[i] = res[i - 1];
		if (i < 100 || cache[i]) continue;

		string str = to_string(i);
		bool flag = true;
		for (int l = 2; l < str.length(); l++) {
			for (int s = 0; s <= str.length() - l; s++) {
				int sub = stoi(str.substr(s, l));

				if (!cache[sub]) {
					flag = false;
					break;
				}
			}
			if (!flag) break;
		}
		if (flag) res[i] = i;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solved();

	int T, N;
	cin >> T;	

	while (T--) {
		cin >> N;

		cout << res[N] << "\n";
	}

	return 0;
}