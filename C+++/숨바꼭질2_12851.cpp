#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int vis[100001];
int n, k, t, cnt;

void BFS(){
    queue<pair<int, int>> q;
    q.push({n,0});
    vis[n] = 1;
    while(!q.empty()) {
        int now = q.front().first;
        int time = q.front().second;
        q.pop();
        vis[now] = 1;
        if(cnt && now == k && t == time) cnt++;
        if(!cnt && now == k) {
            t = time;
            cnt++;
        }
        if(now * 2 <= 100000 && !vis[now * 2]) q.push({now*2,time+1});
        if(now + 1 <= 100000 && !vis[now + 1]) q.push({now+1,time+1});
        if(now - 1 >= 0 && !vis[now - 1]) q.push({now-1,time+1});
    }
}

int main() {
    FAST;
    cin>>n>>k;
    BFS();
    cout<<t<<"\n"<<cnt;
}
