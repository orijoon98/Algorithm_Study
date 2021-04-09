#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main(){
    int a, b;
    cin>>a>>b;
    for(int i=a;i>=1;i--){
        if(a%i == 0 && b%i == 0){
            cout<<i<<"\n";
            break;
        }
    }
    for(int i=1;i<=b;i++){
        if((a*i)%b == 0){
            cout<<a*i<<"\n";
            break;
        }
    }
}
