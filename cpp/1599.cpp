#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <map>

using namespace std;

// a b k d e   g h i l m   n  ng  o p r s t u w y

map<char, int> ranks;
int ng = 11;

void initRanks() {
	ranks['a'] = 0, ranks['b'] = 1, ranks['k'] = 2, ranks['d'] = 3, ranks['e'] = 4;
	ranks['g'] = 5, ranks['h'] = 6, ranks['i'] = 7, ranks['l'] = 8, ranks['m'] = 9;
	ranks['n'] = 10, ranks['o'] = 12, ranks['p'] = 13, ranks['r'] = 14;
	ranks['s'] = 15, ranks['t'] = 16, ranks['u'] = 17, ranks['w'] = 18;
	ranks['y'] = 19;
}

bool compare(const string& s1, const string& s2) {
	int i = 0, j = 0;
	
	while (i < s1.length() && j < s2.length()) {
		int rank1, rank2;
		int advance1 = 1, advance2 = 1;

		if (s1[i] == 'n' && i + 1 < s1.length() && s1[i + 1] == 'g') {
			rank1 = ng;
			advance1 = 2;
		}
		else rank1 = ranks[s1[i]];

		if (s2[i] == 'n' && i + 1 < s2.length() && s2[i + 1] == 'g') {
			rank2 = ng;
			advance2 = 2;
		}
		else rank2 = ranks[s2[i]];

		if (rank1 != rank2) return rank1 < rank2;
		
		i += advance1;
		j += advance2;
	}

	return s1.length() < s2.length();
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<string> words;
	int N;
	cin >> N;

	initRanks();

	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;

		words.push_back(str);
	}

	sort(words.begin(), words.end(), compare);

	for (int i = 0; i < N; i++) {
		cout << words[i] << "\n";
	}

	return 0;
}