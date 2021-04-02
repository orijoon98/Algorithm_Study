#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

bool isPalindrome(string n){
    string m = "";
    for(int i=n.length()-1;i>=0;i--){
        m += n[i];
    }
    if(n==m) return true;
    else return false;
}

int main(){
    while(true){
        string n;
        cin>>n;
        if(n=="0") break;
        if(isPalindrome(n)) cout<<"yes"<<"\n";
        else cout<<"no"<<"\n";
    }
}
