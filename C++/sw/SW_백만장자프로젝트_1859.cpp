#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAX 1000000
#define ll long long

int arr[MAX];
int copyArr[MAX];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin>>T;
    for(int i=1;i<=T;i++){
        int n;
        cin>>n;
        memset(arr, 0, sizeof(arr));
        for(int j=0;j<n;j++){
            cin>>arr[j];
        }
        ll ans = 0;
        int cmp = arr[n-1];
        for(int k=n-1;k>=1;k--){
            cmp = max(cmp, arr[k]);
            if(cmp > arr[k-1]) ans += cmp - arr[k-1];
        }
        cout<<"#"<<i<<' '<<ans<<endl;
    }
}
