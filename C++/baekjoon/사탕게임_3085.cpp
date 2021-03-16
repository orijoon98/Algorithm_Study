#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int count(string* arr, int size){
    int max = 0;
    int cnt = 1;
    for(int i=0;i<size;i++){
        for(int j=0;j<size-1;j++){
            if(arr[i][j] == arr[i][j+1]) cnt++;
            else{
                if(max < cnt) max = cnt;
                cnt = 1;
            }
            if(j == size - 2){
                if(max < cnt) max = cnt;
                cnt = 1;
            }
        }
    }
    for(int j=0;j<size;j++){
        for(int i=0;i<size-1;i++){
            if(arr[i][j] == arr[i+1][j]) cnt++;
            else{
                if(max < cnt) max = cnt;
                cnt = 1;
            }
            if(i == size - 2){
                if(max < cnt) max = cnt;
                cnt = 1;
            }
        }
    }
    return max;
}

int main(){
    FAST;
    int n;
    cin>>n;
    string* candy = new string[n];
    for(int i=0;i<n;i++){
        cin>>candy[i];
    }
    int max = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            swap(candy[i][j], candy[i][j+1]);
            if(count(candy, n) > max) max = count(candy, n);
            swap(candy[i][j], candy[i][j+1]);
        }
    }
    for(int j=0;j<n;j++){
        for(int i=0;i<n-1;i++){
            swap(candy[i][j], candy[i+1][j]);
            if(count(candy, n) > max) max = count(candy, n);
            swap(candy[i][j], candy[i+1][j]);
        }
    }
    cout<<max<<"\n";
}
