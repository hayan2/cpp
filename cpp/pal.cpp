#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
int res = 0;

void generatePalindromes(long long limit) {
	for (int i = 1; i < 10; ++i) {
		if (i > limit) {
			return;
		}
		res++;
	}

	int length = 1;
	while (true) {
		long long start = pow(10, length - 1);
		long long end = pow(10, length);

		for (long long i = start; i < end; ++i) {
			string s = to_string(i);
			string palindromeStr = s + string(s.rbegin(), s.rend());
			long long palindrome = stoll(palindromeStr);
			if (palindrome > limit) {
				return;
			}
			res++;
		}

		for (long long i = start; i < end; ++i) {
			string s = to_string(i);
			for (char mid = '0'; mid <= '9'; ++mid) {
				string palindromeStr = s + mid + string(s.rbegin(), s.rend());
				long long palindrome = stoll(palindromeStr);
				if (palindrome > limit) {
					return;
				}
				res++;
			}
		}
		length++;
	}
}

int main() {
	long long n;
	cin >> n;

	generatePalindromes(n);

	cout << res;

	return 0;
}