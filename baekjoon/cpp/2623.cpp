#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> nodes[1001];
int inDegree[1001];

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;

		int s, e;
		cin >> s;
		for (int j = 0; j < k - 1; j++) {
			cin >> e;
			nodes[s].push_back(e);
			inDegree[e]++;
			s = e;
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (!inDegree[i])
			q.push(i);
	}

	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		if (q.empty()) {
			cout << 0;
			return 0;
		}

		int x = q.front();
		q.pop();
		ans.push_back(x);

		for (int j = 0; j < nodes[x].size(); j++) {
			int y = nodes[x][j];
			inDegree[y]--;
			if (!inDegree[y])
				q.push(y);
		}
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << "\n";
	}
}