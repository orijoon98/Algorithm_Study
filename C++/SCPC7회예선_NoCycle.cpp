#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int T, N, M, K, destination;
vector<int> node[501];
vector<pair<int,int>> v;
vector<int> ans, ansV;
bool vis[501], finished[501];
bool flag, hasCycle;

void DFS(int cur)
{
    vis[cur] = true;
    for (int i = 0; i < node[cur].size(); ++i) {
        int next = node[cur][i];
        if (!vis[next])
            DFS(next);
        else if (finished[next] == false) { //  next가 이미 방문했지만, 종료되지 않는 정점이면
            hasCycle = true;
            return; // 사이클이 존재한다면 바로 종료
        }
    }
    finished[cur] = true;
}

void Track(int n){
    if(flag) return;
    if(n == v.size()){
        for(auto cur: ans){
            ansV.push_back(cur);
        }
        flag = true;
        return;
    }
    node[v[n].first].push_back(v[n].second);
    ans.push_back(0);
    hasCycle = false;
    fill(vis, vis+501, false);
    fill(finished, finished+501, false);
    DFS(v[n].first);
    if(!hasCycle) Track(n+1); // 사이클이없다면
    node[v[n].first].pop_back();
    ans.pop_back();
    node[v[n].second].push_back(v[n].first);
    ans.push_back(1);
    hasCycle = false;
    fill(vis, vis+501, false);
    fill(finished, finished+501, false);
    DFS(v[n].second);
    if(!hasCycle) Track(n+1); // 사이클이없다면
    node[v[n].second].pop_back();
    ans.pop_back();
}

void Solution(){
    cin>>T;
    for(int c=1;c<=T;c++){
        cin>>N>>M>>K;
        for(int i=1;i<=N;i++){
            node[i].clear();
        }
        v.clear();
        for(int i=1;i<=M;i++){
            int a, b;
            cin>>a>>b;
            node[a].push_back(b);
        }
        for(int i=1;i<=K;i++){
            int a, b;
            cin>>a>>b;
            v.push_back({a,b});
        }
        flag = false;
        ans.clear();
        ansV.clear();
        Track(0);
        cout<<"Case #"<<c<<endl;
        for(auto cur: ansV){
            cout<<cur;
        }
        cout<<endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solution();
}
