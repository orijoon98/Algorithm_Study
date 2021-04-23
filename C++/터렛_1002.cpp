#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main(){
    FAST;
    int n;
    int x1, y1, r1, x2, y2, r2;
    double d = 0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x1>>y1>>r1>>x2>>y2>>r2;
        if(x1 == x2 && y1 == y2 && r1 == r2) cout<<-1<<"\n";
        else{
            d = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
            if(d > r1 + r2 || d < abs(r1 - r2)) cout<<0<<"\n";
            else if(d == abs(r1 - r2) || d == r1 + r2) cout<<1<<"\n";
            else if(abs(r1 - r2) < d && d < r1 + r2)cout<<2<<"\n";
        }
    }
}
