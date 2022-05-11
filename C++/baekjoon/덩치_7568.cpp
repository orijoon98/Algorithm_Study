#include <bits/stdc++.h>
#define endl '\n'
#define MAX 51

using namespace std;

int N;
int man[MAX][2];
vector<int> ans;

void Input() {
    cin>>N;
    for (int i = 1; i <= N; i++) {
        cin>>man[i][0]>>man[i][1];
    }
}

void Solution() {
    for (int i = 1; i <= N; i++) {
        int cnt = 0;
        for (int j = 1; j <= N; j++) {
            if (man[i][0] < man[j][0] && man[i][1] < man[j][1]) {
                cnt++;
            }
        }
        ans.push_back(cnt + 1);
    }
    for (int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<' ';
    }
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