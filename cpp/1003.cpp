#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_LEN 42

int sccidx[MAX_LEN] = { 0, 1, };
int T, V;

void getFibonacci(int n) {
	for (int i = 3; i < n; i++) sccidx[i] = sccidx[i - 1] + sccidx[i - 2];	
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	sccidx[1] = sccidx[2] = 1;
	getFibonacci(MAX_LEN);	
	
	cin >> T;

	while (T--) {
		cin >> V;

		if (!V) cout << "1 0\n";
		else if (V == 1) cout << "0 1\n";
		else cout << sccidx[V - 1] << " " << sccidx[V] << "\n";
	}

	return 0;
}