#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string T = "";
string P = "";
vector<int> pi;

void getPi() {
	int m = P.size();
	int j = 0;

	pi.resize(m, 0);

	for (int i = 1; i < m; i++) {
		while ((j > 0) && (P[i] != P[j])) {
			j = pi[j - 1];
		}
		if (P[i] == P[j]) {
			j++;
			pi[i] = j;
		}
	}
}

void solved() {
	vector<int> res;
	
	int n = T.size();
	int m = P.size();
	int j = 0;

	for (int i = 0; i < n; i++) {
		while ((j > 0) && (T[i] != P[j])) {
			j = pi[j - 1];
		}
		if (T[i] == P[j]) {
			if (j == (m - 1)) {
				res.push_back(i - m + 1);
				j = pi[j];
			}
			else j++;
		}
	}

	cout << res.size() << "\n";
	for (auto x : res) {
		cout << x + 1 << " ";
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	getline(cin, T);
	getline(cin, P);

	getPi();
	solved();

	return 0;
}