#include <bits/stdc++.h>
using namespace std;
#define endl '\n'


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin>>T;
    for(int j=1;j<=T;j++){
        int ans = 0;
        for(int i=0;i<10;i++){
            int n;
            cin>>n;
            if(n % 2 == 1) ans += n;
        }
        cout<<"#"<<j<<' '<<ans<<endl;
    }
}

