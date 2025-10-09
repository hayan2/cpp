#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
using pii = pair<int, int>;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	vector<int> res;
	int G;

	cin >> G;

	for (int i = 1; i * i < G; i++) {		
		if (!(G % i)) {
			int A = i, B = G / i;
			if (!((A + B) % 2)) res.push_back((A + B) / 2);
		}
	}
	
	if (!res.size()) {
		cout << "-1";
		exit(0);
	}

	sort(res.begin(), res.end());
	for (auto cur : res) {
		cout << cur << "\n";
	}

	return 0;
}