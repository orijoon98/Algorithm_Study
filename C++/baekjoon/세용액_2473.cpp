#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define INF LLONG_MAX

int N;
ll arr[5000];

void Input(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    sort(arr, arr+N);
}

void Solution(){
    ll x, a, b, c, sum;
    sum = INF;
    for(int i=0;i<N-2;i++){
        x = arr[i];
        int left = i + 1;
        int right = N - 1;
        while(left < right){
            ll temp = x + arr[left] + arr[right];
            if(sum > abs(temp)){
                sum = abs(temp);
                a = x;
                b = arr[left];
                c = arr[right];
            }
            if(temp < 0) left++;
            else if(temp > 0) right--;
            else { i = N; break; }
        }
    }
    cout<<a<<' '<<b<<' '<<c<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Input();
    Solution();
}
