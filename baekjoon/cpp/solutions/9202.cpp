#include <iostream>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

int n, m;
string dict[300000];
string board[4];
int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };
unordered_map<int, int> score;
string cur; // 현 DFS 탐색의 문자열
set<string> cases; // 가능한 단어들
int visited[4][4];

void findRoute(int x, int y) {
	if (cur.length() > 8) return;

	cases.insert(cur);

	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4) continue;
		if (visited[nx][ny]) continue;

		cur.push_back(board[nx][ny]);
		visited[nx][ny] = 1;

		findRoute(nx, ny);

		cur.pop_back();
		visited[nx][ny] = 0;
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	score[1] = score[2] = 0;
	score[3] = score[4] = 1;
	score[5] = 2;
	score[6] = 3;
	score[7] = 5;
	score[8] = 11;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> dict[i];
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> board[j];
		}

		cases.clear();

		// 각 단어를 시작으로 최대 8글자의 단어를 생성한다.
		for (int x = 0; x < 4; x++) {
			for (int y = 0; y < 4; y++) {
				cur.push_back(board[x][y]);
				visited[x][y] = 1;

				findRoute(x, y);

				cur.pop_back();
				visited[x][y] = 0;
			}
		}

		// 정답 구하기
		int maxScore = 0;
		string longest = "";
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (cases.find(dict[i]) != cases.end()) {
				cnt++;
				maxScore += score[dict[i].length()];
				if (longest.length() == dict[i].length()) {
					longest = longest > dict[i] ? dict[i] : longest;
				}
				else {
					longest = longest.length() < dict[i].length() ? dict[i] : longest;
				}
			}
		}

		cout << maxScore << " " << longest << " " << cnt << "\n";
	}
}