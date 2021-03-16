#include <bits/stdc++.h>
#define MAX 51
#define endl '\n'
#define ll long long
using namespace std;

int N, ans;
ll Building[MAX];

void Input(){
    cin>>N;
    for(int i=1;i<=N;i++) cin>>Building[i];
}

ll CCW(ll a, ll b, ll c){ // 시계방향 음수, 반시계방향 양수, 평행일때 0
    return (a * Building[b] + b * Building[c] + c * Building[a]) - (a * Building[c] + c * Building[b] + b * Building[a]);
}

void Solution(){
    for(int i=1;i<=N;i++){
        int cnt = 0;
        for(int left=i-1;left>=1;left--){
            bool flag = true;
            for(int middle=left+1;middle<=i-1;middle++){
                if(CCW(left, middle, i) <= 0){
                    flag = false;
                    break;
                }
            }
            if(flag) {
                cnt++;
            } 
        }
        for(int right=i+1;right<=N;right++){
            bool flag = true;
            for(int middle=i+1;middle<=right-1;middle++){
                if(CCW(right, middle, i) >= 0){
                    flag = false;
                    break;
                }
            }
            if(flag) {
                cnt++;
            }
        }
        ans = max(ans, cnt);
    }
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