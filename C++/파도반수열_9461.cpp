#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

long long dp[101] = {0, 1, 1, 1, 2, 2};

int main()
{
    FAST;
    int n;
    cin>>n;
    while(n--){
        int a;
        cin>>a;
        if(a<=5) cout<<dp[a]<<'\n';
        else{
            for(int i=6;i<=a;i++){
                dp[i] = dp[i-1] + dp[i-5];
            }
            cout<<dp[a]<<'\n';
        }
    }
}
