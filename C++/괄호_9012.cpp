#include <iostream>
#include <stack>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main(){
    int n;
    string ps;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ps;
        stack<int> s;
        while(!s.empty()) s.pop();
        for(int j=0;j<ps.length();j++){
            if(ps[j] == '(') s.push(1);
            else{
                if(s.empty()){
                    cout<<"NO\n";
                    break;
                }
                s.pop();
            }
            if(j == ps.length()-1){
                if(s.empty()) cout<<"YES\n";
                else cout<<"NO\n";
            }
        }
    }
}

