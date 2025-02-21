#define MAX_LEN 1001
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int cacheA[MAX_LEN][MAX_LEN] = { 0, };
int cacheB[MAX_LEN][MAX_LEN] = { 0, };
int V, W;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V;
	cin >> W;

	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			cacheA[i][j] = i + j - 2;
			cacheB[V - i + 1][V - j + 1] = i + j - 2;
		}
	}
	
	vector<int> res;
	int dsum = 0, x, y;	
	int aposx = 1, aposy = 1, bposx = V, bposy = V;
	
	while (W--) {
		cin >> x >> y;
				
		if (abs(cacheA[aposx][aposy] - cacheA[x][y]) > abs(cacheB[bposx][bposy] - cacheB[x][y])) {			
			dsum += abs(cacheB[bposx][bposy] - cacheB[x][y]);
			bposx = x;
			bposy = y;
			res.push_back(2);			
		}
		else (abs(cacheA[aposx][aposy] - cacheA[x][y]) < abs(cacheB[bposx][bposy] - cacheB[x][y])) {			
			dsum += abs(cacheA[aposx][aposy] - cacheA[x][y]);
			aposx = x;
			aposy = y;
			res.push_back(1);			
		}
		else {

		}
	}

	cout << dsum << endl;
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}

	return 0;
}
