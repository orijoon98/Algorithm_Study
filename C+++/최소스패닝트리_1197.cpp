#include <bits/stdc++.h>
using namespace std;
#define edgeMAX 100001
#define nodeMAX 10001
#define left second.first
#define right second.second
#define cost first

int V, E, ans;
vector<pair<int, pair<int, int>>> edge; // 가중치, A정점, B정점
int parent[nodeMAX];

void Input(){
    cin>>V>>E;
    for(int i=1;i<=E;i++){
        int A, B, C;
        cin>>A>>B>>C;
        edge.push_back({C,{A,B}});
    }
    sort(edge.begin(), edge.end()); // 가중치 오름차순으로 정렬
    for(int i=1;i<=V;i++){
        parent[i] = i;
    }
}

int getRoot(int x){
    if(parent[x] == x) return x;
    return parent[x] = getRoot(parent[x]);
}

void Union(int a, int b){
    int A = getRoot(a);
    int B = getRoot(b);
    if(A < B) parent[B] = A;
    else parent[A] = B;
}

bool sameRoot(int a, int b){
    return getRoot(a) == getRoot(b);
}

void Sol(){
    for(int i=0;i<E;i++){
        int nodeL = edge[i].left;
        int nodeR = edge[i].right;
        int cos = edge[i].cost;
        if(sameRoot(nodeL, nodeR)) continue;
        Union(nodeL, nodeR);
        ans += cos;
    }
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Input();
    Sol();
}
