#include <bits/stdc++.h>
#define endl '\n'
#define MAX 10001
using namespace std;

int N, L;
vector<pair<int,int>> water;

void Input(){
    cin>>N>>L;
    for(int i=1;i<=N;i++){
        int a, b;
        cin>>a>>b;
        water.push_back({a,b-1});
    }
}

void Solution(){
    sort(water.begin(), water.end());
    int cnt = 0;
    int tmp = 0;
    for(int i=0;i<water.size();i++){
        if(tmp < water[i].first){
            tmp = water[i].first + L - 1;
            cnt++;
        }
        while(tmp < water[i].second){
            cnt++;
            tmp += L;
        }
    }
    cout<<cnt<<endl;
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
