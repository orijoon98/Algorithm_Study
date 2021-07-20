#include <bits/stdc++.h>
#define endl '\n'
#define MAX 1001
#define ll long long
using namespace std;

ll T, sumA, sumB, ans;
ll A[MAX], sumAA[MAX], B[MAX], sumBB[MAX];
vector<ll> subA, subB;
int n, m;

void Input(){
    cin>>T;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>A[i];
        sumA += A[i];
        sumAA[i] = sumAA[i-1] + A[i];
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>B[i];
        sumB += B[i];
        sumBB[i] = sumBB[i-1] + B[i];
    }
}

bool binarySearch(ll target){
    int left = 0;
    int right = (int)subB.size() - 1;
    int mid = (left + right) / 2;
    while(left <= right){
        if(subB[mid] > target) right = mid - 1;
        else if(subB[mid] < target) left = mid + 1;
        else return true;
        mid = (left + right) / 2;
    }
    return false;
}

void Solution(){
    //A의 부배열
    for(int i=0;i<n;i++){
        ll cur = sumA - sumAA[i];
        subA.push_back(cur);
        for(int j=n;j>=i+2;j--){
            cur -= A[j];
            subA.push_back(cur);
        }
    }
    //B의 부배열
    for(int i=0;i<m;i++){
        ll cur = sumB - sumBB[i];
        subB.push_back(cur);
        for(int j=m;j>=i+2;j--){
            cur -= B[j];
            subB.push_back(cur);
        }
    }
    sort(subB.begin(), subB.end());
    for(auto cur: subA){
        if(binarySearch(T - cur)){
            ans += upper_bound(subB.begin(), subB.end(), T-cur) - lower_bound(subB.begin(), subB.end(), T-cur);
        }
    }
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
}
