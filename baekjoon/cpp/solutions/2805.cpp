#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> tree;
	for (int i = 0;i < n;i++) {
		int x;
		cin >> x;
		tree.push_back(x);
	}

	sort(tree.begin(), tree.end());

	int l = 0;
	int r = tree[tree.size() - 1];
	int mid;
	while (l <= r) {
		mid = l + (r - l) / 2;
		unsigned long long h = 0;
		for (int i = 0;i < n;i++) {
			// 만약 잘린다면
			if (tree[i] - mid > 0) {
				h += tree[i] - mid;
			}

			// 잘린 길이가 목표 길이보다 클 경우 굳이 계속할 필요없음 (오버플로우 방지)
			if (h > m) break;
		}

		if (h > m) {
			if (l == mid) break;
			l = mid;
		}
		else if (h < m) {
			if (r == mid) break;
			r = mid;
		}
		else break;
	}

	cout << mid;
}