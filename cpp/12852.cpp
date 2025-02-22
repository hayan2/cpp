#define MAX_LEN 1000001
#define INF 1e7
#include <iostream>
#include <algorithm>

using namespace std;

int sccidx[MAX_LEN];
int V;

// AC
// MEM 37056kb  |  TIME 32ms

int sol(int x) {
	if (x == 1) {
		return 0;
	}
	if (sccidx[x] != -1) {
		return sccidx[x];
	}

	sccidx[x] = sol(x - 1) + 1;
	if (x % 3 == 0) {
		sccidx[x] = min(sccidx[x], sol(x / 3) + 1);
	}
	if (x % 2 == 0) {
		sccidx[x] = min(sccidx[x], sol(x / 2) + 1);
	}
	
	return sccidx[x];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> V;
	fill_n(sccidx, V + 1, -1);
	sccidx[1] = 0;

	sol(V);

	cout << sccidx[V] << endl;

	while (V != 0) {
		if (V % 3 == 0 && sccidx[V / 3] == sccidx[V] - 1) {
			cout << V << " ";
			V /= 3;
		}
		else if (V % 2 == 0 && sccidx[V / 2] == sccidx[V] - 1) {
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