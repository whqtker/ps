#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

int l, r, c;

int main() {
	while (1) {
		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0)
			break;

		int sl = 0, sr = 0, sc = 0; // 시작 위치
		vector<vector<vector<char>>> v;
		for (int i = 0;i < l;i++) {
			vector<vector<char>> tmp(r, vector<char>(c));
			for (int j = 0;j < r;j++) {
				for (int k = 0;k < c;k++) {
					char x;
					cin >> x;

					if (x == 'S') {
						sl = i;
						sr = j;
						sc = k;
					}
					tmp[j][k] = x;
				}
			}
			v.push_back(tmp);
		}

		vector<vector<vector<int>>> visited(l, vector<vector<int>>(r, vector<int>(c)));
		queue<tuple<int, int, int>> q;
		q.push({ sl,sr,sc });
		bool flag = false;

		while (!q.empty()) {
			int f = get<0>(q.front());
			int x = get<1>(q.front());
			int y = get<2>(q.front());

			if (v[f][x][y] == 'E') {
				cout << "Escaped in " << visited[f][x][y] << " minute(s)." << "\n";
				flag = true;
				break;
			}

			if (f - 1 >= 0 && visited[f - 1][x][y] == 0 && v[f - 1][x][y] != '#') {
				q.push({ f - 1,x,y });
				visited[f - 1][x][y] = visited[f][x][y] + 1;
			}
			if (f + 1 < l && visited[f + 1][x][y] == 0 && v[f + 1][x][y] != '#') {
				q.push({ f + 1,x,y });
				visited[f + 1][x][y] = visited[f][x][y] + 1;
			}
			if (x - 1 >= 0 && visited[f][x - 1][y] == 0 && v[f][x - 1][y] != '#') {
				q.push({ f,x - 1,y });
				visited[f][x - 1][y] = visited[f][x][y] + 1;
			}
			if (x + 1 < r && visited[f][x + 1][y] == 0 && v[f][x + 1][y] != '#') {
				q.push({ f ,x + 1,y });
				visited[f][x + 1][y] = visited[f][x][y] + 1;
			}
			if (y - 1 >= 0 && visited[f][x][y - 1] == 0 && v[f][x][y - 1] != '#') {
				q.push({ f ,x,y - 1 });
				visited[f][x][y - 1] = visited[f][x][y] + 1;
			}
			if (y + 1 < c && visited[f][x][y + 1] == 0 && v[f][x][y + 1] != '#') {
				q.push({ f ,x,y + 1 });
				visited[f][x][y + 1] = visited[f][x][y] + 1;
			}
			q.pop();
		}

		if (!flag)
			cout << "Trapped!" << "\n";
	}
}