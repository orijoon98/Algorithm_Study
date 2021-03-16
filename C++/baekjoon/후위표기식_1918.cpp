#include <bits/stdc++.h>
#define endl '\n'
#define MAX 1001
using namespace std;

string s;
stack<char> op;

void Input() {
    cin >> s;
}

void Solution() {
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            cout << s[i];
        }
        else
        {
            if (s[i] == '(')
                op.push(s[i]);
            else if (s[i] == '*' || s[i] == '/')
            {
                while (!op.empty() && (op.top() == '*' || op.top() == '/'))
                {
                    cout << op.top();
                    op.pop();
                }
                op.push(s[i]);
            }
            else if (s[i] == '+' || s[i] == '-')
            {
                while (!op.empty() && op.top() != '(')
                {
                    cout << op.top();
                    op.pop();
                }
                op.push(s[i]);
            }
            else if (s[i] == ')')
            {
                while (!op.empty() && op.top() != '(')
                {
                    cout << op.top();
                    op.pop();
                }
                op.pop();
            }
        }
    }
    while (!op.empty())
    {
        cout << op.top();
        op.pop();
    }
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solve();
}