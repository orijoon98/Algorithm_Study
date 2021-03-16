#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAX 50001

int T, n, t;
int bit[MAX];
int ans[MAX];

void Solution(){
    cin>>T;
    for(int c=1;c<=T;c++){
        cin>>n>>t;
        string str;
        cin>>str;
        for(int i=0;i<str.size();i++){
            bit[i+1] = str[i] - 48;
        }
        fill(ans, ans+MAX, -1);
        for(int i=1;i<=n;i++){
            if(bit[i] == 0) { // bit[i] == 0
                if(i-t >= 1)
                    ans[i-t] = 0;
                if(i+t <= n)
                    ans[i+t] = 0;
            }
        }
        for(int i=1;i<=n;i++){
            if(bit[i] == 1){
                if(i <= t){
                    ans[i+t] = 1;
                }
                else if(i > n-t){
                    ans[i-t] = 1;
                } else{
                    if(i-t >= 1 && i+t <= n){
                        if(ans[i+t] == 0) ans[i-t] = 1;
                        else if(ans[i-t] == 0) ans[i+t] = 1;
                        else if(ans[i-t] == 1) continue;
                        else if(ans[i+t] != 0 && ans[i-t] != 1) ans[i+t] = 1;
                    }
                }
            }
        }
        cout<<"Case #"<<c<<endl;
        for(int i=1;i<=n;i++){
            if(ans[i] == -1) cout<<0;
            else cout<<ans[i];
        }
        cout<<endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solution();
}

