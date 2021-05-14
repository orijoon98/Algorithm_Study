#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

bool board[10000][10000];

void input_star(int n, int x, int y){
    if(n == 3){
        board[x][y] = true;
        board[x+1][y-1] = true;
        board[x+1][y+1] = true;
        for(int i=0;i<5;i++){
            board[x+2][y-i+2] = true;
        }
        return;
    }
    input_star(n/2, x, y);
    input_star(n/2, x+n/2, y-n/2);
    input_star(n/2, x+n/2, y+n/2);
}

int main() {
    FAST;
    int n; cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<2*n-1;j++){
            board[i][j] = false;
        }
    }
    input_star(n,0,n-1);

    for(int i=0;i<n;i++){
        for(int j=0;j<2*n-1;j++){
            if(board[i][j]) cout<<"*";
            else cout<<" ";
        }
        cout<<'\n';
    }
}

