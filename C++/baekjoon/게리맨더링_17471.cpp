#include <bits/stdc++.h>
#define MAX 11
#define endl '\n'
using namespace std;

int N, ans;
int Population[MAX];
bool Selected[MAX];
bool Visit[MAX];
vector<int> Adj[MAX];

void Input(){
    cin>>N;
    for(int i=1;i<=N;i++) cin>>Population[i];
    for(int i=1;i<=N;i++){
        int n;
        cin>>n;
        for(int j=0;j<n;j++){
            int node;
            cin>>node;
            Adj[i].push_back(node);
        }
    }
}

bool isConnected(vector<int> &v, bool flag){
    memset(Visit, false, sizeof(Visit));
    queue<int> q;
    Visit[v[0]] = true;
    q.push(v[0]);
    int cnt = 1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto value: Adj[x]){
            if(Selected[value] != flag || Visit[value]) continue;
            cnt++;
            Visit[value] = true;
            q.push(value);
        }
    }
    if(v.size() == cnt) return true;
    else return false;
}

bool isOK(){
    vector<int> a;
    vector<int> b;
    for(int i=1;i<=N;i++){
        if(Selected[i]) a.push_back(i);
        else b.push_back(i);
    }
    if(a.empty() || b.empty()) return false;
    if(!isConnected(a, true)) return false;
    if(!isConnected(b, false)) return false;
    return true;
}

void calcu(){
    int a_sum = 0;
    int b_sum = 0;
    for(int i=1;i<=N;i++){
        if(Visit[i]) a_sum += Population[i];
        else b_sum += Population[i];
    }
    ans = min(ans, abs(a_sum - b_sum));
}

void DFS(int start, int depth){
    if(depth >= 1){
        if(isOK()){
            calcu();
        }
    }
    for(int i=start;i<=N;i++){
        if(Selected[i]) continue;
        Selected[i] = true;
        DFS(i+1, depth+1);
        Selected[i] = false;
    }
}

void Solution(){
    ans = INT_MAX;
    DFS(1,0);
    if(ans == INT_MAX) ans = -1;
    cout<<ans<<endl;
}

void Solve(){
    Input();
    Solution();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solve();

    return 0;
}