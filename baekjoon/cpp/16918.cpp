#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

bool outOfBound(int r, int c, int i, int j) {
	if (r <= i || i < 0 || c <= j || j < 0)
		return true;
	else return false;
}

void bfs(int r, int c, int n, vector<string> v) {
	queue<pair<int, int>> q;
	for (int i = 0;i < r;i++) {
		for (int j = 0;j < c;j++) {
			if (v[i][j] == 'O') {
				q.push({ i,j });
			}
		}
	}
	vector<vector<int>> exploded(r, vector<int>(c, 0)); // 1이면 폭탄이 터진 반경에 해당함
	for (int i = 0;i < n / 2;i++) {
		for (int j = 0;j < r;j++)
			for (int k = 0;k < c;k++)
				exploded[j][k] = 0;

		while (!q.empty()) {
			int cur_i = q.front().first;
			int cur_j = q.front().second;
			exploded[cur_i][cur_j] = 1;
			if (!outOfBound(r, c, cur_i - 1, cur_j))
				exploded[cur_i - 1][cur_j] = 1;
			if (!outOfBound(r, c, cur_i + 1, cur_j))
				exploded[cur_i + 1][cur_j] = 1;
			if (!outOfBound(r, c, cur_i, cur_j - 1))
				exploded[cur_i][cur_j - 1] = 1;
			if (!outOfBound(r, c, cur_i, cur_j + 1))
				exploded[cur_i][cur_j + 1] = 1;
			q.pop();
		}
		for (int i = 0;i < r;i++) {
			for (int j = 0;j < c;j++) {
				if (exploded[i][j] == 0)
					q.push({ i,j });
			}
		}
	}

	for (int i = 0;i < r;i++) {
		for (int j = 0;j < c;j++) {
			if (exploded[i][j] == 1)
				cout << ".";
			else cout << "O";
		}
		cout << "\n";
	}
}

int main() {
	int r, c, n;
	cin >> r >> c >> n; // r: 세로, c: 가로, n: n초 후

	vector<string> v;
	for (int i = 0;i < r;i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}
	if (n % 2 == 0) {
		for (int i = 0;i < r;i++) {
			for (int j = 0;j < c;j++)
				cout << "O";
			cout << "\n";
		}

	}
	else if (n == 1) {
		for (int i = 0;i < r;i++) {
			cout << v[i] << "\n";
		}
	}
	else
		bfs(r, c, n, v);
}