#include <bits/stdc++.h>
#define endl '\n'
#define MAX 100000
using namespace std;

int N;
int rope[MAX];

void Input(){
    cin>>N;
    for(int i=0;i<N;i++) cin>>rope[i];
}

void Solution(){
    sort(rope, rope+N);
    int ans = 0;
    for(int i=1;i<=N;i++){
        ans = max(ans, rope[N-i] * i);
    }
    cout<<ans<<endl;
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

    return 0;
}
