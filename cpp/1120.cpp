#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int INF = 1e9;

string A, B;

int solve(int s) {
	int ret = 0;

	for (int i = 0; i < A.size(); i++) {
		if (A[i] != B[i + s]) ret++;
	}

	return ret;
}
//
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> A >> B;
	//
	int res = INF;

	for (int i = 0; i < B.size() - A.size() + 1; i++) {
		res = min(res, solve(i));
	}
	///////
	cout << res;

	return 0;
}