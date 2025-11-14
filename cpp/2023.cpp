#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

const int INF = 1e9 + 7;

int prime[] = { 2, 3, 5, 7 };
int N;

bool isPrime(int n) {
	if (n <= 1 || !(n % 2)) return false;	
	if (n == 2) return true;	
	for (int i = 3; i * i <= n; i += 2) {
		if (!(n % i)) return false;
	}

	return true;
}

void solve(int n, int d) {
	if (!isPrime(n) && n != 2) return;
	if (d == N) {
		cout << n << "\n";
		return;
	}

	for (int i = 1; i <= 9; i += 2) {
		solve(n * 10 + i, d + 1);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < 4; i++) solve(prime[i], 1);

	return 0;
}