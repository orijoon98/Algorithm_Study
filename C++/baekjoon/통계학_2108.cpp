#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main(){
    FAST;
    int n;
    cin>>n;
    double* numbers = new double[n];
    int* cnt = new int[n];
    double sum = 0;
    for(int i=0;i<n;i++){
        cin>>numbers[i];
        sum += numbers[i];
        cnt[i] = 1;
    }
    sort(numbers, numbers+n);
    double A;
    int B, C, D;
    A = sum / n;
    B = n/2;
    B = numbers[B];
    D = numbers[n-1] - numbers[0];
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
            C = numbers[i];
        }
    }
    for(int i=0;i<n;i++){
        if(cnt[i] == max){
            if(index == 1){
                C = numbers[i];
                break;
            }
            index++;
        }
    }
    cout<<floor(A+0.5)<<"\n"<<B<<"\n"<<C<<"\n"<<D<<"\n";
}
