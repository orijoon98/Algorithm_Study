#include <iostream>
using namespace std;

int main(){
    int L;
    int t, a;
    cin>>L;
    t = L/5;
    a = L%5;
    if(a==0){
        cout<<t<<endl;
    }
    else{
        cout<<t+1<<endl;
    }
}
