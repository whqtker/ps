#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp {
	bool operator()(int a, int b) {
		if (abs(a) > abs(b))
			return true;
		else if (abs(a) == abs(b)) {
			if (a > b)
				return true;
			else
				return false;
		}
		return false;
	}
};

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	priority_queue<int,vector<int>,cmp> pq;

	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		int x;
		cin >> x;

		if (x == 0) {
			if (pq.empty())
				cout << "0\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			pq.push(x);
		}
	}
}