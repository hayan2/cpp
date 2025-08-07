#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <string.h>

using namespace std;
using ll = long long;

ll solve(int N) {
	queue<string> q;
	vector<ll> res;

	for (int i = 0; i <= 9; i++) {
		q.push(to_string(i));
		res.push_back(i);
	}	
	
	while (!q.empty()) {
		string cur = q.front();
		q.pop();
		
		for (int i = 0; i < cur.back() - '0'; i++) {
			string x = cur + to_string(i);
			q.push(x);
			res.push_back(stoll(x));
		}
	}

	if (N >= res.size()) return -1;
	else return res[N];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	cout << solve(N - 1);

	return 0;
}
