#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int students[100001];
int vis[100001];
int done[100001];
int cpy[100001];
int cnt;

void dfs(int n){ // dfs 한 이후에는 i 0으로 초기화, check 0으로 초기화
    vis[n] = 1;
    
    int next = students[n];
    if(vis[next] != 1)
        dfs(next);
    else if(done[next] != 1){
        for(int i=next;i!=n;i=students[i]){
            cnt++;
        }
        cnt++; // 자기 자신
    }
    done[n] = 1;
}


int main() {
    FAST;
    int N; cin>>N;
    while(N--){
        fill(vis, vis+100001, 0);
        fill(done, done+100001, 0);
        int n; cin>>n;
        for(int i=1;i<=n;i++) cin>>students[i];
        cnt = 0;
        for(int i=1;i<=n;i++){
            if(vis[i] != 1){
                dfs(i);
            }
        }
        cout<<n-cnt<<'\n';
    }
    
}

