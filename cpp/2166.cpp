#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef struct Coordinate {
	double x, y;
}Coordinate;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout.precision(1);
	
	double res = 0;
	double x, y, pSum = 0, pSub = 0;
	int N;

	cin >> N;
	vector<Coordinate> p;

	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		p.push_back({ x, y });
	}

	p.push_back({ p[0].x, p[0].y });
	
	for (int i = 0; i < N; i++) {
		pSum += (p[i].x * p[i + 1].y);
		pSub += (p[i].y * p[i + 1].x);
	}

	res = abs(pSum - pSub) / 2;
	cout << res;

	return 0;
}