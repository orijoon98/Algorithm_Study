#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MAX 20010
#define INF 987654321

int V, E, K;
int Dist[MAX];
vector<pair<int, int>> Vertex[MAX];

void input(){
    cin>>V>>E;
    cin>>K;
    while(E--){
        int u, v, w;
        cin>>u>>v>>w;
        Vertex[u].push_back({v,w});
    }
    for(int i=1;i<=V;i++) Dist[i] = INF;
}

void solution(){
    priority_queue<pair<int, int>> PQ;
    PQ.push({0,K});
    Dist[K] = 0;
    while(!PQ.empty()){
        int cost = -PQ.top().first;
        int cur = PQ.top().second;
        PQ.pop();

        for(int i=0;i<Vertex[cur].size();i++){
            int next = Vertex[cur][i].first;
            int nCost = Vertex[cur][i].second;
            if(Dist[next] > cost + nCost){
                Dist[next] = cost + nCost;
                PQ.push({-Dist[next],next});
            }
        }
    }
    for(int i=1;i<=V;i++){
        if(Dist[i] == INF) cout<<"INF"<<'\n';
        else cout<<Dist[i]<<'\n';
    }
}

int main(){
    FAST;
    input();
    solution();
}
