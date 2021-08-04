#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int N;
vector<pair<int, int>> v, ans;


void Input(){
    cin>>N;
    for(int i=0;i<N;i++){
        int start, finish;
        cin>>start>>finish;
        v.push_back({finish,start});
    }
}

void Solution(){
    sort(v.begin(), v.end()); // 도착시간 순으로 정렬
    ans.push_back(v[0]);
    for(int i=1;i<v.size();i++){
        int arrive = ans[ans.size()-1].first; // 마지막 도착시간
        if(v[i].second >= arrive) ans.push_back(v[i]);
    }
    cout<<ans.size()<<endl;
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
