#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main(){
    FAST;
    int n, k;
    cin>>n>>k;
    int temp[1000000];
    fill(temp, temp+1000000, 0);
    for(int i=0;i<n;i++) cin>>temp[i];
    int left = -1, right = -1;
    int sum = 0, max = -10000000; // max 0으로 하면 max가 -값일때 max 가 0임
    while(true){
        if(left + k > right) {
            sum += temp[++right];
            if(right == left + k){
                if(sum > max) max = sum;
                if(right == n - 1) break;
            }
        }
        else sum -= temp[++left];
    }
    cout<<max<<'\n';
}
