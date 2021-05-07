#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int arr[1000];
int lis[1000];

int binary_search(int left, int right, int target){
    int mid;
    while(left < right){
        mid = (left + right) / 2;
        if(lis[mid] < target) left = mid + 1;
        else right = mid;
    }
    return right;
}

int main()
{
    FAST;
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    int j = 0;
    lis[0] = arr[0];
    int i = 1;
    while(i < n){
        if(lis[j] < arr[i]){
            lis[j + 1] = arr[i];
            j++;
        }
        else{
            int index = binary_search(0, j, arr[i]);
            lis[index] = arr[i];
        }
        i++;
    }
    cout<<j+1<<'\n';
}
