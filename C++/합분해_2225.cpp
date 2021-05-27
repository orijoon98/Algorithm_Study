#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long

int N, K;
ll dp[201][201]; // 합, 개수

int main(){
    FAST;
    cin>>N>>K;
    for(int i=0;i<=N;i++){
        dp[i][1] = 1;
    }
    for(int i=2;i<=K;i++){
        for(int j=0;j<=N;j++){
            for(int k=0;k<=j;k++){
                dp[j][i] += dp[k][i-1];
                if(dp[j][i] >= 1000000000) dp[j][i] %= 1000000000;
            }
        }
    }
    cout<<dp[N][K];
}
