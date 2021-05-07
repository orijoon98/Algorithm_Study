#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int main()
{
    FAST;
    stack<char> S;
    string c;
    int test = 1;
    while(true){
        int cnt = 0;
        cin>>c;
        if(c[0] == '-') break;
        for(int i=0;i<c.length();i++){
            char ch = c[i];
            if(ch == '{') S.push(ch);
            else if(ch == '}'){
                if(S.empty() || S.top() != '{') S.push(ch);
                else S.pop();
            }
        }
        while(!S.empty()){
            char ch = S.top();
            S.pop();
            if(S.top() != ch) cnt += 2;
            else cnt++;
            S.pop();
        }
        cout<<test++<<". "<<cnt<<'\n';
    }
}

