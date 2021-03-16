#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main(){
    FAST;
    int alphabets[26] = {0,};
    string str;
    cin>>str;
    for(int i=0;i<str.length();i++){
        alphabets[(int)str[i] - 97]++;
    }
    for(int i=0;i<26;i++){
        cout<<alphabets[i]<<" ";
    }
}
