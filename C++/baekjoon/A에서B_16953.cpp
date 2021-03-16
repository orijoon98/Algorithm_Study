#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

long long A, B;
int ans = INT_MAX;
queue<pair<long long,int>> q;

void Input(){
    cin>>A>>B;
}

void Solution(){
    q.push({A,1});
    while(!q.empty()){
        long long cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        long long next1 = cur * 2;
        long long next2 = cur * 10 + 1;
        int nextCnt = cnt + 1;
        if(next1 == B || next2 == B){
            ans = nextCnt;
            return;
        }
        if(next1 < B) q.push({next1, nextCnt});
        if(next2 < B) q.push({next2, nextCnt});
    }
}

void Solve(){
    Input();
    Solution();
    if(ans == INT_MAX) cout<<-1<<endl;
    else cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solve();

    return 0;
}
