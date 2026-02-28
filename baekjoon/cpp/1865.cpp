#include <iostream>
#include <vector>
#include <tuple>

#define INF 25000001

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m, w; // 지점, 도로, 웜홀
		cin >> n >> m >> w;

		vector<tuple<int, int, int>> v;
		for (int i = 0;i < m;i++) {
			int s, e, t;
			cin >> s >> e >> t; // 시점, 종점, 가중치
			v.push_back({ s,e,t });
			v.push_back({ e,s,t });
		}
		for (int i = 0;i < w;i++) {
			int s, e, t;
			cin >> s >> e >> t; // 시점, 종점, 가중치
			v.push_back({ s,e,-t });
		}

		vector<int> dist(n + 1); // 최소 비용
		for (int i = 1;i <= n;i++) {
			dist[i] = INF;
		}
		dist[1] = 0;

		for (int i = 0;i < n - 1;i++) {
			for (int j = 0;j < v.size();j++) {
				int start = get<0>(v[j]);
				int end = get<1>(v[j]);
				int cost = get<2>(v[j]);

				if (dist[start] + cost < dist[end])
					dist[end] = dist[start] + cost;
			}
		}

		bool flag = false;
		for (int j = 0;j < v.size();j++) {
			int start = get<0>(v[j]);
			int end = get<1>(v[j]);
			int cost = get<2>(v[j]);

			if (dist[start] + cost < dist[end]) {
				cout << "YES\n";
				flag = true;
				break;
			}
		}

		if (!flag)
			cout << "NO\n";
	}
}