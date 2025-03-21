#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define ll unsigned long long
#define MAX_LEN 10
#define TIMES 3

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string color[MAX_LEN] = { "black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white" };
	string x;
	int cache[TIMES] = { 0, };
	ll res = 0;

	for (int i = 0; i < TIMES; i++) {
		cin >> x;
		for (int j = 0; j < MAX_LEN; j++) {
			if (color[j] == x) cache[i] = j;
		}
	}

	res = cache[0] * 10 + cache[1];
	for (int i = 0; i < cache[2]; i++) res *= 10;
	cout << res;

	return 0;
}