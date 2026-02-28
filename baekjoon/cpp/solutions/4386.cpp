#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

vector<pair<double, double>> stars;
vector<pair<int, double>> graph[101];
int mst[101];

double calc(int a, int b) {
	return sqrt(pow(stars[a].first - stars[b].first, 2) + pow(stars[a].second - stars[b].second, 2));
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		double x, y;
		cin >> x >> y;
		stars.push_back({ x,y });
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			graph[i].push_back({ j,calc(i,j) });
		}
	}

	priority_queue <pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
	for (int i = 0; i < graph[0].size(); i++) {
		pq.push({ graph[0][i].second,graph[0][i].first });
	}

	mst[0] = 1;
	int cnt = 0;
	double cumw = 0;
	while (cnt < n - 1) {
		double w = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (mst[node]) continue;

		mst[node] = 1;
		cnt++;
		cumw += w;

		for (int i = 0; i < graph[node].size(); i++) {
			int nnode = graph[node][i].first;
			double nw = graph[node][i].second;

			if (!mst[nnode]) {
				pq.push({ nw,nnode });
			}
		}
	}

	cout << fixed;
	cout << setprecision(2);
	cout << cumw;
}