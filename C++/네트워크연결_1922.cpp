#include <bits/stdc++.h>
using namespace std;

int N, M, ans;
vector<pair<int, pair<int, int>>> edge;
int parent[1001];

void Input(){
    cin>>N;
    cin>>M;
    for(int i=1;i<=M;i++){
        int a, b, c;
        cin>>a>>b>>c;
        edge.push_back({c,{a,b}});
    }
    sort(edge.begin(), edge.end());
    for(int i=1;i<=N;i++){
        parent[i] = i;
    }
}

int getRoot(int x){
    if(parent[x] == x) return x;
    return parent[x] = getRoot(parent[x]);
}

void Union(int x, int y){
    int X = getRoot(x);
    int Y = getRoot(y);
    if(X < Y) parent[Y] = X;
    else parent[X] = Y;
}

bool sameRoot(int x, int y){
    return getRoot(x) == getRoot(y);
}

void Sol(){
    for(auto cur: edge){
        int cost = cur.first;
        int left = cur.second.first;
        int right = cur.second.second;
        if(sameRoot(left, right)) continue;
        Union(left, right);
        ans += cost;
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
