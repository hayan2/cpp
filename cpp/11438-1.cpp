#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a = 4, b = 4, c = 5;

	cout << (a & b) << "\n";
	cout << (a & c);

	return 0;
}