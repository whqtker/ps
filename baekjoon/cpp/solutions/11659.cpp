#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;
	
	vector<int> v; // 누적 합을 저장하는 벡터, v[i]: 1번 째부터 i번 째까지 원소의 합
	v.push_back(0);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x + v[i]);
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << v[b] - v[a - 1] << "\n";
	}
}