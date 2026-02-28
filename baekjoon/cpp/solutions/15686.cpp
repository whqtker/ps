#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m;
int ans = 1301;
vector<pair<int, int>> house, chicken;
vector<int> selected; // 선택한 치킨집의 인덱스
vector<int> visited(13); // 선택한 치킨집 여부

void dfs(int idx, int cnt) {
	if (cnt == m) {
		int total = 0;
		for (int i = 0;i < house.size();i++) {
			int d = 101;
			for (int j = 0;j < cnt;j++) {
				d = min(d, abs(house[i].first - chicken[selected[j]].first) + abs(house[i].second - chicken[selected[j]].second));
			}
			total += d;
		}

		ans = min(ans, total);
	}

	for (int i = idx;i < chicken.size();i++) {
		if (visited[i] == 1)
			continue;
		else {
			visited[i] = 1;
			selected.push_back(i);
			dfs(i, cnt + 1);
			visited[i] = 0;
			selected.pop_back();
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			int x;
			cin >> x;
			if (x == 1)
				house.push_back({ i,j });
			else if (x == 2)
				chicken.push_back({ i,j });
		}
	}

	dfs(0, 0);
	cout << ans;
}