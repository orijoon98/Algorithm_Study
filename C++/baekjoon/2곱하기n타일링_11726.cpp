#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

long long dp[1001];

long long fibo(long long n){
    if(n == 1) {
        dp[1] = 1;
        return 1;
    }
    else if(n == 2) {
        dp[2] = 2;
        return 2;
    }
    else{
        long long a, b;
        if(dp[n-1] != 0) a = dp[n-1];
        else{
            a = fibo(n-1);
            dp[n-1] = a;
        }
        if(dp[n-2] != 0) b= dp[n-2];
        else{
            b = fibo(n-2);
            dp[n-2] = b;
        }
        long long c = a + b;
        if(c >= 10007) c -= 10007;
        return c;
    }
}

int main(){
    FAST;
    long long n;
    cin>>n;
    cout<<fibo(n)<<'\n';
}
