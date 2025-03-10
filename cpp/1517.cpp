#include <iostream>
#include <algorithm>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<pair<int, int>> save;
vector<int> tree;
long long ans;

// 세그먼트 트리 갱신
void update(int node, int start, int end, int idx) {
	// 리프 노드에 도달한 경우
	if (start == end) {
		tree[node] = 1;
		return;
	}
	int mid = (start + end) / 2;

	// node의 왼쪽 자식 idx = node * 2, 오른쪽 자식 idx = node * 2 + 1
	// 왼쪽으로 update 하면 start~mid 사이의 구간 합을 node * 2에 저장
	// 오른쪽으로 update 하면 mid+1~end 사이의 구간 합을 node * 2 + 1에 저장
	if (idx <= mid) update(node * 2, start, mid, idx);
	else update(node * 2 + 1, mid + 1, end, idx);

	// 현재 node의 구간 합은 자식 노드들의 합과 같다..
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}


// 세그먼트 트리 탐색
long long query(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];

	long long mid = (start + end) / 2;
	long long left_sum = query(node * 2, start, mid, left, right);
	long long right_sum = query(node * 2 + 1, mid + 1, end, left, right);
	return left_sum + right_sum;
}

int main() {
	FastIO

	cin >> N;

	// 세그먼트 트리 노드 갯수 = 2^(세그먼트 트리 깊이 = ceil(log2(N)) + 1)
	int tree_depth = 1 << ((int)ceil(log2(N)) + 1);
	tree = vector<int>(tree_depth);

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;

		// 0~10억 범위 대신 index 범위 0~50만으로 '좌표 압축'
		save.emplace_back(temp, i);
	}

	// ★세그먼트 트리 기준 : 자신보다 먼저 갱신된 값들의 구간 합
	// 정렬을 하는 이유 : 가장 작은 값부터 넣으면서 자신보다 인덱스가 앞이고 큰 값이 들어갈 때마다 뒤에 있는 모든 값들의 합만큼 갱신한다.
	// ★큰 값이 세그먼트 트리에 들어가면서, 앞쪽 인덱스에 들어가는 경우 [해당 인덱스 + 1, N - 1]에 위치한 모든 구간의 합 만큼을 정답에 더한다.
	// 왜나하면 뒤에서 갱신된 현재 값들보다 작은 값들에게 있어서 앞쪽 인덱스에 더 큰 값이 하나 더 생기는 꼴이기 때문이다.
	// 위의 과정에서 세그먼트 트리를 필요로 한다.
	sort(save.begin(), save.end());

	for (int i = 0; i < N; i++) {
		// 현재 값의 index
		int idx = save[i].second;

		// query(시작 노드, (탐색 가능 범위), (탐색 범위)) : 루트 노드가 1이며, [idx+1 ~ N-1] 구간 합을 return한다.
		ans += query(1, 0, N - 1, idx + 1, N - 1);
		// update(시작 노드, (범위), 목적지) : idx 위치까지 +1 하면서 파고 들어감. O(log2(N))
		update(1, 0, N - 1, idx);
	}

	cout << ans;

	return 0;
}