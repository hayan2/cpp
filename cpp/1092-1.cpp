#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> cache(5);
	cache[0] = 4;
	cache[1] = 4;
	cache[2] = 4;
	cache[3] = 4;
	cache[4] = 5;
	int l = 3;
	
	int ub = upper_bound(cache.begin(), cache.end(), l) - cache.begin() - 1;
	
	cout << ub;

	return 0;
}