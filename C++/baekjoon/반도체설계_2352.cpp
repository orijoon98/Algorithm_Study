#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int line[40001];
int dp[40001];
int lis[40001];

int lowerBound(int* arr, int target, int size){
    int left = 1;
    int right = size;
    int mid;
    while(left < right){
        mid = (left + right) / 2;
        if(arr[mid] >= target) {
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    return right;
}

int main() {
    FAST;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>line[i];
    }
    lis[1] = line[1];
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        if(line[i] > lis[dp[i-1]]){
            lis[dp[i-1] + 1] = line[i];
            dp[i] = dp[i-1] + 1;
//            cout<<"first"<<' ';
//            for(int j=1;j<=dp[i];j++) cout<<lis[j]<<' ';
//            cout<<'\n';
        }
        else{
            int index = lowerBound(lis, line[i], dp[i-1]);
            lis[index] = line[i];
//            cout<<"second"<<' ';
//            for(int j=1;j<=dp[i-1];j++) cout<<lis[j]<<' ';
//            cout<<'\n';
            dp[i] = dp[i-1];
        }
    }
//    for(int i=1;i<=n;i++){
//        cout<<dp[i];
//    }
    cout<<dp[n];
}
