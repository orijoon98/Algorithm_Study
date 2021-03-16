#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int N, M;
char board[8][8];
char copy_board[65][8][8]; // board 복사 배열
bool flag1, flag2, flag3, flag4; // 방향 감시 여부

bool cam1[4][4] = { // rotate, flag1, flag2, flag3, flag4
    {1, 0, 0, 0},
    {0, 1, 0, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 1}
};

bool cam2[2][4] = {
    {1, 1, 0, 0},
    {0, 0, 1, 1}
};

bool cam3[4][4] = {
    {1, 0, 1, 0},
    {0, 1, 1, 0},
    {0, 1, 0, 1},
    {1, 0, 0, 1}
};

bool cam4[4][4] = {
    {1, 1, 1, 0},
    {1, 1, 0, 1},
    {1, 0, 1, 1},
    {0, 1, 1, 1}
};

bool cam5[1][4] = {
    {1, 1, 1, 1}
};

void cctv(int x, int y){ // board 감시 방향 #으로 바꾸는 함수
    if(flag1){
        for(int i=x-1;i>=0;i--){ // 위쪽 방향
            if(board[i][y] == '6') break;
            if(board[i][y] >= '1' && board[i][y] <= '5') continue;
            board[i][y] = '#';
        }
    }
    if(flag2){
        for(int i=x+1;i<N;i++){ // 아래쪽 방향
            if(board[i][y] == '6') break;
            if(board[i][y] >= '1' && board[i][y] <= '5') continue;
            board[i][y] = '#';
        }
    }
    if(flag3){
        for(int i=y+1;i<M;i++){ // 오른쪽 방향
            if(board[x][i] == '6') break;
            if(board[x][i] >= '1' && board[x][i] <= '5') continue;
            board[x][i] = '#';
        }
    }
    if(flag4){
        for(int i=y-1;i>=0;i--){ // 왼쪽 방향
            if(board[x][i] == '6') break;
            if(board[x][i] >= '1' && board[x][i] <= '5') continue;
            board[x][i] = '#';
        }
    }
}

void cctvNum(char n, int rotate){
    switch (n) {
        case '1':
            flag1 = cam1[rotate][0]; flag2 = cam1[rotate][1]; flag3 = cam1[rotate][2]; flag4 = cam1[rotate][3];
            break;
        case '2':
            flag1 = cam2[rotate][0]; flag2 = cam2[rotate][1]; flag3 = cam2[rotate][2]; flag4 = cam2[rotate][3];
            break;
        case '3':
            flag1 = cam3[rotate][0]; flag2 = cam3[rotate][1]; flag3 = cam3[rotate][2]; flag4 = cam3[rotate][3];
            break;
        case '4':
            flag1 = cam4[rotate][0]; flag2 = cam4[rotate][1]; flag3 = cam4[rotate][2]; flag4 = cam4[rotate][3];
            break;
        default: // case 5:
            flag1 = cam5[rotate][0]; flag2 = cam5[rotate][1]; flag3 = cam5[rotate][2]; flag4 = cam5[rotate][3];
            break;
    }
}

pair<char, pair<int, int>> cameras[64]; // 카메라 번호, 카메라 위치
int camera_num = 0; // 카메라 개수

int minimum = 100;

int cnt() { // 사각지대의 개수 반환
    int cnt = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(board[i][j] == '0') cnt++;
        }
    }
    return cnt;
}

void DFS(int n){ // n번째 cctv 적용, cctv가 최소 1개 있을때 실행
    memcpy(copy_board[n], board, sizeof(board)); // board 기존 상태 copy_board에 복사
    if(n == camera_num + 1){ // n번째 camera까지 모두 적용했을 때
        minimum = min(minimum, cnt());
    }
    else{
        for(int i=0;i<4;i++){ // rotate
            char cctvNumber = cameras[n-1].first; // 현재 cctv 번호
            if(cctvNumber == '2'){
                if(i == 2) break; // cctv2 일때 rotate 2번만 하므로 break
            }
            if(cctvNumber == '5'){
                if(i == 1) break; // cctv5 일때 rotate 1번만 하므로 break
            }
            cctvNum(cctvNumber, i); // cctv 방향 설정
            cctv(cameras[n-1].second.first, cameras[n-1].second.second); // 설정된 방향대로 #으로 변경
            
//            디버깅 부분
//            cout<<n<<": "<<cctvNumber<<' '<<"rotate: "<<i<<" cnt: "<<cnt()<<'\n';
//            cout<<flag1<<flag2<<flag3<<flag4<<'\n';
//            for(int a=0;a<N;a++){
//                for(int b=0;b<M;b++){
//                    cout<<board[a][b]<<' ';
//                }
//                cout<<'\n';
//            }
            DFS(n+1); // 다음 카메라 적용
            memcpy(board, copy_board[n], sizeof(copy_board[n])); // board를 기존상태로 되돌린다
        }
    }
}

int main() {
    FAST;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>board[i][j];
            if(board[i][j] >= '1' && board[i][j] <= '5'){
                cameras[camera_num++] = {board[i][j], {i, j}}; // 카메라 위치 저장
            }
        }
    }
    
    if(camera_num == 0){ // cctv가 없을 때
        cout<<cnt()<<'\n';
        return 0;
    }
    
    // cctv가 하나라도 있다면
    DFS(1); // 첫번째 cctv부터 DFS 적용해서 minimum 설정
    
    cout<<minimum<<'\n';
}
