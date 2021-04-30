#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main(){
    FAST;
    int n, m;
    cin>>n>>m;
    int num[10000];
    fill(num, num+10000, 0);
    for(int i=0;i<n;i++) cin>>num[i];
    int left = -1, right = -1;
    int sum = 0, cnt = 0;
    while(left < n){
        if(sum < m) sum += num[++right];
        else if(sum == m){
            cnt++;
            sum -= num[++left];
        }
        else sum -= num[++left];
    }
    cout<<cnt<<'\n';
}
