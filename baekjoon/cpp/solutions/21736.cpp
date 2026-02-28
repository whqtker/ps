#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool outOfBound(int y, int x, int n, int m) {
	if (x < 0 || y < 0 || x >= m || y >= n) return true;
	else return false;
}

void dfs(vector<string> v, int x, int y, int n, int m) {
	vector<vector<int>> visited(n, vector<int>(m, 0));
	visited[y][x] = 1;
	int cnt = 0;
	stack<pair<int, int>> s;
	s.push({ x,y });

	while (!s.empty()) {
		int curX = s.top().first;
		int curY = s.top().second;
		s.pop();

		// 인덱스 벗어나면 안 됨, 방문 안한 노드로 가야 함, 벽이면 못 감
		if (!outOfBound(curY + 1, curX, n, m) && visited[curY + 1][curX] == 0 && v[curY + 1][curX] != 'X') {
			visited[curY + 1][curX] = 1;
			s.push({ curX,curY + 1 });
			if (v[curY + 1][curX] == 'P') cnt++;
		}
		if (!outOfBound(curY - 1, curX, n, m) && visited[curY - 1][curX] == 0 && v[curY - 1][curX] != 'X') {
			visited[curY - 1][curX] = 1;
			s.push({ curX,curY - 1 });
			if (v[curY - 1][curX] == 'P') cnt++;
		}
		if (!outOfBound(curY, curX + 1, n, m) && visited[curY][curX + 1] == 0 && v[curY][curX + 1] != 'X') {
			visited[curY][curX + 1] = 1;
			s.push({ curX + 1,curY });
			if (v[curY][curX + 1] == 'P') cnt++;
		}
		if (!outOfBound(curY, curX - 1, n, m) && visited[curY][curX - 1] == 0 && v[curY][curX - 1] != 'X') {
			visited[curY][curX - 1] = 1;
			s.push({ curX - 1,curY });
			if (v[curY][curX - 1] == 'P') cnt++;
		}
	}

	if (cnt == 0) cout << "TT";
	else cout << cnt;
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<string> v;
	int x, y; // 시작 좌표
	for (int i = 0;i < n;i++) {
		string s;
		cin >> s;
		v.push_back(s);

		if (s.find('I') != string::npos) {
			x = s.find('I');
			y = i;
		}
	}

	dfs(v, x, y, n, m);
}