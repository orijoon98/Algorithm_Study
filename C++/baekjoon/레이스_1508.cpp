#include <bits/stdc++.h>
#define endl '\n'
#define MAX 1000010

using namespace std;

int N, M, K;
vector<int> able;
string ans;

void Input() {
    cin>>N>>M>>K;
    for (int i = 0; i < K; i++) {
        int a;
        cin>>a;
        able.push_back(a);
    }
    sort(able.begin(), able.end());
}

string BinarySearch() {
    int left = 0;
    int right = N;
    int mid; // 두 심판 사이의 최소 거리
    while (left <= right) {
        string cur = "";
        mid = (left + right) / 2;
        int prev = 0;
        int cnt = 1;
        cur.push_back('1');
        for (int i = 1; i < K; i++) {
            if (cnt == M) break;
            if (able[i] - able[prev] >= mid) {
                cur.push_back('1');
                cnt++;
                prev = i;
            } else 
                cur.push_back('0');
        }
        while (cur.length() < K) cur.push_back('0');
        if (cnt == M) {
            left = mid + 1;
            ans = cur;
        } else
            right = mid - 1;        
    }
    return ans;
}

void Solution() {
    cout<<BinarySearch()<<endl;
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