#include <bits/stdc++.h>
#define endl '\n'
#define MAX 100
using namespace std;

int N, K;
string str;
vector<int> num;
stack<pair<int,int>> s;

void Input(){
    cin>>N>>K;
    cin>>str;
}

void Solution(){
    for(int i=0;i<str.size();i++) num.push_back(str[i] - 48);
    int cnt = 0;
    s.push({num[0],0});
    bool flag = false;
    for(int i=1;i<num.size();i++){
        if(!s.empty() && s.top().first < num[i]){
            while(!s.empty() && s.top().first < num[i]){
                num[s.top().second] = -1;
                s.pop();
                cnt++;
                if(cnt == K){
                    flag = true;
                    break;
                }
            }
            if(flag) break;
            s.push({num[i],i});
        }
        else{
            s.push({num[i],i});
        }
    }
    // 반례: 7 3 7654321 해결을 위한 부분
    if(!flag){
        for(int i=num.size()-1;i>=0;i--){
            if(num[i] != -1){
                num[i] = -1;
                cnt++;
                if(cnt == K) break;
            }
        }
    }
    for(int i=0;i<num.size();i++){
        if(num[i] != -1) cout<<num[i];
    }
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
