#include <bits/stdc++.h>
#define endl '\n'
#define MAX 100001
using namespace std;

int T, N;
pair<int,int> p[MAX];

void Solution(){
    cin>>T;
    while(T--){
        cin>>N;
        for(int i=0;i<N;i++){
            cin>>p[i].first>>p[i].second;
        }
        sort(p, p+N);
        int ans = 1;
        int temp = p[0].second;
        for(int i=1;i<N;i++){
            if(p[i].second < temp){
                ans++;
                temp = p[i].second;
                if(temp == 1) break;
            }
        }
        cout<<ans<<endl;
    }
}

void Solve(){
    Solution();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solve();

    return 0;
}
