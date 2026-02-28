#include <iostream>
#include <vector>

using namespace std;

int n, m;

bool able(int x, int y, vector<vector<int>>& v) {
	if (x - 1 >= 0 && v[x - 1][y] == 0)
		return true;
	if (x + 1 < n && v[x + 1][y] == 0)
		return true;
	if (y - 1 >= 0 && v[x][y - 1] == 0)
		return true;
	if (y + 1 < m && v[x][y + 1] == 0)
		return true;

	return false;
}

int main() {
	cin >> n >> m;

	int r, c, d;
	cin >> r >> c >> d;
	vector<vector<int>> v(n, vector<int>(m));

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			int x;
			cin >> x;
			v[i][j] = x;
		}
	}

	int cnt = 0;
	while (1) {
		if (v[r][c] == 0) {
			cnt++;
			v[r][c] = -1;
		}

		if (able(r, c, v)) {
			d = (d + 3) % 4;

			if (d == 0 && r - 1 >= 0 && v[r - 1][c] == 0)
				r--;
			else if (d == 1 && c + 1 < m && v[r][c + 1] == 0)
				c++;
			else if (d == 2 && r + 1 < n && v[r + 1][c] == 0)
				r++;
			else if (d == 3 && c - 1 >= 0 && v[r][c - 1] == 0)
				c--;
		}
		else if (!able(r, c, v)) {
			if (d == 0) {
				if (r + 1 < n && v[r + 1][c] != 1)
					r++;
				else
					break;
			}
			else if (d == 1) {
				if (c - 1 >= 0 && v[r][c - 1] != 1)
					c--;
				else
					break;
			}
			else if (d == 2) {
				if (r - 1 >= 0 && v[r - 1][c] != 1)
					r--;
				else
					break;
			}
			else if (d == 3) {
				if (c + 1 < m && v[r][c + 1] != 1)
					c++;
				else
					break;
			}
		}
	}

	cout << cnt;
}