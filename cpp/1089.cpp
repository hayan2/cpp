#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
using ld = long double;
const int MAX_SIZE = 10;
const int MOD = 1 << 16;

vector<int> res[MAX_SIZE];
string str[5];
int words[MAX_SIZE] = { 0x7B6F, 0x4924, 0x73E7, 0x79E7, 0x49ED, 0x79CF, 0x7BCF, 0x4927, 0x7BEF, 0x79EF };
int n[MAX_SIZE] = { 0, };
int N;

int getBit(int x, int y, int idx) {
	int ret = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = y; j < idx * 4 + 3; j++) {
			if (str[i][j] == '#') ret |= (1 << ((i * 3) + (j % 4)));
		}
	}
	return ret;
}

void solved(int idx) {
	for (int i = 0; i < MAX_SIZE; i++) {
		if ((words[i] | n[idx]) == words[i])
			res[idx].push_back(i);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < 5; i++)
		cin >> str[i];

	for (int i = 0; i < N; i++) {
		n[i] = getBit(0, i * 4, i);
		solved(i);
	}

	ld sum = 0, cnt = 1, d = 1;
	for (int i = 0; i < N; i++) 
		cnt *= res[i].size();	
	for (int i = N - 1; i > -1; i--) {
		ld s = 0;
		for (auto x : res[i]) s += x;
		if (res[i].size()) sum += (s * d * (cnt / res[i].size()));
		d *= 10;
	}

	cout << ((!cnt) ? -1 : sum / (ld)cnt);

	return 0;
}