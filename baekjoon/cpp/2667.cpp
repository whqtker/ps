#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool outOfBound(int row, int col, int n) {
	if (row < 0 || col < 0 || row >= n || col >= n)
		return true;
	else
		return false;
}

void bfs(vector<string> v, int n) {
	vector<vector<int>> visited(n, vector<int>(n, 0));
	queue<pair<int, int>> q;
	int row;
	int col;

	vector<pair<int, int>> house;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (v[i][j] == '1')
				house.push_back({ i,j });
		}
	}

	vector<int> complex;
	for (int i = 0;i < house.size();i++) {
		row = house[i].first;
		col = house[i].second;
		if (visited[row][col] == 0) {
			q.push(house[i]);
			visited[row][col] = 1;

			int cnt = 1;
			while (!q.empty()) {
				row = q.front().first;
				col = q.front().second;

				if (!outOfBound(row + 1, col, n) && v[row + 1][col] == '1' && visited[row + 1][col] == 0) {
					q.push({ row + 1,col });
					visited[row + 1][col] = 1;
					cnt++;
				}
				if (!outOfBound(row - 1, col, n) && v[row - 1][col] == '1' && visited[row - 1][col] == 0) {
					q.push({ row - 1,col });
					visited[row - 1][col] = 1;
					cnt++;
				}
				if (!outOfBound(row, col + 1, n) && v[row][col + 1] == '1' && visited[row][col + 1] == 0) {
					q.push({ row,col + 1 });
					visited[row][col + 1] = 1;
					cnt++;
				}
				if (!outOfBound(row, col - 1, n) && v[row][col - 1] == '1' && visited[row][col - 1] == 0) {
					q.push({ row,col - 1 });
					visited[row][col - 1] = 1;
					cnt++;
				}

				q.pop();
			}
			complex.push_back(cnt);
		}
	}

	cout << complex.size() << "\n";
	sort(complex.begin(), complex.end());
	for (int i = 0;i < complex.size(); i++) {
		cout << complex[i] << "\n";
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	vector<string> v;
	for (int i = 0;i < n;i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}

	bfs(v, n);
}