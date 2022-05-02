#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int N;
vector<pair<int, int>> v, ans;

void Input() {
    cin>>N;
    for (int i = 0; i < N; i++) {
        int start, end;
        cin>>start>>end;
        v.push_back({end, start});
    }
}

void Solution() {
    sort(v.begin(), v.end()); // 끝나는 시간 순으로 정렬
    ans.push_back(v[0]);
    for (int i = 1; i < v.size(); i++) {
        int end = ans[ans.size()-1].first; // 마지막 회의가 끝나는 시간
        if (v[i].second >= end) ans.push_back(v[i]);
    }
    cout<<ans.size()<<endl;
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