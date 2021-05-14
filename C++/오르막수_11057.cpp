#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int dp[1001][10]; // 자릿수, 마지막 자리의 숫자

int main() {
    FAST;
    int len;
    cin>>len;
    for(int i=0;i<=9;i++) dp[1][i] = 1; // 한 자릿수 일때는 전부 1가지 경우
    for(int i=2;i<=len;i++){
        for(int j=0;j<=9;j++){
            for(int k=j;k>=0;k--){
                dp[i][j] += dp[i-1][k];
                if(dp[i][j] >= 10007) dp[i][j] %= 10007;
            }
        }
    }
    int ans = 0;
    for(int i=0;i<=9;i++){
        ans += dp[len][i];
    }
    if(ans >= 10007) ans %= 10007;
    cout<<ans<<'\n';
}
