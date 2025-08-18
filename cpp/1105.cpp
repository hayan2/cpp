#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string L, R;
	int res = 0;

	cin >> L >> R;
	
	if (L.size() != R.size()) cout << "0";
	else {
		for (int i = 0; i < L.size(); i++) {
			if (L[i] != R[i]) break;
			else if (L[i] == R[i] && L[i] == '8') res++;
		}

		cout << res;
	}

	return 0;
}