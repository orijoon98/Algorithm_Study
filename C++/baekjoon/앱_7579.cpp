#include <bits/stdc++.h>
#define endl '\n'
#define MAX 101
#define tMAX 10001
using namespace std;

int N, M, ans = INT_MAX;
int dp[MAX][tMAX];
int m[MAX];
int c[MAX];

void Input(){
    cin>>N>>M;
    for(int i=1;i<=N;i++) cin>>m[i];
    for(int i=1;i<=N;i++) cin>>c[i];
}

void Solution(){
    for(int i=1;i<=N;i++){
        for(int j=0;j<tMAX;j++){
            dp[i][j] = (j>=c[i]) ? max(dp[i-1][j-c[i]] + m[i], dp[i-1][j]) : dp[i-1][j];
            if(dp[i][j] >= M) ans = min(ans, j);
        }
    }
    cout<<ans<<endl;
}

void Solve(){
    Input();
    Solution();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solve();

    return 0;
}
