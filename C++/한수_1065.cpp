#include <iostream>
#include <string>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

bool isHansu(string str){
    if(str.length() < 3) return true;
    else{
        for(int i=0;i<str.length() - 2;i++){
            if((int)str[i+1] - (int)str[i] != (int)str[i+2] - (int)str[i+1]) break;
            if(i == str.length() - 3) return true;
        }
        return false;
    }
}

int main(){
    FAST;
    string number;
    int cnt = 0;
    cin>>number;
    for(int i=1;i<=stoi(number);i++){
        if(isHansu(to_string(i))) cnt++;
    }
    cout<<cnt<<"\n";
}
