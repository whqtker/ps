#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> arr[100001];
vector<int> rev_arr[100001];
vector<int> bomb;
int find_visited[100001];
int escape_visited[100001];
int n, m;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		arr[x].push_back(y);
		rev_arr[y].push_back(x);
	}

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int b;
		cin >> b;
		bomb.push_back(b);
	}

	queue<int> find;
	find.push(1);
	find_visited[1] = 1;
	while (!find.empty()) {
		int x = find.front();
		find.pop();

		for (int j = 0; j < arr[x].size(); j++) {
			int y = arr[x][j];
			if (!find_visited[y]) {
				find_visited[y] = 1;
				find.push(y);
			}
		}
	}

	queue<int> escape;
	escape.push(n);
	escape_visited[n] = 1;
	while (!escape.empty()) {
		int x = escape.front();
		escape.pop();

		for (int j = 0; j < rev_arr[x].size(); j++) {
			int y = rev_arr[x][j];
			if (!escape_visited[y]) {
				escape_visited[y] = 1;
				escape.push(y);
			}
		}
	}


	for (int i = 0; i < t; i++) {
		if (find_visited[bomb[i]] && escape_visited[bomb[i]])
			cout << "Defend the CTP\n";
		else
			cout << "Destroyed the CTP\n";
	}
}