#include <iostream>
#include <vector>
#include <tuple>

#define INF 1e9

using namespace std;

int grave[31][31];
int hole[31][31];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int dist[31][31]; // dist[x][y]: (x, y)에 도달하기까지 최소 비용

// (x, y)를 하나의 노드로 간주
struct Coor {
	int x;
	int y;

	Coor(int x, int y) :x(x), y(y) {};
};

void clear() {
	for (int i = 0; i < 31; i++) {
		for (int j = 0; j < 31; j++) {
			grave[i][j] = 0;
			hole[i][j] = 0;
			dist[i][j] = INF;
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	while (1) {
		clear();
		int w, h;
		cin >> w >> h;

		if (w == 0 && h == 0) break;

		int g;
		cin >> g;
		for (int i = 0; i < g; i++) {
			int x, y;
			cin >> x >> y;
			grave[x][y] = 1;
		}

		vector<tuple<Coor, Coor, int>> edges;
		int e;
		cin >> e;
		for (int i = 0; i < e; i++) {
			int x1, x2, y1, y2, t;
			cin >> x1 >> y1 >> x2 >> y2 >> t;

			edges.push_back({ Coor(x1,y1),Coor(x2,y2),t });
			hole[x1][y1] = 1;
		}

		// 인접 좌표 비용 1로 계산
		for (int x = 0; x < w; x++) {
			for (int y = 0; y < h; y++) {
				if (grave[x][y] || hole[x][y]) continue;
				if (x == w - 1 && y == h - 1) continue; // 도착 지점엔 간선 추가 X

				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];

					if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
					if (grave[nx][ny]) continue;

					edges.push_back({ Coor(x, y),Coor(nx,ny),1 });
				}
			}
		}

		dist[0][0] = 0;

		for (int i = 0; i < w * h - 1; i++) {
			for (int j = 0; j < edges.size(); j++) {
				Coor start = get<0>(edges[j]);
				Coor end = get<1>(edges[j]);
				int cost = get<2>(edges[j]);

				// 도달하지 못한 출발 지점에 대한 갱신은 하지 않는다.
				if (dist[start.x][start.y] == INF) continue;

				if (dist[start.x][start.y] + cost < dist[end.x][end.y]) {
					dist[end.x][end.y] = dist[start.x][start.y] + cost;
				}
			}
		}

		bool never = false;
		for (int j = 0; j < edges.size(); j++) {
			Coor start = get<0>(edges[j]);
			Coor end = get<1>(edges[j]);
			int cost = get<2>(edges[j]);

			if (dist[start.x][start.y] == INF) continue;

			if (dist[start.x][start.y] + cost < dist[end.x][end.y]) {
				cout << "Never\n";
				never = true;
				break;
			}
		}

		if (!never) {
			if (dist[w - 1][h - 1] == INF) {
				cout << "Impossible\n";
			}
			else {
				cout << dist[w - 1][h - 1] << "\n";
			}
		}
	}
}