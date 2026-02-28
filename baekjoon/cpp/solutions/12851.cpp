#include <iostream>
#include <queue>

using namespace std;

int arr[100001];
int visited[100001];

int main() {
	int n, m;
	cin >> n >> m;
	arr[n] = 1; // 수빈이 위치
	arr[m] = 2; // 동생 위치

	queue<pair<int, int>> q;
	q.push({ n,0 });

	int min = 100001; // 동생 위치까지 찾는 가장 빠른 시간
	int ans = 0; // 가장 빠른 시간으로 찾는 횟수
	while (!q.empty()) {
		int x = q.front().first; // 현위치
		int cnt = q.front().second; // 걸린 시간
		q.pop();

		visited[x] = 1;

		if (arr[x] == 2) {
			if (min >= cnt) {
				min = cnt;
				ans++;
			}
		}

		if (x - 1 >= 0 && !visited[x - 1]) {
			q.push({ x - 1,cnt + 1 });
		}
		if (x + 1 <= 100000 && !visited[x + 1]) {
			q.push({ x + 1,cnt + 1 });
		}
		if (2 * x <= 100000 && !visited[2 * x]) {
			q.push({ 2 * x,cnt + 1 });
		}
	}

	cout << min << "\n" << ans;
}