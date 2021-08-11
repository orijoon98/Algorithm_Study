#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAX 1000001

int N, big;
int A[MAX];
stack<int> s, bigStack;
deque<int> dq;

void Input(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
}

void Solution(){
    for(int i=N-1;i>=0;i--){
        int before = 0;
        if(!s.empty()) before = s.top();
        s.push(A[i]);
        if(s.size() == 1) {
            dq.push_front(-1);
            big = s.top();
            bigStack.push(big);
            continue;
        }
        if(A[i] >= big){
            while(!bigStack.empty()){
                if(bigStack.top() <= A[i]) bigStack.pop();
                else {
                    dq.push_front(bigStack.top());
                    big = A[i];
                    bigStack.push(big);
                    break;
                }
            }
            if(bigStack.empty()){
                dq.push_front(-1);
                big = A[i];
                bigStack.push(big);
            }
        }
        else if(A[i] < big){
            if(before > A[i] && before < big){
                big = before;
                bigStack.push(big);
                dq.push_front(big);
            }
            else dq.push_front(big);
        }
    }
    for(auto cur: dq){
        cout<<cur<<' ';
    }
    cout<<endl;
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
}
