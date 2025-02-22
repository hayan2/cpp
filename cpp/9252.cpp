#define MAX_LEN 1001
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int sccidx[MAX_LEN][MAX_LEN] = { 0, };

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	stack<char> res;
	string A, B;
	int cnt = 0;

	getline(cin, A);
	getline(cin, B);

	int sizeA = A.size();
	int sizeB = B.size();

	for (int i = 1; i <= sizeA; i++) {
		for (int j = 1; j <= sizeB; j++) {
			if (A[i - 1] == B[j - 1]) {
				sccidx[i][j] = sccidx[i - 1][j - 1] + 1;
				cnt = sccidx[i][j] > cnt ? sccidx[i][j] : cnt;
			}
			else {
				sccidx[i][j] = sccidx[i - 1][j] > sccidx[i][j - 1] ? sccidx[i - 1][j] : sccidx[i][j - 1];
			}
		}
	}

	int i = sizeA, j = sizeB;

	while (i > 0 && j > 0) {
		if (sccidx[i][j] == sccidx[i - 1][j]) {
			i--;
		}
		else if (sccidx[i][j] == sccidx[i][j - 1]) {
			j--;
		}
		else {
			res.push(A[i - 1]);
			i--;
			j--;
		}
	}

	cout << cnt << endl;
	while (!res.empty()) {
		cout << res.top();
		res.pop();
	}

	return 0;
}