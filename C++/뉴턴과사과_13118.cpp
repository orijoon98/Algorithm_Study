#include <iostream>
using namespace std;

int main(){
    int a,b,c,d;
    int x,y,r;
    cin>>a>>b>>c>>d;
    cin>>x>>y>>r;
    if(x==a){
        cout<<1<<endl;
    }
    else if(x==b){
        cout<<2<<endl;
    }
    else if(x==c){
        cout<<3<<endl;
    }
    else if(x==d){
        cout<<4<<endl;
    }
    else{
        cout<<0<<endl;
    }
}
