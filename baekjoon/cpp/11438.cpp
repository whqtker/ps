#include <iostream>
#include <vector>

#define LOG 17

using namespace std;

int up[LOG][100001];
int depth[100001];
vector<int> graph[100001];

void dfs(int cur,int par,int d) {
    up[0][cur]=par;
    depth[cur]=d;
    for (auto nxt:graph[cur]) {
        if (nxt==par) continue;
        dfs(nxt,cur,d+1);
    }
}

void preprocessing(int n) {
    for (int i=1;i<LOG;i++) {
        for (int j=1;j<=n;j++) {
            up[i][j]=up[i-1][up[i-1][j]];
        }
    }
}

int lca(int a,int b) {
    if (depth[a]<depth[b]) swap(a,b);

    int diff=depth[a]-depth[b];
    for (int i=0;i<LOG;i++) {
        if (diff>>i&1) {
            a=up[i][a];
        }
    }

    if (a==b) return a;

    for (int i=LOG-1;i>=0;i--) {
        if (up[i][a]!=up[i][b]) {
            a=up[i][a];
            b=up[i][b];
        }
    }

    return up[0][a];
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

    preprocessing(n);

    int m;
    cin>>m;
    for (int i=0;i<m;i++) {
        int a,b;
        cin>>a>>b;

        cout<<lca(a,b)<<"\n";
    }
}