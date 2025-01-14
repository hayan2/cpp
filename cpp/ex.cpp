#include <iostream>
#include <algorithm>

using namespace std;

int res = 0;

int solved(int x) {
	if (x == 5) return 1;
	x++;
	res += solved(x);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cout << res;

	return 0;
}