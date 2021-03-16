#include <bits/stdc++.h>
#define MAX INT_MAX
#define endl '\n'
using namespace std;

int Point[3][2];

void Input(){
    for(int i=0;i<3;i++){
        for(int j=0;j<2;j++){
            cin>>Point[i][j];
        }
    }
}

void Solution(){
    int x1 = Point[0][0];
    int y1 = Point[0][1];
    int x2 = Point[1][0];
    int y2 = Point[1][1];
    int x3 = Point[2][0];
    int y3 = Point[2][1];
    int ccw = (x1 * y2 + x2 * y3 + x3 * y1) - (x1 * y3 + x2 * y1 + x3 * y2);
    if(ccw > 0) cout<<1<<endl;
    else if(ccw < 0) cout<<-1<<endl;
    else cout<<0<<endl;
}

void Solve(){
    Input();
    Solution();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solve();

    return 0;
}