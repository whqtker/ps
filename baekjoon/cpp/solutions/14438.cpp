#include <iostream>
#include <algorithm>

using namespace std;

int arr[100000];
int min_seg_tree[400000];

void init(int start, int end, int node) {
	// 리프 노드인 경우
	if (start == end) {
		min_seg_tree[node] = arr[start];
		return;
	}

	// 왼쪽, 오른쪽 자식을 재귀적으로 초기화
	int mid = (start + end) / 2;
	init(start, mid, node * 2);
	init(mid + 1, end, node * 2 + 1);

	min_seg_tree[node] = min(min_seg_tree[node * 2], min_seg_tree[node * 2 + 1]);
}

// [start, end]: 현재 노드가 담당하는 범위, idx: 수정할 노드의 인덱스
void update(int start, int end, int idx, int node, int val) {
	// 범위를 벗어난 경우
	if (start > idx || idx > end)
		return;

	// 리프 노드에 도달한 경우 값 갱신
	if (start == end) {
		min_seg_tree[node] = val;
		arr[idx] = val;
		return;
	}

	if (start != end) {
		int mid = (start + end) / 2;
		update(start, mid, idx, node * 2, val);
		update(mid + 1, end, idx, node * 2 + 1, val);

		min_seg_tree[node] = min(min_seg_tree[node * 2], min_seg_tree[node * 2 + 1]);
	}
}

// [start, end]: 현재 노드가 담당하는 범위, [left, right]: 찾고자 하는 범위
int findMin(int start, int end, int left, int right, int node) {
	// 겹치지 않는 경우
	if (start > right || end < left)
		return 1e9 + 1;

	// 찾고자 하는 범위에 노드가 담당하는 범위가 포함된 경우
	if (left <= start && end <= right)
		return min_seg_tree[node];

	int mid = (start + end) / 2;
	return min(findMin(start, mid, left, right, node * 2), findMin(mid + 1, end, left, right, node * 2 + 1));
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	init(0, n - 1, 1);

	int m;
	cin >> m;
	while (m--) {
		int op;
		cin >> op;

		if (op == 1) {
			int i, v;
			cin >> i >> v;
			update(0, n - 1, i - 1, 1, v);
		}
		else {
			int i, j;
			cin >> i >> j;
			cout << findMin(0, n - 1, i - 1, j - 1, 1) << "\n";
		}
	}
}