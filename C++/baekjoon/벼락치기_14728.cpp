#include <bits/stdc++.h>
#define endl '\n'
#define NMAX 110
#define TMAX 10010
#define KMAX 1010
#define SMAX 1010
using namespace std;

int N, T;
int dp[NMAX][TMAX];
int K[KMAX];
int S[SMAX];
int ans;

void Initialize() {
    memset(dp, 0, sizeof(dp));
    memset(K, 0, sizeof(K));
    memset(S, 0, sizeof(S));
}

void Input() {
    cin>>N>>T;
    for (int i = 1; i <= N; i++) {
        cin>>K[i]>>S[i];
    }
}

void Solution() {
    for (int i = 1; i <= N; i++) {
        for (int t = 0; t <= T; t++) {
            if (t - K[i] >= 0) {
                dp[i][t] = max(dp[i-1][t], dp[i-1][t-K[i]] + S[i]);
            } else {
                dp[i][t] = dp[i-1][t];
            }
            ans = max(ans, dp[i][t]);
        }
    }
    cout<<ans;
}

void Solve() {
    Initialize();
    Input();
    Solution();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solve();

    return 0;
}