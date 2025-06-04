#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

using namespace std;
const int MAX_SIZE = 51;
const int INF = 1e9 + 7;

string str, words[MAX_SIZE];
int dp[MAX_SIZE], box[MAX_SIZE][MAX_SIZE], N;

int getCost(int s, int idx) {
	int& ret = box[s][idx];
	if (ret != -1) return ret;

	string w = words[idx];
	if (s + w.size() > str.size()) return ret = INF;

	ret = 0;
	vector<int> x(26);
	for (int i = 0; i < w.size(); i++) {
		int sc = str[s + i] - 'a';
		int wc = w[i] - 'a';

		x[sc]--;
		x[wc]++;
		if (sc != wc) ret++;
	}

	for (int i = 0; i < 26; i++) {
		if (x[i] != 0) return ret = INF;
	}
	return ret;
}

int solved(int s) {
	if (s >= str.size()) return 0;

	int& ret = dp[s];
	if (ret != -1) return ret;

	ret = INF;
	for (int i = 0; i < N; i++) {
		int cost = getCost(s, i);
		if (cost != INF)ret = min(ret, cost + solved(s + words[i].size()));
	}

	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(dp, -1, sizeof dp);
	memset(box, -1, sizeof box);

	cin >> str;
	cin >> N;
	for (int i = 0; i < N; i++) 
		cin >> words[i];
	
	int res = solved(0);
	cout << ((res == INF) ? -1 : res);

	return 0;
}