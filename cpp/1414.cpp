#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <tuple>
#include <numeric>

using namespace std;

const int LOWER = 1;
const int UPPER = 27;

int find(vector<int>& parent, int x) {
	if (parent[x] == x) return x;
	else return parent[x] = find(parent, parent[x]);
}

void unionSet(vector<int>& parent, int a, int b) {
	a = find(parent, a);
	b = find(parent, b);

	if (a < b) parent[b] = a;
	else if (a > b) parent[a] = b;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, tot = 0;

	cin >> N;

	vector<tuple<int, int, int>> edges;
	vector<string> cache(N);

	for (int i = 0; i < N; i++) {
		cin >> cache[i];
		for (int j = 0; j < N; j++) {
			if (cache[i][j] == '0') continue;

			int w = 0;
			w += ((cache[i][j] >= 'a' && cache[i][j] <= 'z') ? 
				cache[i][j] - 'a' + LOWER : cache[i][j] - 'A' + UPPER);
			
			tot += w;
			edges.emplace_back(w, i, j);
		}
	}

	sort(edges.begin(), edges.end());

	vector<int> parent(N);
	iota(parent.begin(), parent.end(), 0);

	int mst = 0;
	int cnt = 0;

	for (const auto& edge : edges) {
		int w, u, v;
		tie(w, u, v) = edge;

		if (find(parent, u) != find(parent, v)) {
			unionSet(parent, u, v);
			mst += w;
			cnt++;
		}
	}
	//
	cout << ((N > 1 && cnt < N - 1) ? -1 : tot - mst);
	
	return 0;
}