#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAX 2000002

int N;
int arr[MAX];

void Input(){
    cin>>N;
    while(N--){
        int num; cin>>num;
        arr[num+1000000]++;
    }
}

void Output(){
    for(int i=0;i<MAX;i++){
        for(int j=0;j<arr[i];j++){
            cout<<i-1000000<<endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     
    Input();
    Output();
}
