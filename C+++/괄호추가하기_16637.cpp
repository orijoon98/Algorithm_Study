#include <bits/stdc++.h>
#define endl '\n'
#define MAX 100
using namespace std;

int n, ans;
string str;

void Input(){
    cin>>n;
    cin>>str;
}

int cal(int a, int b, char oper)
{
    int result = a;
    switch (oper)
    {
    case '+': result += b; break;
    case '*': result *= b; break;
    case '-': result -= b; break;
    }
    return result;
}

void recur(int idx, int cur)
{
    // 1. 종료 조건
    if (idx > n - 1)
    {
        ans = max(ans, cur);
        return;
    }
    char oper = (idx == 0) ? '+' : str[idx - 1];

    // 2. 괄호로 묶는다 = 이전 + 괄호 계산
    if (idx + 2 < n)
    {
        int bracket = cal(str[idx] - '0', str[idx + 2] - '0', str[idx + 1]);
        recur(idx + 4, cal(cur, bracket, oper));
    }
    // 3. 안 묶는다 = 이전 + 다음
    recur(idx + 2, cal(cur, str[idx] - '0', oper));
}


void Solution(){
    ans = INT_MIN;
    recur(0, 0);
    cout<<ans<<endl;
}

void Solve(){
    Input();
    Solution();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solve();

    return 0;
}
