#include <bits/stdc++.h>
#define endl '\n'
#define MAX 50
using namespace std;

int N;
int A[MAX], B[MAX];

void Input(){
    cin>>N;
    for(int i=0;i<N;i++) cin>>A[i];
    for(int i=0;i<N;i++) cin>>B[i];
}

void Solution(){
    sort(A, A+N);
    sort(B, B+N);
    int ans = 0;
    for(int i=0;i<N;i++){
        ans += A[i] * B[N-1-i];
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
