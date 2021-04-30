#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int main(){
    FAST;
    long long K, N, answer = 0;
    cin>>K>>N;
    long long* K_len = new long long[K];
    for(int i=0;i<K;i++) cin>>K_len[i];
    sort(K_len, K_len + K);
    long long left = 1, right = K_len[K-1], mid;
    while(left <= right){
        long long cnt = 0;
        mid = (left + right) / 2;
        for(int i=0;i<K;i++){
            cnt += K_len[i] / mid;
        }
        if(cnt < N){
            right = mid - 1;
        }
        else{
            if(answer < mid) answer = mid;
            left = mid + 1;
        }
    }
    cout<<answer<<'\n';
}

