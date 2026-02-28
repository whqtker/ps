#include <iostream>

typedef long long ll;
using namespace std;

ll arr[1000000];
ll seg_tree[4000000];

void init(int start, int end, int node) {
	if (start == end) {
		seg_tree[node] = arr[start];
		return;
	}

	int mid = (start + end) / 2;
	init(start, mid, node * 2);
	init(mid + 1, end, node * 2 + 1);

	seg_tree[node] = (seg_tree[node * 2] * seg_tree[node * 2 + 1]) % 1000000007;
}

ll mul(int start, int end, int left, int right, int node) {
	if (right < start || end < left)
		return 1;

	if (left <= start && end <= right)
		return seg_tree[node];

	int mid = (start + end) / 2;
	return (mul(start, mid, left, right, node * 2) * mul(mid + 1, end, left, right, node * 2 + 1)) % 1000000007;
}

void update(int start, int end, int idx, int node, ll val) {
	if (start > idx || idx > end)
		return;

	arr[idx] = val;
	seg_tree[node] = val;

	if (start != end) {
		int mid = (start + end) / 2;
		update(start, mid, idx, node * 2, val);
		update(mid + 1, end, idx, node * 2 + 1, val);

		seg_tree[node] = (seg_tree[node * 2] * seg_tree[node * 2 + 1]) % 1000000007;
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
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 1) {
			update(0, n - 1, b - 1, 1, c);
		}
		else {
			cout << mul(0, n - 1, b - 1, c - 1, 1) << "\n";
		}
	}
}