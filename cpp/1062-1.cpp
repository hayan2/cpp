#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>

using namespace std;

map<int, int> m;
vector<string> str;
int N, K;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	m[1] = 1;

	cout << m[1] << "\n";

	int n = 5;
	map<int, int>::iterator itr = m.find(1);

	if (itr != m.end()) {
		swap(m[n], itr->second);
		m.erase(itr);
	}

	cout << m[5] << "\n";

	return 0;
}