#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int N;
int arr[3];
int preA[3], preB[3];
int curA[3], curB[3];

void Solution(){
    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=0;j<3;j++){
            if(i == 1){
                cin>>arr[j];
                preA[j] = arr[j];
                preB[j] = arr[j];
            }
            else{
                cin>>arr[j];
            }
        }
        if(i >= 2){
            curA[0] = max(preA[0], preA[1]) + arr[0];
            curA[1] = max(max(preA[0], preA[1]), preA[2]) + arr[1];
            curA[2] = max(preA[1], preA[2]) + arr[2];
            
            curB[0] = min(preB[0], preB[1]) + arr[0];
            curB[1] = min(min(preB[0], preB[1]), preB[2]) + arr[1];
            curB[2] = min(preB[1], preB[2]) + arr[2];
            
            for(int j=0;j<3;j++){
                preA[j] = curA[j];
                preB[j] = curB[j];
            }
        }
    }
    cout<<max(max(preA[0],preA[1]),preA[2])<<' '<<min(min(preB[0],preB[1]),preB[2])<<endl;
}

void Solve(){
    Solution();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solve();

    return 0;
}
