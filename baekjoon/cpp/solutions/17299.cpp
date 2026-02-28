#include <iostream>
#include <stack>

using namespace std;

int arr[1000001];
int cnt[1000001];
int ans[1000001];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		cnt[arr[i]]++;
	}

	stack<int> s;
	for (int i = n - 1; i >= 0; i--) {
		int cur = arr[i];
		while (!s.empty()) {
			int x = s.top();
			if (cnt[x] <= cnt[cur])
				s.pop();
			else
				break;
		}

		if (s.empty())
			ans[i] = -1;
		else
			ans[i] = s.top();
		
		s.push(cur);
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
}