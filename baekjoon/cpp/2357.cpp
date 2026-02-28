#include <iostream>
#include <algorithm>

using namespace std;

int arr[100000];
int min_seg_tree[400000];
int max_seg_tree[400000];

void init(int start, int end, int node) {
	if (start == end) {
		min_seg_tree[node] = arr[start];
		max_seg_tree[node] = arr[start];
		return;
	}

	int mid = (start + end) / 2;
	init(start, mid, node * 2);
	init(mid + 1, end, node * 2 + 1);

	min_seg_tree[node] = min(min_seg_tree[node * 2], min_seg_tree[node * 2 + 1]);
	max_seg_tree[node] = max(max_seg_tree[node * 2], max_seg_tree[node * 2 + 1]);
	return;
}

int findMin(int start, int end, int left, int right, int node) {
	if (start > right || end < left)
		return 1e9 + 1;

	if (left <= start && end <= right)
		return min_seg_tree[node];

	int mid = (start + end) / 2;
	return min(findMin(start, mid, left, right, node * 2), findMin(mid + 1, end, left, right, node * 2 + 1));
}

int findMax(int start, int end, int left, int right, int node) {
	if (start > right || end < left)
		return 0;

	if (left <= start && end <= right)
		return max_seg_tree[node];

	int mid = (start + end) / 2;
	return max(findMax(start, mid, left, right, node * 2), findMax(mid + 1, end, left, right, node * 2 + 1));
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	init(0, n - 1, 1);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << findMin(0, n - 1, a - 1, b - 1, 1) << " " << findMax(0, n - 1, a - 1, b - 1, 1) << "\n";
	}
}