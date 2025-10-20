#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

int getCharIndex(char c) {
	if (c >= 'a' && c <= 'z') return c - 'a';
	else return c - 'A' + 26;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string S, W;
	int g, s;

	cin >> g >> s >> W >> S;
	
	vector<int> wcnt(52, 0);
	for (auto cur : W) wcnt[getCharIndex(cur)]++;
	
	vector<int> scnt(52, 0);
	for (int i = 0; i < g; i++) scnt[getCharIndex(S[i])]++;

	int res = 0;
	if (wcnt == scnt) res++;

	for (int i = g; i < s; i++) {
		scnt[getCharIndex(S[i - g])]--;
		scnt[getCharIndex(S[i])]++;

		if (wcnt == scnt) res++;
	}

	cout << res;

	return 0;
}