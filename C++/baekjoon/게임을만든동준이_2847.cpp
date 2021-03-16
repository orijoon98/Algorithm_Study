#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main(){
    FAST;
    int n;
    cin>>n;
    int* score = new int[n];
    for(int i=0;i<n;i++){
        cin>>score[i];
    }
    int cmp = score[n-1], cnt = 0;
    if(n == 1) cout<<0;
    else{
        for(int i=n-2;i>=0;i--){
            if(score[i] >= cmp) {
                cnt += score[i] - cmp + 1;
                cmp--;
            }
            else cmp = score[i];
        }
    }
    cout<<cnt;
}
