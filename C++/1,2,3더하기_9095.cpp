#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int dp[11] = {0, 1, 2, 4, 0, };

int count(int n){
    if(n == 1) return 1;
    else if(n == 2) return 2;
    else if(n == 3) return 4;
    else{
        int a, b, c;
        if(dp[n-1] != 0) a = dp[n-1];
        else{
            a = count(n-1);
            dp[n-1] = a;
        }
        if(dp[n-2] != 0) b = dp[n-2];
        else{
            b = count(n-2);
            dp[n-2] = b;
        }
        if(dp[n-3] != 0) c = dp[n-3];
        else{
            c = count(n-3);
            dp[n-3] = c;
        }
        return a + b + c;
    }
}

int main(){
    FAST;
    int T, n;
    cin>>T;
    while(T--){
        cin>>n;
        cout<<count(n)<<'\n';
    }
}
