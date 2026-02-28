#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> nodes[32001];
int inDegree[32001];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		nodes[a].push_back(b);
		inDegree[b]++;
	}

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= n; i++) {
		if (!inDegree[i])
			pq.push(i);
	}

	for (int i = 0; i < n; i++) {
		int x = pq.top();
		pq.pop();
		cout << x << " ";

		for (int j = 0; j < nodes[x].size(); j++) {
			int y = nodes[x][j];
			inDegree[y]--;
			if (!inDegree[y])
				pq.push(y);
		}
	}
}