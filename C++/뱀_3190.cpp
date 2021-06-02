#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int N, K, L;
int t = 0; // 게임 시간

int board[101][101];
int dx[4] = {0, 1, 0, -1}; // 우, 하, 좌, 상 -> 오른쪽 회전 순서
int dy[4] = {1, 0, -1, 0}; // 우, 하, 좌, 상 -> 오른쪽 회전 순서
queue<pair<int, char>> inputdata; // 게임 시간, 방향
queue<pair<int, int>> snake; // 뱀의 좌표

void debug(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cout<<board[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
}

void input(){
    cin>>N;
    cin>>K;
    while(K--){
        int x, y;
        cin>>x>>y;
        board[x][y] = -1; // 사과는 -1 로 저장
    }
    cin>>L;
    while(L--){
        int time;
        char dir;
        cin>>time>>dir;
        inputdata.push({time,dir});
    }
}

void gameStart(){
    int dir = 0; // 최초 방향은 오른쪽 방향
    int x = 1, y = 1;
    board[x][y] = 1; // 뱀은 1 로 저장
    snake.push({1,1});
//    debug();
    while(true){
        int time = inputdata.front().first;
        t++;
        x = x + dx[dir];
        y = y + dy[dir];
        if(x < 1 || x > N || y < 1 || y > N) break; // 범위 밖 벗어나면 게임 종료
        if(board[x][y] == 1) break; // 자신의 몸과 부딪히면 게임 종료
        if(board[x][y] == -1){ // 사과와 만난다면
            board[x][y] = 1; // 사과가 없어지고 꼬리는 움직이지 않는다
            snake.push({x,y});
        }
        else{ // 자신의 몸도 아니고 사과도 아니라면 -> 빈 칸이라면
            board[x][y] = 1;
            board[snake.front().first][snake.front().second] = 0; // 꼬리가 위치한 칸을 비워준다
            snake.pop();
            snake.push({x,y});
        }
        if(t == time){
            if(inputdata.front().second == 'D'){ // 방향이 오른쪽이라면
                if(dir<3) dir++;
                else dir = 0;
            }
            else{ // 방향이 왼쪽이라면
                if(dir>0) dir--;
                else dir = 3;
            }
            inputdata.pop(); // 다음 시간 체크 준비
        }
//        debug();
    }
}

int main(){
    FAST;
    input();
    gameStart();
    cout<<t;
}
