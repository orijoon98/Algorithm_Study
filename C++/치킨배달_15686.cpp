#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int N, M, chicken_num;
int board[52][52];
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
bool vis[15];
//int chicken_len[102]; // n번째 집에서의 치킨거리 목록
//int cpy[102];
int chicken_x, chicken_y;
int minimum = 987654321;
vector<pair<int, int>> selected;
//vector<pair<int, int>> selected_arr[1000000];
//int selected_num = 0; // 조합의 개수
//int sum = 0;
int Min(int A, int B) { if (A < B) return A; return B; }

int cal_dist(){
    int sum = 0;
    for(int i=0;i<house.size();i++){
        int x = house[i].first;
        int y = house[i].second;
        int cur = 987654321;
        for(int j=0;j<selected.size();j++){
            int xx = selected[j].first;
            int yy = selected[j].second;
            int dist = abs(xx - x) + abs(yy - y);
            cur = Min(cur, dist);
        }
        sum = sum + cur;
    }
    return sum;
}

//int house_chicken_len(int n){
//    int x = house[n].first;
//    int y = house[n].second;
//    int len;
//    len = abs(x - chicken_x) + abs(y - chicken_y);
//    return len;
//}

//void cal() {
//    for(int i=0;i<selected_num;i++){
//        for(int j=0;j<selected_arr[i].size();j++){
//            chicken_x = selected_arr[i][j].first;
//            chicken_y = selected_arr[i][j].second;
//            for(int k=0;k<house.size();k++){
//                chicken_len[k] = min(chicken_len[k], house_chicken_len(k));
//            }
//        }
//        for(int j=0;j<house.size();j++){
//            sum += chicken_len[j];
//        }
//        minimum = min(sum, minimum);
//        sum = 0;
//        memcpy(chicken_len, cpy, sizeof(cpy));
//    }
//}

void track(int n, int index) { // n번째 치킨집
    if(n == M + 1){ // M번째 치킨집까지 적용완료
//        selected_arr[selected_num++] = selected;
        minimum = Min(minimum, cal_dist());
        return;
    }
    for(int i=index;i<chicken_num;i++){
        if(!vis[i]){
            vis[i] = true;
            selected.push_back(chicken[i]);
            // 집들 각각에 치킨거리 목록 만들기
            track(n+1, i);
            vis[i] = false;
            selected.pop_back();
        }
    }
}

int main(){
    FAST;
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>board[i][j];
            if(board[i][j] == 1) house.push_back({i,j}); // 집 좌표 저장
            if(board[i][j] == 2) chicken.push_back({i,j}); // 치킨집 좌표 저장
        }
    }
    chicken_num = chicken.size();
//    fill(chicken_len, chicken_len + 102, 987654321);
//    memcpy(cpy, chicken_len, sizeof(chicken_len));
    track(1, 0);
//    cal();
    cout<<minimum;
}
