#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int arr[1000];
int lis[1000];

int main()
{
    FAST;
    int n, max = 0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        lis[i] = arr[i];
        for(int j=0;j<i;j++){
            if(arr[j] < arr[i] && lis[i] < lis[j] + arr[i]){
                lis[i] = lis[j] + arr[i];
            }
        }
        if(max < lis[i]) max = lis[i];
    }
    cout<<max<<'\n';
}
