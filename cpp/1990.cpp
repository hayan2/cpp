	#include <iostream>
	#include <algorithm>
	#include <string>
	#include <string.h>
	#include <vector>
	#include <cmath>

	using namespace std;
	using ll = long long;
	using ull = unsigned long long;
	using pii = pair<int, int>;

	const int INF = 1e9 + 7;

	bool isPrime(ll n) {
		if (n <= 1) return false;
		if (n <= 3) return true;
		if (!(n % 2) || !(n % 3)) return false;
		for (ll i = 5; i * i <= n; i += 6) {
			if (!(n % i) || !(n % (i + 2))) return false;
		}

		return true;
	}//
	//
	int main(void) {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		ll a, b;
		cin >> a >> b;

		vector<ll> res;
		for (int i = 1; ; i++) {
			string s = to_string(i);
			string t = s;
			reverse(t.begin(), t.end());
		
			ll pal = stoll(s + t.substr(1));
			if (pal > b) break;

			if (pal >= a && isPrime(pal)) res.push_back(pal);

			pal = stoll(s + t);
			if (pal > b) continue;

			if (pal >= a && isPrime(pal)) res.push_back(pal);
		}

		sort(res.begin(), res.end());
		for (auto p : res) cout << p << "\n";
		cout << "-1";

		return 0;
	}