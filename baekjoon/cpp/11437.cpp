#include <iostream>
#include <vector>

using namespace std;

int parent[50001];
int depth[50001];
vector<int> graph[50001];

void dfs(int cur,int par,int d) {
    parent[cur]=par;
    depth[cur]=d;
    for (auto nxt:graph[cur]) {
        if (nxt==par) continue;
        dfs(nxt,cur,d+1);
    }
}

int lca(int a,int b) {
    while (depth[a]>depth[b]) a=parent[a];
    while (depth[b]>depth[a]) b=parent[b];

    while (a!=b) {
        a=parent[a];
        b=parent[b];
    }

    return a;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin>>n;
    for (int i=0;i<n-1;i++) {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1,-1,0);

    int m;
    cin>>m;
    for (int i=0;i<m;i++) {
        int a,b;
        cin>>a>>b;

        cout<<lca(a,b)<<"\n";
    }
}