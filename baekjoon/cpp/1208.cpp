#include <iostream>
#include <vector>
#include <map>

using namespace std;

int arr[41];
int n, s;
map<int, int> m;
long long ans;

// 왼쪽 부분수열의 합
void left(int idx, int sum) {
	if (idx == n / 2) {
		m[sum]++;
		return;
	}

	left(idx + 1, sum);
	left(idx + 1, sum + arr[idx]);
}

// 오른쪽 부분수열의 합
void right(int idx, int sum) {
	if (idx == n) {
		ans += m[s - sum];
		return;
	}

	right(idx + 1, sum);
	right(idx + 1, sum + arr[idx]);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> s;

	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}

	left(0, 0);
	right(n / 2, 0);

	if (s == 0)
		ans--;

	cout << ans;
}