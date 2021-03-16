#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int zero_dp[41];
int one_dp[41];

int main()
{
    FAST;
    int n;
    cin>>n;
    zero_dp[0] = 1;
    zero_dp[1] = 0;
    one_dp[0] = 0;
    one_dp[1] = 1;
    while(n--){
        int a;
        cin>>a;
        if(a<=1) cout<<zero_dp[a]<<' '<<one_dp[a]<<'\n';
        else{
            for(int i=2;i<=a;i++){
                zero_dp[i] = zero_dp[i-1] + zero_dp[i-2];
                one_dp[i] = one_dp[i-1] + one_dp[i-2];
            }
            cout<<zero_dp[a]<<' '<<one_dp[a]<<'\n';
        }
    }
}
