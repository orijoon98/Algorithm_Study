#include <iostream>
using namespace std;

int main(){
    int L,R,A;
    int max;
    cin>>L>>R>>A;
    while(A!=0){
        if(L>R){
            R++;
            A--;
        }
        else if(R>L){
            L++;
            A--;
        }
        else{
            L+=A/2;
            R+=A/2;
            A=0;
        }
    }
    if(L!=R){
        if(L>R){
            cout<<2*R<<endl;
        }
        else{
            cout<<2*L<<endl;
        }
    }
    else{
        cout<<L+R<<endl;
    }
}
