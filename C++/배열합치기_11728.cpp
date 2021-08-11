#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAX 1000000

int N, M;
int A[MAX], B[MAX], ans[MAX*2];

void Input(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    for(int i=0;i<M;i++){
        cin>>B[i];
    }
}

void Sort(){
    int i = 0, j = 0, k = 0;
    while(true){
        if(i < N && j < M){
            if(A[i] < B[j]) ans[k++] = A[i++];
            else ans[k++] = B[j++];
        }
        else {
            if(i == N) ans[k++] = B[j++];
            else ans[k++] = A[i++];
        }
        if(k == N + M) break;
    }
    for(int x=0;x<N+M;x++){
        cout<<ans[x]<<' ';
    }
    cout<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Input();
    Sort();
}
