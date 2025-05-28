#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, F;

	cin >> N >> F;

	int r = N / 100;
	int tmp = r * 100;
		
	while ((tmp % F)) tmp++;

	cout << (tmp % 100) / 10 << tmp % 10;

	return 0;
}