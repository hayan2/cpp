#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	map<int, string> history;
	history[-1] = "";

	string command, val;
	int curTime = 0;

	while (N--) {
		cin >> command >> val >> curTime;

		if (command == "type") {
			auto it = history.lower_bound(curTime);
			--it;
			history[curTime] = it->second + val;
		}
		else if (command == "undo") {
			int t = stoi(val);
			int target = curTime - t;

			auto it = history.lower_bound(target);
			if (it == history.begin()) {
				history[curTime] = "";
			}
			else {
				--it;
				history[curTime] = it->second;
			}
		}
	}
	if (history.empty() || history.rbegin()->first < 0) {
		cout << "";
	}
	else {
		cout << history.rbegin()->second;
	}
	cout << endl;

	return 0;
}