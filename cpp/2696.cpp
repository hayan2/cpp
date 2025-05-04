#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int MAX_SIZE = 10001;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	int T;

	cin >> T;

	while (T--) {
		priority_queue<int> max;
		priority_queue<int, vector<int>, greater<int>> min;
		vector<int> res;
		int cache[MAX_SIZE] = { 0, }, M, tmp = 0;

		cin >> M;

		for (int i = 1; i <= M; i++) {
			cin >> cache[i];

			if (i & 1) max.push(cache[i]);
			else min.push(cache[i]);
			
			if (i > 1) {
				if (max.top() > min.top()) {
					tmp = max.top(), max.pop();
					max.push(min.top()), min.pop();
					min.push(tmp);
				}
			}
			if (i & 1) res.push_back(max.top());
		}
		//
		cout << res.size() << "\n";
		for (auto x : res) cout << x << " ";
		cout << "\n";
	}

	return 0;
}