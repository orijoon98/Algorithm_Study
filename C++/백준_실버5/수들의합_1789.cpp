#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main(){
    FAST;
    long long n;
    long long cnt = 0;
    cin>>n;
    for(long long i=1;i<100000;i++){
        if((i*i+i)/2 > n){
            cnt = i-1;
            break;
        }
    }
    cout<<cnt<<"\n";
}
