#include <iostream>
#include <algorithm>

using namespace std;
using lli = long long int;
const lli INF = 1e9 + 7;
const int MAX_SIZE = 10001;

typedef struct pos {
	lli x, y;

	void read() { cin >> x >> y; }
}pos;

pos point[MAX_SIZE], cache[5], s, e;

bool operator > (pos a, pos b) {
	if (a.x == b.x) return a.y > b.y;
	else return a.x > b.x;
}

bool operator <= (pos a, pos b) {
	if (a.x == b.x) return a.y <= b.y;
	else return a.x < b.x;
}

int ccw(pos p1, pos p2, pos p3) {
	int tmp = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
	tmp = tmp - p1.y * p2.x - p2.y * p3.x - p3.y * p1.x;

	if (tmp > 0) return 1;
	else if (tmp < 0) return -1;
	else return 0;
}

bool solved(pos a, pos b, pos c, pos d) {
	int l1 = ccw(a, b, c) * ccw(a, b, d);
	int l2 = ccw(c, d, a) * ccw(c, d, b);

	if (l1 == 0 && l2 == 0) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		if (c > b || a > d) return false;

		return a <= d && c <= b;
	}	
	else return l1 <= 0 && l2 <= 0;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	for (int i = 1; i <= N; i++) point[i].read();
	for (int i = 1; i < 4; i++) cache[i].read();

	for (int i = 1; i < 4; i++) {
		s = cache[i];
		e.x = INF;
		e.y = cache[i].y + 1;

		bool flag = false;
		int cnt = 0;
		for (int j = 1; j <= N; j++) {
			pos p1 = point[j];
			pos p2 = point[j + 1];
			if (j == N) p2 = point[1];

			if (s.x == p1.x && s.y == p1.y) flag = true;
			else if (s.x == p2.x && s.y == p2.y) flag = true;

			if (flag) {
				cout << "1\n";
				break;
			}

			if (solved(s, e, p1, p2)) cnt++;
		}
		if (flag) continue;
		if (!(cnt & 1)) cout << "0\n";
		else cout << "1\n";
	}

	return 0;
}