#include <iostream>
#include <algorithm>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int search(int* arr, int length, int target){
    int start = 0;
    int end = length - 1;
    int mid = 0;
    while(start<=end){
        mid = (start + end) / 2;
        if(arr[mid] == target) return mid;
        else if(arr[mid] > target){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return -1;
}

int main(){
    FAST;
    int n, m;
    cin>>n;
    int* numbers = new int[n];
    for(int i=0;i<n;i++){
        cin>>numbers[i];
    }
    sort(numbers, numbers+n);
    cin>>m;
    int* compare = new int[m];
    for(int i=0;i<m;i++){
        cin>>compare[i];
        if(search(numbers, n, compare[i]) == -1) cout<<"0\n";
        else cout<<"1\n";
    }
}
