#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string str = "";
vector<int> pi;
int L;

void getPi() {
	int len = 0;

	pi.resize(L, 0);

	for (int i = 1; i < L; i++) {
		while ((len > 0) && (str[i] != str[len])) {
			len = pi[len - 1];
		}
		if (str[i] == str[len]) {
			len++;
			pi[i] = len;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> L;
	cin.ignore();
	getline(cin, str);

	getPi();

	cout << (L - 1 - pi[L - 1] + 1);

	return 0;
}