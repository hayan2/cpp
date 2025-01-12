#define LIM 21
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string oper = "";
	int S = 0, N, x;

	cin >> N;
	while (N--) {
		cin >> oper;

		if (oper == "add") {
			cin >> x;
			S |= (1 << x);
		}
		else if (oper == "remove") {
			cin >> x;
			S &= ~(1 << x);
		}
		else if (oper == "check") {
			cin >> x;

			if (S & (1 << x)) cout << "1\n";
			else cout << "0\n";
		}
		else if (oper == "toggle") {
			cin >> x;

			if (S & (1 << x)) S &= ~(1 << x);
			else S |= (1 << x);
		}
		else if (oper == "all") S = (1 << LIM) - 1;
		else if (oper == "empty") S = 0;
	}

	return 0;
}