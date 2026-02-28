#include <iostream>
#include <numeric>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int graph[200001]; // graph[i]=j : i의 부모는 j
int parent[200001];

int Find(int x) {
    if (parent[x]==x) return x;
    return parent[x]=Find(parent[x]);
}

void Union(int x,int y) {
    x=Find(x);
    y=Find(y);

    if (x!=y) {
        parent[x]=y;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,q;
    cin>>n>>q;
    for (int i=2;i<=n;i++) cin>>graph[i];

    vector<string> queies;
    cin.ignore();
    for (int i=0;i<n-1+q;i++) {
        string str;
        getline(cin,str);
        queies.push_back(str);
    }

    iota(parent+1,parent+n+1,1);

    // 거꾸로 쿼리를 수행하며, 간선 제거 연산은 Union하며 답을 구한다.
    vector<string> ans;
    for (int i=queies.size()-1;i>=0;i--) {
        string query=queies[i];
        if (query[0]=='0') {
            int node=stoi(query.substr(1));
            Union(node,graph[node]);
        }
        else {
            vector<int> nums;
            string num;
            stringstream ss(query.substr(1));
            while (ss>>num) {
                nums.push_back(stoi(num));
            }

            if (Find(nums[0])==Find(nums[1])) ans.push_back("YES");
            else ans.push_back("NO");
        }
    }

    for (int i=ans.size()-1;i>=0;i--) {
        cout<<ans[i]<<"\n";
    }
}