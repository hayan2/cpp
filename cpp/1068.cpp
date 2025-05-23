#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX_SIZE = 52;
const int VISITED = 1;

vector<int> cache[MAX_SIZE];
int visited[MAX_SIZE] = { 0, };
int N, R, x, res = 0, tmp, root;

void solved(int cur) {
	if (cur == R) return;
	if (cache[cur].empty()) res++;
	visited[cur] = VISITED;
	for (auto nxt : cache[cur]) {
		if (visited[nxt]) continue;
		if (cache[cur].size() == 1 && nxt == R) res++;
		solved(nxt);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		if (x == -1) root = i;
		else cache[x].push_back(i);
	}
	
	cin >> R;	
	solved(root);
	cout << res;

	return 0;
}