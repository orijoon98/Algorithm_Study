#include <bits/stdc++.h>
#define endl '\n'
#define MAX 10001

using namespace std;

int n, ans = 0;
vector<vector<pair<int,int>>> node;
bool vis[MAX];

void Initialize() {
    for (int i = 0; i <= 10000; i++) {
        vector<pair<int,int>> v;
        v.push_back({i, 0});
        node.push_back(v);
    }
}

void Input() {
    cin>>n;
    for (int i = 0; i < n - 1; i++) {
        int parent, child, weight;
        cin>>parent>>child>>weight;
        node[parent].push_back({child,weight});
        node[child].push_back({parent,weight});
    }
}

void DFS(int cur, int result) {
    vis[cur] = true;
    ans = max(ans, result);
    for (int i = 0; i < node[cur].size(); i++) {
        int next = node[cur][i].first;
        int weight = node[cur][i].second;
        if (cur == next) continue;
        if (vis[next]) continue;
        DFS(next, result + weight);
    }
}

void Solution() {
    for (int i = 1; i <= 10000; i++) {
        memset(vis, false, sizeof(vis));
        DFS(i, 0);
    }
    cout<<ans<<endl;
}

void Solve() {
    Initialize();
    Input();
    Solution();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solve();

    return 0;
}