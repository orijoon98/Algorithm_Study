#include <iostream>
using namespace std;

bool candy(int a,int b,int c);

int main(){
    int n,y,t=2;
    int N;
    int cnt=0;
    int i=1;
    cin>>N;
    while((N-t)>0){
        t=2*i;
        n=N-t;
        y=N-t-n;
        while(n>=y){
            if(candy(n,y,t)){
                cnt++;
            }
            n--;
            y++;
        }
        i++;
    }
    cout<<cnt<<endl;
}

bool candy(int a,int b,int c){
    if((a-b)>=2 && c%2==0 && a>0 && b>0 && c>0){
        return true;
    }
    else{
        return false;
    }
}
