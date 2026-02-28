#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int cnt = 0; // 활성화해야 하는 좌표의 수 == 빈 칸의 수
int board[51][51];
vector<pair<int, int>> inactivated; // 모든 비활성 바이러스 좌표
vector<pair<int, int>> activated; // 활성 바이러스 좌표
int dfs_visited[51][51];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int visited[51][51];
int ans = 1e9;

void clear() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = 0;
        }
    }
}

int bfs() {
    clear();
    int target = 0;
    int max_time = 0;
    queue<pair<int, int>> q;

    // 활성 바이러스들을 큐에 삽입
    for (auto e : activated) {
        q.push(e);
        visited[e.first][e.second] = 1;
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (visited[nx][ny]) continue;
            if (board[nx][ny] == 1) continue;
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

            visited[nx][ny] = visited[x][y] + 1;

            if (board[nx][ny] == 0) {
                target++;
                max_time = visited[nx][ny] - 1;
            }

            q.push({ nx,ny });
        }
    }

    // 모든 빈 칸을 바이러스로 채웠다면
    if (cnt == target) return max_time;

    // 불가능한 경우
    return 1e9;
}

// 활성 바이러스 수, inactivated 현재 인덱스
void dfs(int x, int idx) {
    // m개 활성 바이러스 설정했다면
    if (x == m) {
        // 바이러스를 퍼뜨린다.
        int ret = bfs();
        ans = min(ans, ret);
        return;
    }

    for (int i = idx; i < inactivated.size(); i++) {
        int cx = inactivated[i].first;
        int cy = inactivated[i].second;

        if (!dfs_visited[cx][cy]) {
            dfs_visited[cx][cy] = 1;
            activated.push_back({ cx,cy });

            dfs(x + 1, i + 1);

            activated.pop_back();
            dfs_visited[cx][cy] = 0;
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];

            if (board[i][j] == 2) {
                inactivated.push_back({ i,j });
            }
            else if (board[i][j] == 0) cnt++;
        }
    }

    // DFS로 빈 칸 중 M개 활성 바이러스로 설정
    dfs(0, 0);

    if (ans == 1e9) cout << -1;
    else cout << ans;
}