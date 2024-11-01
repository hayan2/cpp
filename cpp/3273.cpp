#define MAX_LEN 100001
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int A[MAX_LEN];
	int n, x, res = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	cin >> x;

	sort(A, A + n);
	int low = 0, high = n - 1;

	while (low < high) {
		if (A[low] + A[high] > x) {
			high--;			
		}
		else if (A[low] + A[high] < x) {
			low++;
		}
		else if (A[low] + A[high] == x) {
			res++;
			low++;
			high--;
		}
	}

	cout << res;
  
	return 0;
}