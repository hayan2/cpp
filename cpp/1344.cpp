#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX_COMB = 19;
const int np[] = { 0, 1, 4, 6, 8, 9, 10, 12, 14, 15, 16, 18 };

int C[MAX_COMB][MAX_COMB];

void getCombinations() {
	for (int i = 0; i < MAX_COMB; i++) {
		C[i][0] = 1;
		C[i][i] = 1;
	}

	for (int i = 2; i < MAX_COMB; i++) {
		for (int j = 1; j < i; j++) {
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}
}

double solve(double p) {
	double ret = 0;
	for (auto x : np) {
		double tmp = C[18][x] * pow(p, x) * pow(1 - p, 18 - x);

		ret += tmp;
	}

	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	double pa, pb;

	cin >> pa >> pb;

	pa /= 100.0;
	pb /= 100.0;
	
	getCombinations();	
	
	double a = solve(pa);
	double b = solve(pb);

	cout.fixed;
	cout.precision(16);	
	cout << 1 - (a * b);

	return 0;
}