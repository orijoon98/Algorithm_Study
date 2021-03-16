#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

bool isGood(string str){
    deque<char> dq;
    for(int i=0;i<str.length();i++){
        dq.push_back(str[i]);
        if(dq.size()>=2){
            if(dq[dq.size() - 1] == dq[dq.size() - 2]){
                dq.pop_back();
                dq.pop_back();
            }
        }
        if(i == str.length()-1){
            if(dq.empty()) return true;
            else return false;
        }
    }
    return false;
}

int main(){
    FAST;
    int n, cnt = 0;
    string str;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>str;
        if(isGood(str)) cnt++;
    }
    cout<<cnt<<"\n";
}
