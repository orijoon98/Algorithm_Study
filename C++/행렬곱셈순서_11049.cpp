#include <bits/stdc++.h>
#define endl '\n'
#define MAX 501
using namespace std;

int N;
int num[MAX][2];
int dp[MAX][MAX]; // i번째부터 j번째까지 곱한 최솟값

void Setting(){
    for(int i=0;i<MAX;i++) fill(dp[i], dp[i] + MAX, INT_MAX);
}

void Input(){
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>num[i][0]>>num[i][1];
    }
}

int Solution(int left, int right){
    if(left == right) return 0;
    if(dp[left][right] != INT_MAX) return dp[left][right];
    for(int i=left;i<right;i++){
        dp[left][right] = min(dp[left][right], Solution(left, i) + Solution(i+1, right) + num[left][0] * num[i][1] * num[right][1]);
    }
    
    return dp[left][right];
}

void Solve(){
    Setting();
    Input();
    cout<<Solution(1, N)<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solve();

    return 0;
}
