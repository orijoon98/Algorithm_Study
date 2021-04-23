#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main(){
    FAST;
    int ice[1000001] = {};
    int n, k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int a, b;
        cin>>a>>b;
        ice[b] = a; // 같은 인덱스에 얼음양 저장
    }
    k = 2 * k + 1;
    int max = 0, sum = 0;
    for(int i=0;i<=1000000;i++){
        if(i>=k) sum -= ice[i - k];
        sum += ice[i];
        max = sum > max ? sum : max;
    }
    cout<<max<<"\n";
}
