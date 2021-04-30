#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main(){
    FAST;
    string str, command;
    list<char> edit;
    cin>>str;
    for(auto i : str) edit.push_back(i);
    auto t = edit.end();
    int n;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin, command);
        switch (command[0]) {
            case 'L':
                if(t != edit.begin()) t--;
                break;
            case 'D':
                if(t != edit.end()) t++;
                break;
            case 'B':
                if(t != edit.begin()) t = edit.erase(--t); // 에러 난 곳
                break;
            case 'P':
                edit.insert(t, command[2]);
                break;
            default:
                cout<<"error"<<"\n";
                break;
        }
    }
    for(auto i : edit) cout<<i;

}
