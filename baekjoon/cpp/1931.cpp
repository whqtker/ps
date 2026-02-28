#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<pair<int, int>> v;
	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ b,a }); // 종료, 시작 순으로 저장
	}
	sort(v.begin(), v.end());

	int time = v[0].first;
	int cnt = 1;
	for (int i = 1;i < n;i++) {
		if (time <= v[i].second) {
			time = v[i].first;
			cnt++;
		}
	}
	cout << cnt;

}