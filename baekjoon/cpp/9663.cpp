#include <iostream>

using namespace std;

int n;
int col[16]; // 퀸은 각 행 또는 열에 하나씩 있어야 하며 대각선으로 만나도록 배치하면 안 된다.
int ans = 0;

bool cond(int k) {
	for (int i = 0;i < k;i++) {
		if (col[i] == col[k] || abs(col[k] - col[i]) == k - i) {
			return false;
		}
	}
	return true;
}

void bt(int k) {
	if (n == k) {
		ans++;
		return;
	}

	for (int i = 0;i < n;i++) {
		col[k] = i;
		if (cond(k))
			bt(k + 1);
	}
}

int main() {
	cin >> n;

	bt(0);
	cout << ans;
}