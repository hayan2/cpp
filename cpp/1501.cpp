#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

map<string, int> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N;

	string x;
	for (int i = 0; i < N; i++) {
		cin >> x;

		sort(x.begin() + 1, x.end() - 1);

		if (m.count(x)) 
	}


	return 0;
}