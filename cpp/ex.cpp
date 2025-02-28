#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int S = 5;
	//
	S &= ~(1 << 2);

	cout << S;

	return 0;
}