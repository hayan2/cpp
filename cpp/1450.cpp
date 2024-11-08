#define MAX_LEN 31
#define ull unsigned long long
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int A[MAX_LEN] = { 0, };
int N, C;

void makeSet(vector<int>& set, int idx, int end, int x) {	
	if (idx == end) {
		set.push_back(x);
		return;
	}
	if (x > C) {
		return;
	}

	makeSet(set, idx + 1, end, A[idx] + x);
	makeSet(set, idx + 1, end, x);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> setA;	
	vector<int> setB;	
	ull res = 0;

	cin >> N >> C;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	makeSet(setA, 0, N / 2, 0);
	makeSet(setB, N / 2, N, 0);

	sort(setB.begin(), setB.end());

	for (int i = 0; i < setA.size(); i++) {
		res += upper_bound(setB.begin(), setB.end(), C - setA[i]) - setB.begin();
	}

	cout << res;

	return 0;
}