#define MAX_LEN 100001
#define VISITED 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

vector<int> cache(MAX_LEN, MAX_LEN);
int prevPath[MAX_LEN] = { 0, };
int visited[MAX_LEN] = { 0, };
int N;

void solved(int K) {	
	priority_queue<pair<int, int>> heap;

	heap.push({ 0, N });

	while (!heap.empty()) {
		int time = -heap.top().first;
		int pos = heap.top().second;
		heap.pop();
		visited[pos] = VISITED;

		int pushTime, pushPos;

		if (cache[pos] < time) {
			continue;
		}

		cache[pos] = time;		

		if (visited[K]) {
			break;
		}

		// go
		pushTime = time + 1;
		pushPos = pos + 1;
		if (pushPos < MAX_LEN && cache[pushPos] > pushTime) {
			heap.push({ -pushTime, pushPos });
			prevPath[pushPos] = pos;
			if (prevPath[pushPos] == 0) {
				prevPath[pushPos] = pos;
			}
		}

		// back
		pushTime = time + 1;
		pushPos = pos - 1;
		if (pushPos > -1 && cache[pushPos] > pushTime) {
			heap.push({ -pushTime, pushPos });
			if (prevPath[pushPos] == 0) {
				prevPath[pushPos] = pos;
			}			
		}

		// teleport
		pushTime = time + 1;
		pushPos = pos * 2;
		if (pushPos < MAX_LEN && cache[pushPos] > pushTime) {
			heap.push({ -pushTime, pushPos });
			if (prevPath[pushPos] == 0) {
				prevPath[pushPos] = pos;
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int K;

	cin >> N >> K;

	solved(K);

	cout << cache[K] << endl;	

	stack<int> res;
	int len = cache[K];
	res.push(K);
	for (int i = 0; i < len; i++) {
		res.push(prevPath[K]);
		K = prevPath[K];
	}

	while (!res.empty()) {
		cout << res.top() << " ";
		res.pop();
	}

	return 0;
}