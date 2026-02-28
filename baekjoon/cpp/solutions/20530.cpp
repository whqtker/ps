#include <iostream>
#include <vector>

using namespace std;
int n, q;
vector<int> v[200001];
int cycle[200001];
int visited[200001];
int parent[200001];
bool findCycle;

// 사이클 발견 및 해당 노드 찾기
void dfs(int s, int p) {
    visited[s] = 1;
    parent[s] = p;
    for (int next : v[s]) {
        if (!visited[next]) {
            dfs(next, s);
        }
        // 사이클 발생
        else if (next != p && !findCycle) {
            findCycle = true;
            int cur = s;
            cycle[next] = 1;
            while (cur != next) {
                cycle[cur] = 1;
                cur = parent[cur];
            }
            return;
        }

        if (findCycle) return;
    }
}

int Find(int n) {
    if (n == parent[n]) return n;
    return parent[n] = Find(parent[n]);
}

// 사이클에 속한 노드가 루트 노드가 되도록 합쳐야 한다.
void Union(int x, int y) {
    int px = Find(x);
    int py = Find(y);

    if (cycle[px] && cycle[py])
        return;
    else if (cycle[px])
        parent[py] = px;
    else if (cycle[py])
        parent[px] = py;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    // 초기화
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    // 사이클에 속한 노드들을 루트 노드로 하여 각각의 트리로 분할한다.
    // 두 노드가 다른 트리에 있다면 2, 같은 트리에 있다면 1
    dfs(1, -1);

    for (int i = 1; i <= n; i++) {
        if (cycle[i])
            parent[i] = i;
    }


    for (int i = 1; i <= n; i++) {
        for (int next : v[i]) {
            if (Find(i) != Find(next)) {
                Union(i, next);
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        if (Find(x) == Find(y)) {
            cout << "1\n";
        }
        else {
            cout << "2\n";
        }
    }
}
