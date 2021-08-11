#include <iostream>
#include <algorithm>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int search(int *arr, int point, int length, int target)
{
    int start = point;
    int end = length-1;
    int mid = 0;
    while (start <= end){
        mid = (start+end) / 2;
        if (arr[mid] == target)
            return mid;
        else {
            if (arr[mid] < target)
                start = mid+1;
            else if (arr[mid] > target)
                end = mid-1;
        }
    }
    return -1;
}

int main(){
    FAST;
    int n, x;
    cin>>n;
    int* numbers = new int[n];
    int* check = new int[n];
    for(int i=0;i<n;i++){
        cin>>numbers[i];
        check[i] = 0;
    }
    cin>>x;
    sort(numbers, numbers+n);
    int cnt = 0;
    for(int i=0;i<n-1;i++){
        if(check[i] == 0){
            int sub = x - numbers[i];
            int index = search(numbers, i+1, n, sub);
            if(index != -1){
                    cnt++;
                    check[index] = 1;
            }
            
        }
    }
    cout<<cnt<<"\n";
}
