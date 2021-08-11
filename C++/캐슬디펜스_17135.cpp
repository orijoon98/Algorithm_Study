#include <bits/stdc++.h>
#define endl '\n'
#define MAX 17
using namespace std;

int N, M, D, ans;
int board[MAX][MAX];
int board2[MAX][MAX]; // board의 초기 상태 저장해둘 배열
bool flag;// 궁수가 공격할 대상 정했는지
int passed; // 이미 캐슬로 도달해서 무시하는 행
set<pair<int,int>> willAttack; // 공격 당할 적의 위치

void Input(){
    cin>>N>>M>>D;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>board[i][j];
            board2[i][j] = board[i][j];
        }
    }
}

int dist(int a, int b, int x, int y){
    int d = abs(a-x) + abs(b-y);
    return d;
}

void searchAttack(int x, int y, int d){ // 궁수의 위치 x,y 거리 d
    for(int b=1;b<=M;b++){
        for(int a=N-passed;a>=1;a--){
            if(board[a][b] == 1){
                if(dist(a,b,x,y) == d){
                    willAttack.insert({a,b});
                    flag = true;
                    return;
                }
            }
        }
    }
}

void Solution(){
    for(int a=1;a<=M-2;a++){
        for(int b=a+1;b<=M-1;b++){
            for(int c=b+1;c<=M;c++){
                //궁수의 위치 N+1 행, a, b, c 열
                int curAns = 0;
                passed = 0;
                for(int i=1;i<=N;i++){
                    for(int j=1;j<=M;j++){
                        board[i][j] = board2[i][j];
                    }
                }
                while(passed != N){
                    flag = false;
                    for(int i=1;i<=D;i++){
                        if(!flag)
                            searchAttack(N+1, a, i+passed);
                    }
                    flag = false;
                    for(int i=1;i<=D;i++){
                        if(!flag)
                            searchAttack(N+1, b, i+passed);
                    }
                    flag = false;
                    for(int i=1;i<=D;i++){
                        if(!flag)
                            searchAttack(N+1, c, i+passed);
                    }
                    curAns += willAttack.size();
                    for(auto cur: willAttack){
                        board[cur.first][cur.second] = 0;
                    }
                    willAttack.clear();
                    passed++;
                }
                ans = max(ans, curAns);
            }
        }
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
