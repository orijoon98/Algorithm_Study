#include <bits/stdc++.h>
#define endl '\n'
#define MAX 10
using namespace std;

int N, K, ans;
int coin[MAX];

void Input(){
    cin>>N>>K;
    for(int i=0;i<N;i++){
        cin>>coin[i];
    }
}

void Solution(){
    for(int i=N-1;i>=0;i--){
        int cur = 0;
        while(true){
            if(K - coin[i] < 0) break;
            K -= coin[i];
            cur++;
        }
        ans += cur;
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
