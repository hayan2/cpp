#define MAX_LEN 100001
#define KEY 0
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A[MAX_LEN] = { 0, };
	int N, pH = INT_MAX, sol1 = 0, sol2 = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	sort(A, A + N);

	int low = 0, high = N - 1;

	while (low < high) {
		if (abs(pH) > abs(A[low] + A[high])) {
			pH = A[low] + A[high];
			sol1 = low;
			sol2 = high;
		}

		if (A[low] + A[high] > KEY) {
			high--;
		}
		else if (A[low] + A[high] < KEY) {
			low++;
		}
		else {
			sol1 = low;
			sol2 = high;
			pH = KEY;
			break;
		}
	}

	cout << A[sol1] << " " << A[sol2];

	return 0;
}