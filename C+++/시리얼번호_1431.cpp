#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int N;
vector<string> serial;

void Input(){
    cin>>N;
    while(N--){
        string number;
        cin>>number;
        serial.push_back(number);
    }
}

bool compare(const string& a, const string& b){
    if(a.size() != b.size()){
        return a.size() < b.size();
    }
    else{
        int A = 0, B = 0;
        for(int i=0;i<a.length();i++){
            if(a[i] >= '0' && a[i] <= '9') A += a[i] - '0';
        }
        for(int i=0;i<b.length();i++){
            if(b[i] >= '0' && b[i] <= '9') B += b[i] - '0';
        }
        if(A != B){
            return A < B;
        }
        else {
            return a < b;
        }
    }
}

void Solution(){
    sort(serial.begin(), serial.end(), compare);
    for(auto cur: serial){
        cout<<cur<<endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Input();
    Solution();
}
