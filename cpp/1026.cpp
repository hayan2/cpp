#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 51;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int A[MAX_N], B[MAX_N];

	cin >> N;

	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) cin >> B[i];

	sort(A, A + N);
	sort(B, B + N, greater<int>());

	int res = 0;
	for (int i = 0; i < N; i++)	res += (A[i] * B[i]);
	cout << res;

	return 0;
}