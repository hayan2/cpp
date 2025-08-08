#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	deque<int> dq;
	for (int i = 1; i <= N; i++) dq.push_back(i);
	

	int cnt = 0;
	for (int i = 0; i < M; i++) {
		int x;
		cin >> x;
				
		int idx = 0;
		for (int j = 0; j < dq.size(); j++) {
			if (dq[j] == x) {
				idx = j;
				break;
			}
		}

		if (idx <= dq.size() / 2) {		
			for (int j = 0; j < idx; j++) {
				dq.push_back(dq.front());
				dq.pop_front();
			}
			cnt += idx;
		}
		else {			
			int m = dq.size() - idx;
			for (int j = 0; j < m; j++) {
				dq.push_front(dq.back());
				dq.pop_back();
			}
			cnt += m;
		}
				
		dq.pop_front();
	}

	cout << cnt;

	return 0;
}