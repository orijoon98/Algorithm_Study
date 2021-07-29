#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
const ll Divide = 1000000003;
int N, K;
ll ans[1001][1001];

ll Solve() {

    ans[2][1] = 2;
    ans[3][1] = 3;

    for (int i = 4; i <= N; i++) {
        ans[i][1] = i;
        for (int j = 2; j <= K; j++) {
            if (j > i / 2) break;
            ans[i][j] = (ans[i - 2][j - 1] + ans[i - 1][j]) % Divide;
        }
    }

    return ans[N][K];
}

int main() {
    FAST;
    cin >> N >> K;

    if (N / 2 < K) cout << "0" << '\n';
    else cout << Solve() << '\n';;
}