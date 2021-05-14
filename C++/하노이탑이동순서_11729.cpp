#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

void func(int a, int b, int n){
    if(n == 1){
        cout<<a<<' '<<b<<'\n';
        return;
    }
    func(a, 6-a-b, n-1);
    cout<<a<<' '<<b<<'\n';
    func(6-a-b, b, n-1);
}

int main() {
    FAST;
    int k;
    cin>>k;
    cout<<(1<<k) - 1<<'\n';
    func(1, 3, k);
}
