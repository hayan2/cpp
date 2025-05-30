#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	int N, M, x;

	cin >> N;	
	vector<int> cache(N);
	for (int i = 0; i < N; i++) 
		cin >> cache[i];

	cin >> M;	
	vector<int> w(M);
	for (int i = 0; i < M; i++)
		cin >> w[i];			

	sort(cache.begin(), cache.end());
	sort(w.begin(), w.end());

	int cnt = 0;
	int l = w.size();

	if (cache[N - 1] < w[M - 1]) {
		cout << -1;
		return 0;
	}
	
	while (l > 0) {
		for (int i = 0; i < N; i++) {
			int idx = upper_bound(w.begin(), w.end(), cache[i]) - w.begin() - 1;
			if (idx < 0) continue;
			l--;
			w.erase(w.begin() + idx, w.begin() + idx + 1);
		}
		cnt++;
	}

	cout << cnt;

	return 0;
}