#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
#include <array>
#include <set>

using namespace std;

const int MAX_WORD = 200001;
const int ALPHABET_SIZE = 26;
const int PUZZLE_SIZE = 9;
const int INF = 1e9;

struct Info {
	string word;
	array<int, ALPHABET_SIZE> cnt = { 0, };
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	vector<Info> cache;
	vector<string> words;
	string str, puzzle;

	while (cin >> str && str != "-") {
		Info info;
		info.word = str;
		for (auto x : str) info.cnt[x - 'A']++;
		cache.push_back(info);
	}

	while (cin >> puzzle && puzzle != "#") {		
		array<int, ALPHABET_SIZE> pcnt = { 0, };
		for (auto x : puzzle) pcnt[x - 'A']++;

		array<int, ALPHABET_SIZE> cnt = { 0, };
		for (const auto& cur : cache) {
			bool flag = true;
			for (int i = 0; i < ALPHABET_SIZE; i++) {
				if (cur.cnt[i] > pcnt[i]) {
					flag = false;
					break;
				}				
			}
			if (flag) {
				for (int i = 0; i < ALPHABET_SIZE; i++) {
					if (cur.cnt[i] > 0) cnt[i]++;
				}
			}
		}

		int mn = INF, mx = -1;
		set<char> sc;		
		for (auto x : puzzle) sc.insert(x);
		for (auto x : puzzle) {
			mn = min(mn, cnt[x - 'A']);
			mx = max(mx, cnt[x - 'A']);
		}
		
		string mns, mxs;
		for (auto x : sc) {
			if (!(cnt[x - 'A'] ^ mn)) mns += x;
			if (!(cnt[x - 'A'] ^ mx)) mxs += x;
		}

		cout << mns << " " << mn << " " << mxs << " " << mx << "\n";
	}

	return 0;
}