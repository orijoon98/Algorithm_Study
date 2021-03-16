#include <bits/stdc++.h>
#define endl '\n'
#define MAX 32010
using namespace std;

int N, M;
vector<int> node[MAX];
int incoming[MAX];


void Input(){
    cin>>N>>M;
    for(int i=1;i<=M;i++){
        int a, b;
        cin>>a>>b;
        node[a].push_back(b);
        incoming[b]++;
    }
}

void Solution(){
    queue<int> q;
    for(int i=1;i<=N;i++){
        if(incoming[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int cur = q.front();
        cout<<cur<<' ';
        q.pop();
        for(int i=0;i<node[cur].size();i++){
            int next = node[cur][i];
            incoming[next]--;
            if(incoming[next] == 0) q.push(next);
        }
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
