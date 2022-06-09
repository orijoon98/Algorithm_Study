#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int N, M, L, ans;
vector<int> rest;

void Input() {
    cin>>N>>M>>L;
    // 휴게소를 놓을 수 없는 위치 추가
    rest.push_back(0);
    rest.push_back(L);
    int position;
    for (int i = 0; i < N; i++) {
        cin>>position;
        rest.push_back(position);
    }
    sort(rest.begin(), rest.end());
}

int BinarySearch() {
    int left = 0;
    int right = L;
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (mid == 0) { // DivisonByZero 예외처리
            left = mid + 1;
            continue;
        }        
        int cnt = 0; // 휴게소 사이에 배치 될 수 있는 휴게소 개수
        for (int i = 1; i < rest.size(); i++) {
            int dist = rest[i] - rest[i-1]; // 인접한 두 휴게소 사이의 거리
            cnt += (dist / mid);
            if (dist % mid == 0) cnt--; // 휴게소가 이미 있는 위치라면 하나 감소
        }
        if (cnt > M) 
            left = mid + 1;
        else {
            right = mid - 1;
            ans = mid;
        }
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