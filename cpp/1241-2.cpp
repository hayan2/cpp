#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1000001;

int score[MAX_N] = { 0 };
int cnt[MAX_N] = { 0 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> cache(N);
	//
	int mx = 0;
	for (int i = 0; i < N; i++) {
		cin >> cache[i];		
		cnt[cache[i]]++;
		mx = max(mx, cache[i]);
	}
		
	for (int i = 1; i <= mx; i++) {	
		if (cnt[i] > 0) {			
			for (int j = i; j <= mx; j += i) {
				score[j] += cnt[i];
			}
		}
	}

	for (int cur : cache) cout << score[cur] - 1 << "\n";	

	return 0;
}