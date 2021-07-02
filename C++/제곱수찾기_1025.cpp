#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int N, M;
int ans = -1;
int board[10][10];

void Input(){
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        string str;
        cin>>str;
        for(int j=0;j<str.size();j++){
            board[i][j+1] = str[j] - 48;
        }
    }
}

bool isSqrt(int n){
    int root = sqrt(n);
    if(root * root == n) return true;
    return false;
}

void Solution(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            for(int x=-N;x<N;x++){
                for(int y=-M;y<M;y++){
                    if(x == 0 && y == 0) continue;
                    int a = i, b = j;
                    int now = 0;
                    while(a > 0 && a <= N && b > 0 && b <= M){
                        now *= 10;
                        now += board[a][b];
                        if(isSqrt(now)) ans = max(ans, now);
                        a += x;
                        b += y;
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Input();
    Solution();
}
