#include <iostream>
#include <algorithm>

using namespace std;
using lli = long long int;
const int DICE = 6;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	lli dice[DICE];
	lli res = 0, N;
	cin >> N;

	for (int i = 0; i < DICE; i++) cin >> dice[i];

	if (N == 1) {
		sort(dice, dice + DICE);
		for (int i = 0; i < 5; i++) res += dice[i];				
	}
	else {
		lli cache[3];
		cache[0] = min(dice[0], dice[5]);
		cache[1] = min(dice[1], dice[4]);
		cache[2] = min(dice[2], dice[3]);
		sort(cache, cache + 3);
		res += (cache[0] + cache[1] + cache[2]) * 4;
		res += (cache[0] + cache[1]) * ((N - 2) * 8 + 4);
		res += (cache[0] * (((N - 2) * (N - 2) * 5) + ((N - 2) * 4)));		
	}

	cout << res;

	return 0;
}