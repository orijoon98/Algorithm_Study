#include <bits/stdc++.h>
#define endl '\n'
#define MAX INT_MAX

using namespace std;

int N, S, ans = 0;
vector<int> arr;

void Input() {
    cin>>N>>S;
    for (int i = 0; i < N; i++) {
        int n;
        cin>>n;
        arr.push_back(n);
    }
}

void Solution() {
    for (int r = 1; r <= N; r++) {
        vector<bool> temp(N, false);
        for (int i = 0; i < r; i++) {
            temp[i] = true;
        }
        do { 
            int cur = 0;
            for (int i = 0; i < N; i++) {
                if (temp[i]) {
                    cur += arr[i];
                }
            }
            if (cur == S) ans++;
        } while (prev_permutation(temp.begin(), temp.end()));
    }
    cout<<ans<<endl;
}

void Solve() {
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