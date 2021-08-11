#include <iostream>
using namespace std;
#define ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main(){
    int n, max=0, cnt=0;
    cin>>n;
    int* vote = new int[n];
    int* voted = new int[n+1];
    for(int i=0;i<n+1;i++){
        voted[i] = 0;
    }
    for(int i=0;i<n;i++){
        cin>>vote[i];
    }
    for(int i=0;i<n;i++){
        voted[vote[i]] = voted[vote[i]] + 1;
    }
    for(int i=1;i<n+1;i++){
        if(voted[i]>max){
            max = voted[i];
        }
    }
    for(int i=1;i<n+1;i++){
        if(voted[i]==max){
            cnt++;
        }
    }
    if(cnt==1){
        for(int i=1;i<n+1;i++){
            if(voted[i]==max){
                cout<<i<<"\n";
            }
        }
    }
    else{
        cout<<"skipped"<<"\n";
    }
    
}
