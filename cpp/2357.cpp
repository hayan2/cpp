#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

#define ull unsigned long long

vector<ull> smax;
vector<ull> smin;
int N, M;

void init() {
	int x = ceil(log2(N));
	int height = (1 << (x + 1));
	smax.resize(height);
	smin.resize(height);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	init();



	return 0;
}