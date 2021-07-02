#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int N, M, ans;
int parent[100001];
vector<pair<int, pair<int, int>>> house;
vector<int> mst;

void Input(){
    cin>>N>>M;
    while(M--){
        int a, b, c;
        cin>>a>>b>>c;
        house.push_back({c,{a,b}});
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

void Solution(){
    sort(house.begin(), house.end());
    for(int i=1;i<=N;i++) parent[i] = i;
    for(int i=0;i<house.size();i++){
        if(!sameRoot(house[i].second.first, house[i].second.second)){
            Union(house[i].second.first, house[i].second.second);
            mst.push_back(house[i].first);
        }
    }
    for(int i=0;i<mst.size()-1;i++){
        ans += mst[i];
    }
    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Input();
    Solution();
}

