#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int n;
string a, b, c;
bool flag;
int aLen, bLen, cLen;

bool test() {
    vector<int>alp(27, 0);
    for (int i = 0; i < aLen; i++)
        alp[a[i] - 'a']++;
    for (int i = 0; i < bLen; i++)
        alp[b[i] - 'a']++;
    for (int i = 0; i < cLen; i++)
        alp[c[i] - 'a']--;
    bool flag = false;
    for (int i = 0; i < 26; i++) {
        if (alp[i] != 0)
            flag = true;
    }
    if (flag)
        return false;
    else
        return true;
}

void sol(int n, int index_a, int index_b){
    if(flag) return;
    if(n == cLen){
        flag = true;
        return;
    }
    if(c[n] == a[index_a]){
        sol(n+1, index_a + 1, index_b);
    }
    if(c[n] == b[index_b]){
        sol(n+1, index_a, index_b + 1);
    }
}

void input(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b>>c;
        aLen = a.length();
        bLen = b.length();
        cLen = c.length();
        cout<<"Data set "<<i<<": ";
        if(test()){
            sol(0, 0, 0);
            if(flag) cout<<"yes"<<'\n';
            else cout<<"no"<<'\n';
        }
        else{
            cout<<"no"<<'\n';
        }
        flag = false;
    }
}

int main(){
    FAST;
    input();
}
