#include <iostream>
#include <map>
#include <vector>

using namespace std;

int arr[100000];

int main() {
	int n;
	cin >> n;
	map<int, int> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		m[arr[i]]++;
	}

	vector<vector<int>> guide = { {1, 2, 3},{1, 3, 2},{2, 1, 3},{2, 3, 1},{3, 1, 2},{3, 2, 1} };

	int ans = 2e9;
	for (int i = 0; i < 6; i++) {
		// guide를 기반으로 연속된 1, 2, 3의 수열을 만든다.
		vector<int> cmp;
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < m[guide[i][j]]; k++) {
				cmp.push_back(guide[i][j]);
			}
		}

		// arr - cmp 간 같은 인덱스 원소 쌍을 관리한다.
		map<pair<int, int>, int> pairs;
		for (int j = 0; j < n; j++) {
			pairs[{arr[j], cmp[j]}]++;
		}

		int cnt = 0;
		// {a, b}, {b, a} 는 한 번의 교환으로 매칭시킬 수 있다.
		while (pairs[{1, 2}] > 0 && pairs[{2, 1}] > 0) {
			pairs[{1, 2}]--;
			pairs[{2, 1}]--;
			cnt++;
		}

		while (pairs[{3, 2}] > 0 && pairs[{2, 3}] > 0) {
			pairs[{3, 2}]--;
			pairs[{2, 3}]--;
			cnt++;
		}

		while (pairs[{1, 3}] > 0 && pairs[{3, 1}] > 0) {
			pairs[{1, 3}]--;
			pairs[{3, 1}]--;
			cnt++;
		}

		// {a, b}, {b, c}, {c, a}는 두 번의 교환으로 매칭시킬 수 있다.
		int sum = 0;
		for (auto e : pairs) {
			// 쌍이 맞지 않은 경우만
			if (e.first.first - e.first.second != 0)
				sum += e.second;
		}
		cnt += sum / 3 * 2;

		ans = min(ans, cnt);
	}

	cout << ans;
}