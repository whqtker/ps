#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;

		vector<int> last; // 작년 순위
		vector<int> inDegree(501);
		vector<int> lastRank(501); // lastRank[i] = x: i 팀의 작년 순위는 x
		vector<vector<int>> edge(501, vector<int>(501)); // edge[i][j] = 1: i -> j로의 간선이 존재함

		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			last.push_back(x);
			lastRank[x] = i;
		}

		// 존재하는 모든 팀에 대해 가능한 간선을 설정한다. 즉, n(n+1)/2개의 간선을 생성한다.
		// a -> b: a가 순위 더 높음
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int a = last[i];
				int b = last[j];

				inDegree[b]++;
				edge[a][b] = 1;
			}
		}

		int m;
		cin >> m;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;

			// 둘의 관계를 뒤집는다.
			if (lastRank[a] < lastRank[b]) {
				inDegree[b]--;
				inDegree[a]++;
				edge[a][b] = 0;
				edge[b][a] = 1;
			}
			else {
				inDegree[a]--;
				inDegree[b]++;
				edge[a][b] = 1;
				edge[b][a] = 0;
			}
		}

		queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (!inDegree[i]) {
				q.push(i);
			}
		}

		vector<int> ans;
		bool impossible = true;
		bool notUniqueAnswer = false;
		while (!q.empty()) {
			// inDegree가 0인 노드가 두 개 이상이면 순서를 하나로 정할 수 없음
			if (q.size() >= 2) {
				notUniqueAnswer = true;
				break;
			}

			int x = q.front();
			q.pop();
			ans.push_back(x);


			for (int i = 1; i <= n; i++) {
				if (edge[x][i]) {
					int y = i;
					inDegree[y]--;

					if (!inDegree[y]) {
						impossible = false;
						q.push(y);
					}
				}
			}
		}

		// 모든 노드를 방문하지 못한 경우 순서를 정할 수 없음
		if (ans.size() != n) {
			impossible = true;
		}

		if (impossible)
			cout << "IMPOSSIBLE";
		else if (notUniqueAnswer)
			cout << "?";
		else {
			for (int i = 0; i < n; i++) {
				cout << ans[i] << " ";
			}
		}
		cout << "\n";
	}
}