#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int r, c;

int main() {
	cin >> r >> c;

	queue<pair<int, int>> q, fire; // ÁöÈÆ, ºÒ
	vector<vector<char>> v(r, vector<char>(c)); // ¹Ì·Î
	for (int i = 0;i < r;i++) {
		for (int j = 0;j < c;j++) {
			char x;
			cin >> x;
			v[i][j] = x;

			if (x == 'J') {
				q.push({ i,j });
			}
			else if (x == 'F')
				fire.push({ i,j });
		}
	}

	int a = q.front().first;
	int b = q.front().second;
	if (a == 0 || a == r - 1 || b == 0 || b == c - 1) {
		cout << 1;
		return 0;
	}

	vector<vector<int>> time(r, vector<int>(c));
	vector<vector<int>> fireTime(r, vector<int>(c));

	while (!fire.empty()) {
		int x = fire.front().first;
		int y = fire.front().second;

		if (x - 1 >= 0 && v[x - 1][y] != '#' && v[x - 1][y] != 'F' && fireTime[x - 1][y] == 0) {
			fire.push({ x - 1,y });
			fireTime[x - 1][y] = fireTime[x][y] + 1;
		}
		if (x + 1 < r && v[x + 1][y] != '#' && v[x + 1][y] != 'F' && fireTime[x + 1][y] == 0) {
			fire.push({ x + 1,y });
			fireTime[x + 1][y] = fireTime[x][y] + 1;
		}
		if (y - 1 >= 0 && v[x][y - 1] != '#' && v[x][y - 1] != 'F' && fireTime[x][y - 1] == 0) {
			fire.push({ x ,y - 1 });
			fireTime[x][y - 1] = fireTime[x][y] + 1;
		}
		if (y + 1 < c && v[x][y + 1] != '#' && v[x][y + 1] != 'F' && fireTime[x][y + 1] == 0) {
			fire.push({ x ,y + 1 });
			fireTime[x][y + 1] = fireTime[x][y] + 1;
		}

		fire.pop();
	}

	int ans = 1000001;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		if (x - 1 >= 0 && v[x - 1][y] == '.' && time[x - 1][y] == 0) {
			if (time[x][y] + 1 < fireTime[x - 1][y] || fireTime[x - 1][y] == 0) {
				q.push({ x - 1,y });
				time[x - 1][y] = time[x][y] + 1;

				if (x - 1 == 0 && ans > time[x - 1][y])
					ans = time[x - 1][y];
			}
		}
		if (x + 1 < r && v[x + 1][y] == '.' && time[x + 1][y] == 0) {
			if (time[x][y] + 1 < fireTime[x + 1][y] || fireTime[x + 1][y] == 0) {
				q.push({ x + 1,y });
				time[x + 1][y] = time[x][y] + 1;

				if (x + 1 == r - 1 && ans > time[x + 1][y])
					ans = time[x + 1][y];
			}
		}
		if (y - 1 >= 0 && v[x][y - 1] == '.' && time[x][y - 1] == 0) {
			if (time[x][y] + 1 < fireTime[x][y - 1] || fireTime[x][y - 1] == 0) {
				q.push({ x ,y - 1 });
				time[x][y - 1] = time[x][y] + 1;

				if (y - 1 == 0 && ans > time[x][y - 1])
					ans = time[x][y - 1];
			}
		}
		if (y + 1 < c && v[x][y + 1] == '.' && time[x][y + 1] == 0) {
			if (time[x][y] + 1 < fireTime[x][y + 1] || fireTime[x][y + 1] == 0) {
				q.push({ x ,y + 1 });
				time[x][y + 1] = time[x][y] + 1;

				if (y + 1 == c - 1 && ans > time[x][y + 1])
					ans = time[x][y + 1];
			}
		}

		q.pop();
	}

	if (ans == 1000001)
		cout << "IMPOSSIBLE";
	else
		cout << ans + 1;

}