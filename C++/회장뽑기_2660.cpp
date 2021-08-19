#include <bits/stdc++.h>
#define endl '\n'
#define MAX 51
#define INF 987654321
using namespace std;

int N, ans = INF;
int dp[MAX][MAX];
vector<int> ansV;

void Setting(){
    for(int i=0;i<MAX;i++) fill(dp[i], dp[i]+MAX, INF);
}

void Input(){
    cin>>N;
    while(true){
        int a, b;
        cin>>a>>b;
        if(a==-1 && b==-1) break;
        dp[a][b] = 1;
        dp[b][a] = 1;
    }
}

void FloydWarshall(){
    for(int i=1;i<=N;i++) dp[i][i] = 0;
    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
}

void Solution(){
    FloydWarshall();
    for(int i=1;i<=N;i++){
        int tmp = 0;
        for(int j=1;j<=N;j++){
            tmp = max(tmp, dp[i][j]);
        }
        ans = min(ans, tmp);
    }
    for(int i=1;i<=N;i++){
        int tmp = 0;
        for(int j=1;j<=N;j++){
            tmp = max(tmp, dp[i][j]);
        }
        if(tmp == ans) ansV.push_back(i);
    }
    cout<<ans<<' '<<ansV.size()<<endl;
    for(auto cur: ansV) cout<<cur<<' ';
}

void Solve(){
    Setting();
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
