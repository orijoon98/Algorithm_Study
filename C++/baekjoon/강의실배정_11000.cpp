#include <bits/stdc++.h>
#define endl '\n'
#define MAX 100
using namespace std;

int N, ans;
vector<pair<int,int>> v;
vector<int> vv; // finish 시간
priority_queue<int, vector<int>, greater<int>> pq; // finish 시간, 오름차순

void Input(){
    cin>>N;
    for(int i=1;i<=N;i++){
        int start, finish;
        cin>>start>>finish;
        v.push_back({start,finish});
    }
}

void Solution(){
    sort(v.begin(), v.end());
    pq.push(v[0].second);
    for(int i=1;i<v.size();i++){
        if(pq.top() <= v[i].first){
            pq.pop();
            pq.push(v[i].second);
        }
        else{
            pq.push(v[i].second);
        }
    }
    cout<<pq.size()<<endl;
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
