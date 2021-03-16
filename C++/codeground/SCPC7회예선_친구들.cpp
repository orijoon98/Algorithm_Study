#include <bits/stdc++.h>
#define endl '\n'
#define MAX 100001
using namespace std;

int T, N, root[MAX], people[MAX];
set<int> s;

int find(int x){
    if(root[x] == x){
        return x;
    } else {
        return root[x] = find(root[x]);
    }
}

void Union(int x, int y){
    x = find(x);
    y = find(y);
    if(x > y){
        root[x] = y;
    } else{
        root[y] = x;
    }
}

void Print(){
    for(int i=1;i<=N;i++){
        cout<<root[i]<<' ';
    }
    cout<<endl;
}

void Solution(){
    cin>>T;
    for(int t=1;t<=T;t++){
        cin>>N;
        for(int i=1;i<=N;i++){
            cin>>people[i];
            root[i] = i;
        }
        for(int i=1;i<=N;i++){
            int x = i;
            int y = i + people[i];
            if(y <= N){
                int rx = find(x);
                int ry = find(y);
                Union(rx, ry);
            }
        }
        for(int i=1;i<=N;i++){
            root[i] = find(i);
            s.insert(root[i]);
        }
        cout<<"Case #"<<t<<endl;
        cout<<s.size()<<endl;
        s.clear();
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Solution();
}
