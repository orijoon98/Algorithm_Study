#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int board[1001][1001];
int vis[1001];
int visit2[1001];
int n,m,v;
void DFS(int v) {
    vis[v] = 1;
    cout << v << " ";
    
    for (int i = 1; i <= n; i++) {
        if (board[v][i] == 1 && vis[i] == 0) { //현재 정점과 연결되어있고 방문되지 않았으면
            DFS(i);
        }
    }
}

int main(){
    FAST;
    cin>>n>>m>>v;
    while(m--){
        int a, b;
        cin>>a>>b;
        board[a][b] = 1;
        board[b][a] = 1;
    }
    DFS(v);
    cout<<'\n';
    queue<int> Q;
    visit2[v] = 1;
    Q.push(v);
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        cout<<cur<<' ';
        for(int i=1;i<=n;i++){
            if(board[cur][i] != 1) continue;
            if(visit2[i] == 1) continue;
            visit2[i] = 1;
            Q.push(i);
        }
    }
    
}

