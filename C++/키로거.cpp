#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main(){
    FAST;
    int n;
    string command;
    cin>>n;
    while(n--){
        cin>>command;
        list<char> password;
        auto t = password.end();
        for(int i=0;i<command.length();i++){
            switch (command[i]) {
                case '<':
                    if(t != password.begin()) t--;
                    break;
                case '>':
                    if(t != password.end()) t++;
                    break;
                case '-':
                    if(t != password.begin()) t = password.erase(--t); // 에러 난 곳
                    break;
                default:
                    password.insert(t, command[i]);
                    break;
            }
        }
        for(auto i : password) cout<<i;
        cout<<'\n';
    }
    
    
}
