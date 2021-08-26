#include <bits/stdc++.h>
#define endl '\n'
#define MAX 510
using namespace std;

int N;
int Entry[MAX];
int Time[MAX];
int MinTime[MAX];
vector<int> Build[MAX];

void Input(){
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>Time[i];
        MinTime[i] = Time[i];
        while(true){
            int num;
            cin>>num;
            if(num == -1) break;
            Entry[i]++;
            Build[num].push_back(i);
        }
    }
}

void Solution(){
    queue<int> q;
    for(int i=1;i<=N;i++){
        if(Entry[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int cur = q.front();
        int curTime = MinTime[cur];
        q.pop();
        for(int i=0;i<Build[cur].size();i++){
            int next = Build[cur][i];
            int nextTime = Time[next];
            Entry[next]--;
            MinTime[next] = max(MinTime[next], curTime + nextTime);
            if(Entry[next] == 0) q.push(next);
        }
    }
    for(int i=1;i<=N;i++) cout<<MinTime[i]<<endl;
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
