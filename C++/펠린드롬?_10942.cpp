#include <bits/stdc++.h>
#define endl '\n'
#define MAX 2001
using namespace std;

int N, M;
int arr[MAX];
vector<pair<int, int>> v;
bool dp[MAX][MAX]; // i번째 부터 j번째까지 펠린드롬인지 아닌지

void Input(){
    cin>>N;
    for(int i=1;i<=N;i++) cin>>arr[i];
    cin>>M;
    for(int i=1;i<=M;i++){
        int a, b;
        cin>>a>>b;
        v.push_back({a,b});
    }
}

void Solution(){
    for(int i=1;i<=N;i++){ // 0칸, 2칸, 4칸 ... 짝수 칸들에 대한 모든 경우
        dp[i][i] = true;
        int x = i, y = i;
        while(true){
            if(x-1 < 1 || y+1 > N) break;
            x--; y++;
            if(arr[x] != arr[y]) break;
            dp[x][y] = true;
        }
    }
    for(int i=1;i<=N-1;i++){ // 1칸, 3칸, 5칸 ... 홀수 칸들에 대한 모든 경우
        int x = i, y = i + 1;
        while(true){
            if(arr[x] != arr[y]) break;
            dp[x][y] = true;
            if(x-1 < 1 || y+1 > N) break;
            x--; y++;
        }
    }
    for(auto cur: v){
        cout<<dp[cur.first][cur.second]<<endl;
    }
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
