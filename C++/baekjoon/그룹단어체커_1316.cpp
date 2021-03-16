#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

bool isGroup(string str){
    for(int i=0;i<str.length()-1;i++){
            if(str[i] != str[i+1]){
                for(int j=i+1;j<str.length();j++){
                    if(str[j] == str[i]) return false;
                }
            }
    }
    return true;
}
    

int main(){
    int n;
    int cnt = 0;
    cin>>n;
    for(int i=0;i<n;i++){
        string a;
        cin>>a;
        if(isGroup(a)){
            cnt++;
        }
    }
    cout<<cnt<<"\n";
}
