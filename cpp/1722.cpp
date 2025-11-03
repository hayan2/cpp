#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <numeric>

using namespace std;
using ull = unsigned long long;

const int MAX_N = 21;
const bool VISITED = true;

vector<ull> fact;
int N, k;

vector<ull> seq;

vector<ull> getSequence(ull idx) {
	vector<bool> visited(N + 1, false);
	vector<ull> ret;

	int i = 0;

	while (ret.size() < N) {
		int x = N - 1 - i;

		for (int j = 1; j <= N; j++) {
			if (visited[j]) continue;

			if (fact[x] > idx) {
				ret.push_back(j);
				visited[j] = VISITED;
				break;
			}
			else idx -= fact[x];
		}

		i++;
	}	

	return ret;
}

ull getIndex(vector<ull>& cache) {	
	vector<bool> visited(N + 1, false);
	ull ret = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 1; j < cache[i]; j++) {
			if (!visited[j]) ret += fact[N - 1 - i];
		}
		visited[cache[i]] = true;
	}

	return ret + 1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	seq.resize(N);
	cin >> k;

	fact.resize(MAX_N);

	fact[0] = 1;
	for (int i = 1; i < MAX_N; i++) {
		if (i > N) fact[i] = fact[i - 1];
		else fact[i] = fact[i - 1] * i;
	}

	if (k == 1) {
		ull idx;
		cin >> idx;

		vector<ull> ret = getSequence(idx - 1);

		for (auto x : ret) cout << x << " ";
	}
	else {
		vector<ull> cache(N);

		for (int i = 0; i < N; i++) cin >> cache[i];

		cout << getIndex(cache);
	}

	return 0;
}