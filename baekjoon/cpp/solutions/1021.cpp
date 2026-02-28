#include <iostream>
#include <deque>
#include <vector>

using namespace std;

deque<int> leftShift(deque<int> dq) {
	int x = dq.front();
	dq.pop_front();
	dq.push_back(x);
	return dq;
}

deque<int> rightShift(deque<int> dq) {
	int x = dq.back();
	dq.pop_back();
	dq.push_front(x);
	return dq;
}

int findIdx(deque<int> dq, int x) {
	for (int i = 0; i < dq.size(); i++) {
		if (dq[i] == x)
			return i;
	}
	return -1;
}

int main() {
	int n, m;
	cin >> n >> m;

	deque<int> dq;
	vector<int> nums;

	for (int i = 0; i < n; i++) {
		dq.push_back(i + 1);
	}

	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		nums.push_back(x);
	}

	int idx = 0;
	int cnt = 0;
	while (idx <= m - 1) {
		if (dq.front() == nums[idx]) {
			dq.pop_front();
			idx++;
		}
		else {
			int i = findIdx(dq, nums[idx]);
			if (i > dq.size() / 2) {
				while (dq.front() != nums[idx]) {
					dq = rightShift(dq);
					cnt++;
				}
			}
			else {
				while (dq.front() != nums[idx]) {
					dq = leftShift(dq);
					cnt++;
				}
			}
		}
	}

	cout << cnt;
}