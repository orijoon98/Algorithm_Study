#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int t[1500001];
int p[1500001];
int dp[1500001];

int main() {
    FAST;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t[i]>>p[i];
    }
    int mx = 0;
    for(int i=1;i<=n+1;i++){
        mx = max(mx, dp[i]);
        if(i + t[i] > n + 1) continue;
        dp[i + t[i]] = max(mx + p[i], dp[i + t[i]]);
    }
    cout<<mx<<'\n';
}
