#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int c(int x);

int main(){
    FAST;
    int test;
    cin>>test;
    for(int i=0;i<test;i++){
        int j;
        cin>>j;
        int biggest=j;
        while(c(j)!=1 && j!=1){
            int ch = c(j);
            if(biggest<ch){
                biggest = ch;
            }
            j = ch;
        }
        cout<<biggest<<"\n";
    }
}

int c(int x){
    int result;
    if(x%2==0){
        result=x/2;
    }
    else{
        result=3*x+1;
    }
    return result;
}

