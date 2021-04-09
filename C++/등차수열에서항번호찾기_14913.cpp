#include <iostream>
using namespace std;

int main(){
    int a, d, k;
    int n;
    cin>>a>>d>>k;
    n = (k-a)/d + 1;
    if(n>0 && (k-a)%d==0){
        cout<<n<<endl;
    }
    else{
        cout<<"X"<<endl;
    }
}
