#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

vector<int> fr[51]; //각각의 친구 목록
vector<int> nfr[51]; //각각의 친구 아닌 사람 목록
set<int> twofr[51]; // 각각의 2친구 목록

int main() {
    FAST;
    int n;
    cin>>n;
    string str;
    for(int i=1;i<=n;i++){
        cin>>str;
        for(int j=0;j<n;j++){
            if(str[j] == 'Y'){
                fr[i].push_back(j+1); // i의 친구목록에 j+1 추가
            }
            else{
                nfr[i].push_back(j+1); // i의 친구 아닌 사람 목록에 j+1 추가
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(auto cur: fr[i]){
            twofr[i].insert(cur); // i와 친구인 사람 2-친구 목록에 추가
        }
        for(auto cur: nfr[i]){ // i와 친구가 아닌 사람 목록
            for(auto cur2: fr[cur]){//cur 의 친구 목록에 i와도 친구인 사람이 있으면 cur은 i의 2-친구
                auto it = find(fr[cur2].begin(), fr[cur2].end(), i);
                if(it != fr[cur2].end()) {
                    if(cur != i) twofr[i].insert(cur); // 자기 자신이 아니라면 2-친구 목록에 추가
                }
            }
        }
    }
    int mx = 0;
    for(int i=1;i<=n;i++){
        mx = (mx < (int)twofr[i].size()) ? (int)twofr[i].size() : mx;
    }
    cout<<mx;
}
