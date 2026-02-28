#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

char arr[51][51];
int visited[51][51];
vector<pair<int, int>> dist[252]; // i -> j 까지의 최단 거리 (i, j: nodes 벡터의 인덱스)
int n, m;
int mst[252];

bool outOfBound(int x, int y) {
	return x < 0 || y < 0 || x >= n || y >= n;
}

int main() {
	// 1. BFS를 통해 S 또는 K 간 최단 거리를 구한다. -> 최단 거리를 구할 수 없는 지점이 존재하는 경우 -1
	// 2. S, K 간 MST의 최단 거리의 합을 구한다.

	cin >> n >> m;

	vector<pair<int, int>> nodes;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 'S' || arr[i][j] == 'K') {
				nodes.push_back({ i,j });
			}
		}
	}

	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,1,0,-1 };

	queue<pair<int, int>> q;

	for (int i = 0; i < nodes.size(); i++) {
		// 각 노드에 대하여 BFS 수행
		memset(visited, -1, sizeof(visited));
		int x = nodes[i].first;
		int y = nodes[i].second;
		q.push({ x,y });
		visited[x][y] = 0;

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];

				if (!outOfBound(nx, ny) && arr[nx][ny] != '1' && visited[nx][ny] == -1) {
					visited[nx][ny] = visited[x][y] + 1;
					q.push({ nx,ny });
				}
			}
		}

		// 노드 간 최단 거리 초기화
		for (int j = 0; j < nodes.size(); j++) {
			if (i != j) {
				int x = nodes[j].first;
				int y = nodes[j].second;

				if (visited[x][y] != -1)
					dist[i].push_back({ j,visited[x][y] });
			}
		}
	}

	int total_dist = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	mst[0] = 1;
	int node_cnt = 1; // 현재 mst에 존재하는 노드의 수
	for (int i = 0; i < dist[0].size(); i++) {
		pq.push({ dist[0][i].second,dist[0][i].first });
	}

	while (!pq.empty()) {
		int d = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (mst[node]) continue;

		total_dist += d;
		node_cnt++;
		mst[node] = 1;

		for (int i = 0; i < dist[node].size(); i++) {
			int nnode = dist[node][i].first;
			int nd = dist[node][i].second;

			if (!mst[nnode]) {
				pq.push({ nd,nnode });
			}
		}
	}

	// 복제할 수 있는 위치는 m + 1개
	if (m + 1 != node_cnt)
		cout << -1;
	else
		cout << total_dist;
}