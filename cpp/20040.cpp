#define MAX_LEN 500001
#include <iostream>
#include <algorithm>

using namespace std;

int sccidx[MAX_LEN];
int V, E;

int find(int x) {
	if (sccidx[x] == x) return x;
	else return sccidx[x] = find(sccidx[x]);
}

void unionSet(int a, int b) {
	a = find(a);
	b = find(b);

	if (a < b) sccidx[b] = a;
	else if (a > b) sccidx[a] = b;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int u, v, res = 0;
	cin >> V >> E;
	for (int i = 0; i < V; i++) sccidx[i] = i;
	
	for (int i = 1; i <= E; i++) {
		cin >> u >> v;

		if (find(u) == find(v)) {
			res = i;
			break;
		}
		unionSet(u, v);
	}

	cout << res;

	return 0;
}