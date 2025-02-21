#define MAX_LEN 1000001
#include <iostream>
#include <algorithm>

using namespace std;

int cache[MAX_LEN];
int way[MAX_LEN];
int V;

// AC
// MEM 9832kb  |  TIME 8ms

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V;
	fill_n(cache, V + 1, -1);
	cache[1] = 0;

	for (int i = 2; i <= V; i++) {
		if (cache[i] != -1) {
			continue;
		}

		cache[i] = cache[i - 1] + 1;
		way[i] = i - 1;
		if (i % 2 == 0 && cache[i / 2] + 1 < cache[i]) {
			cache[i] = cache[i / 2] + 1;
			way[i] = i / 2;
		}
		if (i % 3 == 0 && cache[i / 3] + 1 < cache[i]) {
			cache[i] = cache[i / 3] + 1;
			way[i] = i / 3;
		}
	}

	cout << cache[V] << endl;

	while (V != 0) {
		cout << V << " ";
		V = way[V];
	}

	return 0;
}