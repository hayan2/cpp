#include <iostream>
#include <algorithm>
#include <regex>
#include <string>

using namespace std;

string root;
regex re("(100+1+|01)+");

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
			
	int T;

	cin >> T;

	while (T--) {		
		cin >> root;

		cout << (regex_match(root, re) ? "YES\n" : "NO\n");
	}

	return 0;
}