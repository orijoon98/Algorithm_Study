#include <bits/stdc++.h>
#define endl '\n'
#define NMAX 110
#define MMAX 110
#define KMAX 1000010
#define ll long long

using namespace std;

int N, M;
int W[NMAX];
int V[NMAX];
int K[MMAX];
int dp[NMAX][KMAX];
int ans;
pair<ll, ll> tmp1;
pair<ll, ll> tmp2;

void Initialization() {
    memset(W, 0, sizeof(W));
    memset(V, 0, sizeof(V));
    memset(K, 0, sizeof(K));
    memset(dp, 0, sizeof(dp));
    ans = 1;
}

void Input() {
    cin>>N>>M;
    for (int i = 1; i <= N; i++) {
        cin>>W[i]>>V[i];
    }
    for (int i = 1; i <= M; i++) {
        cin>>K[i];
    }   
}

void Solution() {
    int maxK = 0;
    for (int k = 1; k <= M; k++) {
        maxK = max(maxK, K[k]);
    }
    for (int i = 1; i <= N; i++) {
        for (int w = 0; w <= maxK; w++) {
            if (w - W[i] >= 0) {
                dp[i][w] = max(dp[i-1][w], dp[i-1][w-W[i]] + V[i]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    for (int i = 2; i <= M; i++) {
        tmp1 = make_pair(K[ans], dp[N][K[ans]]);
        tmp2 = make_pair(K[i], dp[N][K[i]]);
        if (tmp1.second * tmp2.first < tmp1.first * tmp2.second) {
			ans = i;
		}
    }
    cout<<ans;
}

void Solve() {
    Initialization();
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