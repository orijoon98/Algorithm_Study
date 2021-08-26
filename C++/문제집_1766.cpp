#include <bits/stdc++.h>
#define endl '\n'
#define MAX 32010
using namespace std;

int N, M;
int Entry[MAX];
vector<int> Node[MAX];

void Input(){
    cin>>N>>M;
    while(M--){
        int A, B;
        cin>>A>>B;
        Node[A].push_back(B);
        Entry[B]++;
    }
}

void Solution(){
    priority_queue<int> q;
    for(int i=1;i<=N;i++){
        if(Entry[i] == 0) q.push(-i);
    }
    while(!q.empty()){
        int cur = -q.top();
        q.pop();
        cout<<cur<<' ';
        for(int i=0;i<Node[cur].size();i++){
            int next = Node[cur][i];
            Entry[next]--;
            if(Entry[next] == 0) q.push(-next);
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
