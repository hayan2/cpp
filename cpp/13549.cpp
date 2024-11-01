#define _CRT_SECURE_NO_WARNINGS
#define MAX_LEN 100001
#define VISITED 1
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int go(int x) {
	return x + 1;
}

int back(int x) {
	return x - 1;
}

int tel(int x) {
	return x * 2;
}

int visited[MAX_LEN] = { 0, };

int sol(int N, int K) {
	vector<int> ret(MAX_LEN, MAX_LEN);
	priority_queue<pair<int, int>> heap;

	heap.push({ 0, N });

	while (!heap.empty()) {
		int time = -heap.top().first;
		int pos = heap.top().second;
		heap.pop();
		visited[pos] = VISITED;

		int pushTime, pushPos;

		if (ret[pos] < time) {
			continue;
		}
		
		ret[pos] = time;

		if (visited[K]) {
			break;
		}
		// go
		pushTime = time + 1;
		pushPos = go(pos);
		if (pushPos < MAX_LEN && ret[pushPos] > pushTime) {
			heap.push({ -pushTime, pushPos });
		}
		// back
		pushTime = time + 1;
		pushPos = back(pos);
		if (pushPos >= 0 && ret[pushPos] > pushTime) {
			heap.push({ -pushTime, pushPos });
		}
		// teleport
		pushTime = time;
		pushPos = tel(pos);
		if (pushPos < MAX_LEN && ret[pushPos] > pushTime) {
			heap.push({ -pushTime, pushPos });
		}
	}

	return ret[K];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;

	cin >> N >> K;

	cout << sol(N, K);

	return 0;
}