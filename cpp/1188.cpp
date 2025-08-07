#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	if (!b) return a;
	else return gcd(b, a % b);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;

	cin >> N >> M;
	
	int g = gcd(N, M);
	int m = M / g;

	cout << (m - 1) * g;

	return 0;
}