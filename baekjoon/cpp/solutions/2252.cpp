#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int inDegree[32001];
vector<int> nodes[32001];

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		nodes[x].push_back(y);
		inDegree[y]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (!inDegree[i])
			q.push(i);
	}

	for (int i = 1; i <= n; i++) {
		int x = q.front();
		q.pop();
		cout << x << " ";

		for (int j = 0; j < nodes[x].size(); j++) {
			int y = nodes[x][j];
			inDegree[y]--;
			if (!inDegree[y])
				q.push(y);
		}
	}
}