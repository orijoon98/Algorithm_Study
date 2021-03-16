#include <bits/stdc++.h>
#define MAX 21
#define endl '\n'
using namespace std;

int N, ans;
int MAP[MAX][MAX];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void Input(){
    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>MAP[i][j];
        }
    }
}

void Move(int dir){
    // 0 : 아래쪽
    // 1 : 오른쪽
    // 2 : 위쪽
    // 3 : 왼쪽
    deque<int> d;
    switch(dir){
        case 0:
        for(int j=1;j<=N;j++){
            int index = -1; // 이미 합쳐진 블록의 인덱스
            for(int i=N;i>=1;i--){
                if(MAP[i][j] == 0) continue;
                d.push_back(MAP[i][j]);
                if(d.size() >= 2){
                    if(d.size()-1 == index || d.size()-2 == index) continue;
                    int a = d[d.size()-1];
                    int b = d[d.size()-2];
                    if(a == b){
                        d.pop_back();
                        d.pop_back();
                        d.push_back(a+b);
                        index = d.size() - 1;
                    }
                }
            }
            for(int i=N;i>=1;i--){
                if(d.size() == 0) MAP[i][j] = 0;
                else{
                    MAP[i][j] = d[0];
                    ans = max(ans, d[0]);
                    d.pop_front();
                }
            }
        }
        break;

        case 1:
        for(int i=1;i<=N;i++){
            int index = -1; // 이미 합쳐진 블록의 인덱스
            for(int j=N;j>=1;j--){
                if(MAP[i][j] == 0) continue;
                d.push_back(MAP[i][j]);
                if(d.size() >= 2){
                    if(d.size()-1 == index || d.size()-2 == index) continue;
                    int a = d[d.size()-1];
                    int b = d[d.size()-2];
                    if(a == b){
                        d.pop_back();
                        d.pop_back();
                        d.push_back(a+b);
                        index = d.size() - 1;
                    }
                }
            }
            for(int j=N;j>=1;j--){
                if(d.size() == 0) MAP[i][j] = 0;
                else{
                    MAP[i][j] = d[0];
                    ans = max(ans, d[0]);
                    d.pop_front();
                }
            }
        }
        break;

        case 2:
        for(int j=1;j<=N;j++){
            int index = -1; // 이미 합쳐진 블록의 인덱스
            for(int i=1;i<=N;i++){
                if(MAP[i][j] == 0) continue;
                d.push_back(MAP[i][j]);
                if(d.size() >= 2){
                    if(d.size()-1 == index || d.size()-2 == index) continue;
                    int a = d[d.size()-1];
                    int b = d[d.size()-2];
                    if(a == b){
                        d.pop_back();
                        d.pop_back();
                        d.push_back(a+b);
                        index = d.size() - 1;
                    }
                }
            }
            for(int i=1;i<=N;i++){
                if(d.size() == 0) MAP[i][j] = 0;
                else{
                    MAP[i][j] = d[0];
                    ans = max(ans, d[0]);
                    d.pop_front();
                }
            }
        }
        break;

        case 3:
        for(int i=1;i<=N;i++){
            int index = -1; // 이미 합쳐진 블록의 인덱스
            for(int j=1;j<=N;j++){
                if(MAP[i][j] == 0) continue;
                d.push_back(MAP[i][j]);
                if(d.size() >= 2){
                    if(d.size()-1 == index || d.size()-2 == index) continue;
                    int a = d[d.size()-1];
                    int b = d[d.size()-2];
                    if(a == b){
                        d.pop_back();
                        d.pop_back();
                        d.push_back(a+b);
                        index = d.size() - 1;
                    }
                }
            }
            for(int j=1;j<=N;j++){
                if(d.size() == 0) MAP[i][j] = 0;
                else{
                    MAP[i][j] = d[0];
                    ans = max(ans, d[0]);
                    d.pop_front();
                }
            }
        }
        break;

        default:
        cout<<"ERROR"<<endl;
        return;
    }
}

void Track(int cnt){
    if(cnt == 5){
        return;
    }
    for(int dir=0;dir<4;dir++){
        int tmp[MAX][MAX]{}; // 0으로 초기화
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                tmp[i][j] = MAP[i][j]; // 기존 상태 저장
            }
        }
        Move(dir);
        Track(cnt + 1);
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                MAP[i][j] = tmp[i][j]; // 기존 상태 복구
            }
        }
    }
}

void Print(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cout<<MAP[i][j]<<' ';
        }
        cout<<endl;
    }
}

void Solution(){
    Track(0);
    cout<<ans<<endl;
}

void Solve(){
    Input();
    Solution();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solve();

    return 0;
}