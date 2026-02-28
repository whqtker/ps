#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

vector<pair<int, int>> nodes[100000]; // nodes[i] = {c, j}: i번 째와 j번 째 행성 간 비용은 c
int visited[100000];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	vector<pair<int, int>> x, y, z; // 각 행성들의 좌표, {좌표, 행성 번호}
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		x.push_back({ a,i });
		y.push_back({ b,i });
		z.push_back({ c,i });
	}

	// 각 좌표들에 대하여 정렬
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	sort(z.begin(), z.end());

	// n - 1번 째 이후 좌표들은 사용하지 않는다. 어차피 MST를 구성하는 데 사용되지 않기 때문
	for (int i = 0; i < n - 1; i++) {
		int cur_x = x[i].second;
		int nxt_x = x[i + 1].second;
		int cost_x = abs(x[i].first - x[i + 1].first);
		int cur_y = y[i].second;
		int nxt_y = y[i + 1].second;
		int cost_y = abs(y[i].first - y[i + 1].first);
		int cur_z = z[i].second;
		int nxt_z = z[i + 1].second;
		int cost_z = abs(z[i].first - z[i + 1].first);

		nodes[cur_x].push_back({ cost_x,nxt_x });
		nodes[nxt_x].push_back({ cost_x,cur_x });
		nodes[cur_y].push_back({ cost_y,nxt_y });
		nodes[nxt_y].push_back({ cost_y,cur_y });
		nodes[cur_z].push_back({ cost_z,nxt_z });
		nodes[nxt_z].push_back({ cost_z,cur_z });
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	visited[0] = 1;
	for (int i = 0; i < nodes[0].size(); i++) {
		pq.push({ nodes[0][i] });
	}

	int edge = 0, total = 0; // 생성된 간선의 수, 총 비용
	while (edge < n - 1) {
		int cost = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (!visited[node]) {
			visited[node] = 1;
			edge++;
			total += cost;

			for (int i = 0; i < nodes[node].size(); i++) {
				// node와 연결된 노드가 방문하지 않았다면
				if (!visited[nodes[node][i].second]) {
					pq.push({ nodes[node][i] });
				}
			}
		}
	}

	cout << total;
}