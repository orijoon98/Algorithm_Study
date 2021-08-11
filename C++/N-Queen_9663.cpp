#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int n, cnt;
int board[14][14];
int unable1[14]; // 열
int unable2[27]; // 왼쪽 아래 대각선
int unable3[27]; // 오른쪽 아래 대각선

void func(int k){
    if(k == n){
        cnt++;
        return;
    }
    for(int i=0;i<n;i++){
        if(unable1[i] || unable2[i+k] || unable3[k-i+n-1]) continue;
        unable1[i] = 1;
        unable2[i+k] = 1;
        unable3[k-i+n-1] = 1;
        func(k+1);
        unable1[i] = 0;
        unable2[i+k] = 0;
        unable3[k-i+n-1] = 0;
    }
}

int main() {
    FAST;
    cin>>n;
    func(0);
    cout<<cnt;
}
