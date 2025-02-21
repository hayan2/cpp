#define MAX_LEN 1000001
#define INF 1e7
#include <iostream>
#include <algorithm>

using namespace std;

int cache[MAX_LEN];
int V;

// AC
// MEM 37056kb  |  TIME 32ms

int sol(int x) {
	if (x == 1) {
		return 0;
	}
	if (cache[x] != -1) {
		return cache[x];
	}

	cache[x] = sol(x - 1) + 1;
	if (x % 3 == 0) {
		cache[x] = min(cache[x], sol(x / 3) + 1);
	}
	if (x % 2 == 0) {
		cache[x] = min(cache[x], sol(x / 2) + 1);
	}
	
	return cache[x];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> V;
	fill_n(cache, V + 1, -1);
	cache[1] = 0;

	sol(V);

	cout << cache[V] << endl;

	while (V != 0) {
		if (V % 3 == 0 && cache[V / 3] == cache[V] - 1) {
			cout << V << " ";
			V /= 3;
		}
		else if (V % 2 == 0 && cache[V / 2] == cache[V] - 1) {
			cout << V << " ";
			V /= 2;
		}
		else {
			cout << V << " ";
			V -= 1;
		}
	}	

	return 0;
}