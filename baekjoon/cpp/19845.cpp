#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, q; // 세로 크기, 레이저 수
	cin >> n >> q;

	vector<int> v; // 넴모 정보
	for (int i = 0;i < n;i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());
	
	for (int i = 0;i < q;i++) {
		int x, y;
		cin >> x >> y;
		int row = v[n - y] >= x ? v[n - y] - x + 1 : 0;
		int col = v[n - y] < x ? 0 : n - (lower_bound(v.begin(), v.end(), x) - v.begin()) - y + 1;
		if (!row && !col)
			cout << 0 << "\n";
		else
			cout << row + col - 1 << "\n";
	}
}