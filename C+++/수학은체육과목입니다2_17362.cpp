#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    if(n<=5){
        cout<<n<<endl;
    }
    else{
        n-=5;
        n%=40;
        if(n%8==4){
            cout<<1<<endl;
        }
        else if((n%8==3)||(n%8==5)){
            cout<<2<<endl;
        }
        else if((n%8==2)||(n%8==6)){
            cout<<3<<endl;
        }
        else if((n%8==1)||(n%8==7)){
            cout<<4<<endl;
        }
        else{
            cout<<5<<endl;
        }
    }
}
