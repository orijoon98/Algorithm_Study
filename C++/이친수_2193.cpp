#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

long long dp[100] = {0, 1, 1, 2};

long long fibo(long long n){
    if(n == 1) return dp[1];
    else if(n == 2) return dp[2];
    else{
        if(dp[n] != 0) return dp[n];
        else{
            dp[n] = fibo(n-1) + fibo(n-2);
            return dp[n];
        }
    }
}

int main()
{
    FAST;
    long long n;
    cin>>n;
    cout<<fibo(n)<<'\n';
}
