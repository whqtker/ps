#include <iostream>

typedef long long ll;
using namespace std;

ll arr[1000000];
ll seg_tree[4000000];

// start, end는 arr의 인덱스, node는 seg_tree의 인덱스
ll init(int start, int end, int node) {
	if (start == end)
		return seg_tree[node] = arr[start];

	int mid = (start + end) / 2;

	return seg_tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

ll sum(int start, int end, int node, int left, int right) {
	// 범위를 벗어난 경우
	if (start > right || end < left)
		return 0;

	// 범위 안에 있는 경우
	if (left <= start && end <= right)
		return seg_tree[node];

	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int idx, ll value) {
	// 범위를 벗어난 경우
	if (start > idx || end < idx)
		return;

	arr[idx] = value;
	seg_tree[node] = value;

	if (start != end) {
		int mid = (start + end) / 2;
		update(start, mid, node * 2, idx, value);
		update(mid + 1, end, node * 2 + 1, idx, value);
		seg_tree[node] = seg_tree[node * 2] + seg_tree[node * 2 + 1];
	}
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	init(0, n - 1, 1);

	for (int i = 0; i < m + k; i++) {
		ll x, a, b;
		cin >> x;
		if (x == 1) {
			cin >> a >> b;
			update(0, n - 1, 1, a - 1, b);
		}
		else if (x == 2) {
			cin >> a >> b;
			cout << sum(0, n - 1, 1, a - 1, b - 1) << "\n";
		}
	}
}