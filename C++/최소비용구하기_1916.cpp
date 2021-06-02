#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define INF 987654321
#define MAX 1001

int N, M;
int start, finish;
int dis[MAX];
vector<pair<int, int>> vertex[MAX];

void input(){
    cin>>N;
    cin>>M;
    while(M--){
        int a, b, c;
        cin>>a>>b>>c;
        vertex[a].push_back({b,c});
    }
    cin>>start>>finish;
    fill(dis, dis+MAX, INF);
}

void solution(){
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    dis[start] = 0;
    while(!pq.empty()){
        int dist = -pq.top().first; // 현재 노드까지의 비용
        int cur = pq.top().second; // 현재 노드
        pq.pop();
        if(dis[cur] < dist) continue; // 이미 최단경로를 체크한 노드인 경우 패스
        for(int i=0;i<vertex[cur].size();i++){
            int next = vertex[cur][i].first;
            int cost = dist + vertex[cur][i].second;
            if(cost < dis[next]){
                dis[next] = cost;
                pq.push({-cost,next});
            }
        }
    }
    cout<<dis[finish];
}

int main(){
    FAST;
    input();
    solution();
}
