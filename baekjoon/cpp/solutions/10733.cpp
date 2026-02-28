#include <iostream>
#include <stack>

using namespace std;

int main() {
	int n;
	cin >> n;

	//cin.ignore();
	stack<int> result;
	for (int i = 0;i < n;i++) {
		int num;
		cin >> num;

		if (num != 0) {
			result.push(num);
		}
		else {
			result.pop();
		}
	}

	int ans = 0;
	int limit = result.size();
	for (int i = 0;i < limit;i++) {
		ans += result.top();
		result.pop();
	}

	cout << ans;
}