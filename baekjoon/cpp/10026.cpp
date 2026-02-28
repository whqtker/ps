#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool outOfBound(int i, int j, int n) {
	if (i < 0 || j < 0 || i >= n || j >= n)
		return true;
	else
		return false;
}

char isSame(vector<char> v) {
	vector<char> red(4, 'R');
	vector<char> green(4, 'G');
	vector<char> blue(4, 'B');

	if (v == red && v == green)
		return 'B';
	else if (v == green && v == blue)
		return 'R';
	else if (v == red && v == blue)
		return 'G';
	else
		return 'X';

}

void bfs(vector<string> v, int n) {
	vector<vector<int>> visited(n, vector<int>(n, 0));
	queue<pair<int, int>> q;
	int cnt = 0;

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			char start = v[i][j];
			if (visited[i][j] == 0) {
				visited[i][j] = 1;
				q.push({ i,j });
				cnt++;

				while (!q.empty()) {
					vector<char> near;
					int x = q.front().first;
					int y = q.front().second;
					if (!outOfBound(x - 1, y, n) && visited[x - 1][y] == 0 && v[x - 1][y] == start) {
						q.push({ x - 1,y });
						visited[x - 1][y] = 1;
						near.push_back(v[x - 1][y]);
					}
					if (!outOfBound(x + 1, y, n) && visited[x + 1][y] == 0 && v[x + 1][y] == start) {
						q.push({ x + 1,y });
						visited[x + 1][y] = 1;
						near.push_back(v[x + 1][y]);
					}
					if (!outOfBound(x, y - 1, n) && visited[x][y - 1] == 0 && v[x][y - 1] == start) {
						q.push({ x,y - 1 });
						visited[x][y - 1] = 1;
						near.push_back(v[x][y - 1]);
					}
					if (!outOfBound(x, y + 1, n) && visited[x][y + 1] == 0 && v[x][y + 1] == start) {
						q.push({ x, y + 1 });
						visited[x][y + 1] = 1;
						near.push_back(v[x][y + 1]);
					}

					if (isSame(near) == 'R' && start != 'R') {
						cnt--;
					}
					else if (isSame(near) == 'G' && start != 'G') {
						cnt--;
					}
					else if (isSame(near) == 'B' && start != 'B') {
						cnt--;
					}

					q.pop();
				}
			}
		}
	}

	cout << cnt << " ";
}

int main() {
	int n;
	cin >> n;

	vector<string> v;
	for (int i = 0;i < n;i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}
	bfs(v, n);

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (v[i][j] == 'G')
				v[i][j] = 'R';
		}
	}
	bfs(v, n);
}