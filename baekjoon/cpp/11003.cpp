#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX_VALUE = 1000000001;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, l;
	cin >> n >> l;

	vector<int> v;
	for (int i = 0;i < n;i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	for (int i = 0;i < n;i++) {
		priority_queue<int, vector<int>, greater<int>> pq;
		for (int j = i - l + 1;j <= i;j++) {
			if (j >= 0)
				pq.push(v[j]);
			else
				pq.push(MAX_VALUE);
		}
		cout << pq.top() << " ";
	}
}