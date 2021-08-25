#include <bits/stdc++.h>
#define endl '\n'
#define MAX 4000001
using namespace std;

int N, ans;
bool arr[MAX];
vector<int> prime;
vector<int> csum; // 소수들 연속합

void Setting(){
    arr[1] = true;
    for(int i=2;i<=sqrt(MAX);i++){
        if(arr[i]) continue;
        for(int j=i+i;j<MAX;j+=i) arr[j] = true;
    }
    csum.push_back(0);
    for(int i=2;i<MAX;i++){
        if(!arr[i]){
            prime.push_back(i);
            csum.push_back(csum[csum.size()-1] + i);
        }
    }
}

void Input(){
    cin>>N;
}

void Solution(){
    for(int left=0;left<csum.size()-1;left++){
        if(csum[left+1] - csum[left] > N) break;
        for(int right=left+1;right<csum.size();right++){
            if(csum[right] - csum[left] == N){
                ans++;
                break;
            }
            if(csum[right] - csum[left] > N) break;
        }
    }
    cout<<ans<<endl;
}

void Solve(){
    Setting();
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
