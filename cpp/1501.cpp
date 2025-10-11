#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <sstream>

using namespace std;

map<string, int> m;

string getConanical(string word) {
	if (word.length() > 2) sort(word.begin() + 1, word.end() - 1);

	return word;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N;

	string x;
	for (int i = 0; i < N; i++) {
		cin >> x;	

		m[getConanical(x)]++;
	}

	cin >> M;
	cin.ignore();

	for (int i = 0; i < M; i++) {
		getline(cin, x);

		stringstream ss(x);
		string word;
		int cnt = 1;

		while (ss >> word) {
			cnt *= m[getConanical(word)];
		}

		cout << cnt << "\n";
	}

	return 0;
}