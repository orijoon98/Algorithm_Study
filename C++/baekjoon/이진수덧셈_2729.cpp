#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main(){
    FAST;
    int T;
    cin>>T;
    string num1, num2;
    stack<char> s1, s2;
    deque<int> dq;
    while(T--){
        cin>>num1>>num2;
        for(int i=0;i<num1.length();i++) s1.push(num1[i]);
        for(int i=0;i<num2.length();i++) s2.push(num2[i]);
        int a = 0, b = 0, c = 0, d = 0;
        while(!s1.empty() || !s2.empty() || c != 0){
            if(s1.empty()) a = 0;
            else{
                a = s1.top() - 48;
                s1.pop();
            }
            if(s2.empty()) b = 0;
            else{
                b = s2.top() - 48;
                s2.pop();
            }
            c += a + b;
            if(c < 2){
                d = c;
                dq.push_front(d);
                c = 0;
            }
            else{
                d = c-2;
                dq.push_front(d);
                c = 1;
            }
        }
        for(auto i = dq.begin();i != dq.end();i++){
            if(*i == 1) break;
            else dq.pop_front();
        }
        if(dq.empty()) dq.push_front(0);
        for(auto i = dq.begin();i != dq.end();i++) cout<<*i;
        cout<<'\n';
        dq.clear();
    }
}
