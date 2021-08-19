#include <bits/stdc++.h>
#define endl '\n'
#define MAX 501
using namespace std;

int T, K;
int dp[MAX][MAX]; // i 부터 j 까지 합치는 최소 비용
int file[MAX];
int Sum[MAX];

void Setting(){
    for(int i=0;i<MAX;i++) fill(dp[i], dp[i]+MAX, INT_MAX);
}

int Solution(int start, int end){
    int &ref = dp[start][end];
    if(ref != INT_MAX) return ref;
    if(start == end) return ref = 0;
    
    for(int i=start;i<end;i++){
        ref = min(ref, Solution(start, i) + Solution(i+1, end));
    }
    return ref += Sum[end] - Sum[start - 1];
}

void Solve(){
    cin>>T;
    while(T--){
        cin>>K;
        Setting();
        for(int i=1;i<=K;i++){
            cin>>file[i];
            Sum[i] = Sum[i-1] + file[i];
        }
        cout<<Solution(1, K)<<endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solve();

    return 0;
}
