#include <iostream>
#include <vector>

using namespace std;

// arr[x][y] = 1: x와 y 사이에 간선이 존재(x, y는 인접)
// arr[x][y] = 2: x와 y 사이에 간선이 존재(x, y는 인접 X)
int arr[10][10];
int between[10][10]; // conn[x][y] = z: 간선 (x, y) 사이에 있는 수는 z
int nodeVisited[10];
int edgeVisited[10][10];
vector<int> ans;
bool findAnswer = false; // 답을 찾았는지
int e; // 간선의 수
int adjacentEdgeCnt = 0; // 인접 간선의 수

void init() {
	adjacentEdgeCnt = 0;
	findAnswer = false;
	ans.clear();
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			arr[i][j] = 0;
			edgeVisited[i][j] = 0;
		}
		nodeVisited[i] = 0;
	}
}

// n: 연결한 간선의 수, prev: 이전에 방문한 정점
void dfs(int n, int prev) {
	// 답을 찾은 경우
	if (findAnswer)
		return;

	// 모든 간선을 방문한 경우
	if (n == adjacentEdgeCnt) {
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
		findAnswer = true;
		return;
	}

	for (int i = 1; i <= 9; i++) {
		// (prev, i) 간선이 존재하고, 인접한 경우
		if (arr[prev][i] == 1) {
			// i를 방문하지 않은 경우 연결 가능
			if (!nodeVisited[i]) {
				nodeVisited[i] = 1;
				edgeVisited[prev][i] = 1;
				edgeVisited[i][prev] = 1;
				ans.push_back(i);

				dfs(n + 1, i);

				nodeVisited[i] = 0;
				edgeVisited[prev][i] = 0;
				edgeVisited[i][prev] = 0;
				ans.pop_back();
			}
		}
		// (prev, i) 간선이 존재하고, 인접하지 않는 경우
		else if (arr[prev][i] == 2) {
			// i를 방문하지 않았고 중간 정점을 방문한 경우 연결 가능
			int mid = between[prev][i];
			if (!nodeVisited[i] && nodeVisited[mid]) {
				nodeVisited[i] = 1;
				edgeVisited[prev][i] = 1;
				edgeVisited[i][prev] = 1;
				ans.push_back(i);

				// (prev, mid) 간선을 방문한 경우 1개 간선을 방문한 것으로 간주
				if (edgeVisited[prev][mid]) {
					edgeVisited[mid][i] = 1;
					edgeVisited[i][mid] = 1;

					dfs(n + 1, i);

					edgeVisited[mid][i] = 0;
					edgeVisited[i][mid] = 0;
				}
				// 그렇지 않은 경우 2개 간선을 방문한 것으로 간주
				else {
					edgeVisited[mid][i] = 1;
					edgeVisited[i][mid] = 1;
					edgeVisited[prev][mid] = 1;
					edgeVisited[mid][prev] = 1;

					dfs(n + 2, i);

					edgeVisited[mid][i] = 0;
					edgeVisited[i][mid] = 0;
					edgeVisited[prev][mid] = 0;
					edgeVisited[mid][prev] = 0;
				}

				nodeVisited[i] = 0;
				edgeVisited[prev][i] = 0;
				edgeVisited[i][prev] = 0;
				ans.pop_back();
			}
		}
	}
}

int main() {
	int T;
	cin >> T;

	between[1][3] = 2;
	between[1][7] = 4;
	between[1][9] = 5;
	between[2][8] = 5;
	between[3][7] = 5;
	between[3][9] = 6;
	between[4][6] = 5;
	between[7][9] = 8;

	between[3][1] = 2;
	between[7][1] = 4;
	between[9][1] = 5;
	between[8][2] = 5;
	between[7][3] = 5;
	between[9][3] = 6;
	between[6][4] = 5;
	between[9][7] = 8;

	while (T--) {
		init();

		cin >> e;

		for (int i = 0; i < e; i++) {
			int a, b;
			cin >> a >> b;
			arr[a][b] = 1;
			arr[b][a] = 1;
		}

		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				for (int k = 1; k <= 9; k++) {
					// (x, y), (y, z) 간선이 존재할 때 (x, z) 간선 추가
					if (arr[i][j] && arr[j][k] && between[i][k] == j) {
						arr[i][k] = 2;
						arr[k][i] = 2;
					}

					// 이전에 입력받은 간선 (x, y)에 중간 노드가 있는 경우
					else if (arr[i][j] == 1 && between[i][j]) {
						int mid = between[i][j];
						arr[i][j] = 2;
						arr[j][i] = 2;
						arr[i][mid] = 1;
						arr[mid][i] = 1;
						arr[mid][j] = 1;
						arr[j][mid] = 1;
					}
				}
			}
		}

		for (int i = 1; i <= 9; i++) {
			for (int j = i + 1; j <= 9; j++) {
				if (arr[i][j] == 1)
					adjacentEdgeCnt++;
			}
		}

		for (int i = 1; i <= 9; i++) {
			nodeVisited[i] = 1;
			ans.push_back(i);
			dfs(0, i);
			nodeVisited[i] = 0;
			ans.pop_back();
		}

		// 답을 찾지 못한 경우
		if (!findAnswer)
			cout << "IMPOSSIBLE\n";
	}
}