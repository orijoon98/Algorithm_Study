#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int N, K;
int Weight[101];
int Value[101];
int DP[101][100001];

void Input(){
    cin>>N>>K;
    for(int i=1;i<=N;i++){
        cin>>Weight[i]>>Value[i];
    }
}

void Solution(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=K;j++){
            if(j >= Weight[i]) DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - Weight[i]] + Value[i]);
            else DP[i][j] = DP[i - 1][j];
        }
    }
    cout << DP[N][K] << endl;
}

void Solve(){
    Input();
    Solution();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Solve();
}
