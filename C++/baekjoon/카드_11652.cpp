#include <iostream>
#include <algorithm>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main(){
    FAST;
    int n;
    cin>>n;
    long long* numbers = new long long[n];
    int* cnt = new int[n];
    for(int i=0;i<n;i++){
        cin>>numbers[i];
        cnt[i] = 1;
    }
    sort(numbers, numbers+n);
    bool flag = false;
    int state = 0;
    for(int i=0;i<n-1;i++){
        if(numbers[i] == numbers[i+1]){
            if(flag){
                state = i;
                flag = false;
            }
            cnt[state]++;
        }
        else{
            flag = true;
        }
    }
    int max = 0;
    int index = 0;
    for(int i=0;i<n;i++){
        if(cnt[i] > max){
            max = cnt[i];
            index = i;
        }
    }
    cout<<numbers[index]<<"\n";
}
