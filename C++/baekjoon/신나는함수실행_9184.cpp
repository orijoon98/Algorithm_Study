#include <iostream>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int dp[101][101][101];

int w(int a, int b, int c){
    if(a <= 0 || b <= 0 || c <= 0) return 1;
    if(a > 20 || b > 20 || c > 20){
        if(dp[70][70][70] != 0) return dp[70][70][70];
        return w(20, 20, 20);
    }
    if(a < b && b < c){
        int w1, w2, w3;
        if(dp[a+50][b+50][c-1+50] != 0) w1 = dp[a+50][b+50][c-1+50];
        else {
            dp[a+50][b+50][c-1+50] = w(a, b, c-1);
            w1 = dp[a+50][b+50][c-1+50];
        }
        if(dp[a+50][b-1+50][c-1+50] != 0) w2 = dp[a+50][b-1+50][c-1+50];
        else {
            dp[a+50][b-1+50][c-1+50] = w(a, b-1, c-1);
            w2 = dp[a+50][b-1+50][c-1+50];
        }
        if(dp[a+50][b-1+50][c+50] != 0) w3 = dp[a+50][b-1+50][c+50];
        else {
            dp[a+50][b-1+50][c+50] = w(a, b-1, c);
            w3 = dp[a+50][b-1+50][c+50];
        }
        return w1 + w2 - w3;
    }
    else {
        int w1, w2, w3, w4;
        if(dp[a-1+50][b+50][c+50] != 0) w1 = dp[a-1+50][b+50][c+50];
        else {
            dp[a-1+50][b+50][c+50] = w(a-1, b, c);
            w1 = dp[a-1+50][b+50][c+50];
        }
        if(dp[a-1+50][b-1+50][c+50] != 0) w2 = dp[a-1+50][b-1+50][c+50];
        else {
            dp[a-1+50][b-1+50][c+50] = w(a-1, b-1, c);
            w2 = dp[a-1+50][b-1+50][c+50];
        }
        if(dp[a-1+50][b+50][c-1+50] != 0) w3 = dp[a-1+50][b+50][c-1+50];
        else {
            dp[a-1+50][b+50][c-1+50] = w(a-1, b, c-1);
            w3 = dp[a-1+50][b+50][c-1+50];
        }
        if(dp[a-1+50][b-1+50][c-1+50] != 0) w4 = dp[a-1+50][b-1+50][c-1+50];
        else {
            dp[a-1+50][b-1+50][c-1+50] = w(a-1, b-1, c-1);
            w4 = dp[a-1+50][b-1+50][c-1+50];
        }
        return w1 + w2 + w3 - w4;
    }
}

int main(){
    FAST;
    int a, b, c;
    while(true){
        cin>>a>>b>>c;
        if(a == -1 && b == -1 && c == -1) break;
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<w(a, b, c)<<'\n';
    }
}

