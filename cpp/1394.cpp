#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <math.h>

using namespace std;
using ll = long long;
const int MOD = 900528;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<char, int> cache;
	string str, key;	
	cin >> str >> key;

	ll M = str.length();
	ll len = key.length();
	for (int i = 0; i < M; i++) cache[str[i]] = i;	

	ll res = 0, pom = 1;
	for (int i = 1; i < len; i++) {
		pom = (pom * M) % MOD;
		res = (res + pom) % MOD;
	}

	ll rank = 0;
	for (char c : key) rank = (rank * M + cache[c]) % MOD;
	res = (res + rank + 1) % MOD;
	cout << res;

	return 0;
}