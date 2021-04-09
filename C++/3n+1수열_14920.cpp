#include <iostream>
using namespace std;

int c(int x);

int main(){
    int n;
    int cnt=2;
    cin>>n;
    if(n==1){
        cout<<1<<endl;
    }
    else{
        while(c(n)!=1){
            n=c(n);
            cnt++;
        }
        cout<<cnt<<endl;
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
