#include <bits/stdc++.h>
#define MAX 100000
#define endl '\n'
using namespace std;

int n, ans;
set<pair<int,int>> s; // 중복 체크
vector<pair<int,int>> v;
vector<pair<int,int>> vy; // y축 정렬을 위한 벡터
vector<pair<int,pair<int,int>>> divided;
vector<pair<int,pair<int,int>>> tmp;

void Input(){
    cin>>n;
    for(int i=0;i<n;i++){
        int a, b;
        cin >> a >> b;
        v.push_back({a,b});
        s.insert({a,b});
    }
}

bool compare(pair<int,int>a, pair<int,int>b){ // y 기준 정렬
    return a.second < b.second;
}


int Distance(int left, int right, int d){
    vy.clear();
    for(int i=left;i<=right;i++){
        vy.push_back(v[i]);
    }
    sort(vy.begin(), vy.end(), compare);
    int minD = INT_MAX;
    for(int i=0;i<vy.size();i++){
        for(int j=i+1;j<vy.size();j++){
            int lx = vy[i].first;
            int ly = vy[i].second;
            int rx = vy[j].first;
            int ry = vy[j].second;
            if(ry - ly > d) break;
            int curD = (lx - rx) * (lx - rx) + (ly - ry) * (ly - ry);
            minD = min(minD, curD);
        }
    }
    return minD;
}

void Divide(){
    if(v.size() <= 3) {
        divided.push_back({Distance(0,v.size()-1,INT_MAX),{0,v.size() - 1}});
        return;
    }
    if(v.size() % 2 == 0) {
        for(int i=1;i<=v.size()-1;i+=2){
            divided.push_back({Distance(i-1,i,INT_MAX),{i-1,i}});
        }
        return;
    }
    else {
        divided.push_back({Distance(0,2,INT_MAX),{0,2}});
        for(int i=4;i<=v.size()-1;i+=2){
            divided.push_back({Distance(i-1,i,INT_MAX),{i-1,i}});
        }
        return;
    }
}

void Conqure(){
    int left;
    int right;
    while (divided.size() != 1){
        tmp.clear();
        for(int i=1;i<divided.size();i+=2){
            int dl = divided[i-1].first;
            int dr = divided[i].first;
            int curD = sqrt(min(dl, dr));
            int left_start = divided[i-1].second.first;
            int left_end = divided[i-1].second.second;
            left = left_end;
            int lcmp = v[left_end].first - curD;
            for(int l=left_end;l>=left_start;l--){
                if(v[l].first < lcmp) break;
                left = l;
            }
            int right_start = divided[i].second.first;
            int right_end = divided[i].second.second;
            right = right_end;
            int rcmp = v[right_start].first + curD;
            for(int r=right_start;r<=right_end;r++){
                if(v[r].first > rcmp) break;
                right = r;
            }
            int tmpD = Distance(left, right, curD);
            curD = min(dl, dr);
            curD = min(curD, tmpD);
            tmp.push_back({curD,{left_start, right_end}});
        }
        if(divided.size() % 2 == 1){
            tmp.push_back(divided[divided.size()-1]);
        }
        divided = tmp;
    }
    left = divided[0].second.first;
    right = divided[0].second.second;
    ans = divided[0].first;
    return;
}

void Solution(){
    if(s.size() != n){ // 같은 좌표를 가진 점이 있다면 종료
        cout<<0<<endl;
        return;
    }
    sort(v.begin(), v.end());
    Divide(); // 점을 최대 3개, 2개 로 분할
    Conqure();
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